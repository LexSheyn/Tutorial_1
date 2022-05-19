#include "../PCH/pch.h"
#include "SMenu.h"

namespace wce
{
// Constructors and Destructor:

	SMenu::SMenu() : IScreen(EScreen::Menu)
	{
		this->Init();

		FEventSystem::Subscribe(EEventType::ScreenSwitched, this);
	}

	SMenu::~SMenu()
	{
		FEventSystem::UnsubscribeFromAll(this);
	}


// IScreen Inteface:

	void SMenu::Render()
	{
		if (this->IsActive())
		{
			ScreenBuffer.Clear();

			for (auto& [Key, Button] : Buttons)
			{
				Button.Draw(ScreenBuffer);
			}

			ScreenBuffer.Present();
		}
	}

	void SMenu::Update()
	{
	}


// Private Functions:

	void SMenu::Init()
	{
		Buttons[EButton::StartGame].SetPosition(COORD{ 10, 10 }).SetWidth(12).SetText(L"Start game");
		Buttons[EButton::Memory   ].SetPosition(COORD{ 10, 12 }).SetWidth(12).SetText(L"Memory"    );
		Buttons[EButton::Settings ].SetPosition(COORD{ 10, 14 }).SetWidth(12).SetText(L"Settings"  );
		Buttons[EButton::Exit     ].SetPosition(COORD{ 10, 16 }).SetWidth(12).SetText(L"Exit"      );
	}


// IEventListener Interface:

	void SMenu::OnEvent(const FEvent* const Event)
	{
		switch (Event->GetType())
		{
			case EEventType::ScreenSwitched:
			{
				this->OnScreenSwitch(Event);
			}
			break;
		}
	}


// Event Callbacks:

	void SMenu::OnScreenSwitch(const FEvent* const Event)
	{
		if (Event->ScreenData.ToScreen == this->GetName())
		{
			this->Activate();

			for (auto& [Key, Button] : Buttons)
			{
				Button.Enable();
			}
		}
		else
		{
			this->Deactivate();

			for (auto& [Key, Button] : Buttons)
			{
				Button.Disable();
			}
		}
	}


}