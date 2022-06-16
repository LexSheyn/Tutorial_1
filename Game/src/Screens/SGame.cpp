#include "../PCH/pch.h"
#include "SGame.h"

namespace wce
{
// Constructors and Destructor:

	SGame::SGame() : IScreen(EScreen::Game)
	{
		this->Init();

		FEventSystem::Subscribe(EEventType::ApplicationStarted , this);
		FEventSystem::Subscribe(EEventType::ApplicationShutdown, this);
		FEventSystem::Subscribe(EEventType::ScreenSwitched     , this);
	}

	SGame::~SGame()
	{
		FEventSystem::UnsubscribeFromAll(this);
	}


// IScreen Intarface:

	void SGame::Render()
	{
		if (this->IsActive() == false) { return; }

		ScreenBuffer.Clear();

	//	for (auto& Dialog : Dialogs[Chapter])
	//	{
	//
	//	}

		for (auto& [Key, Button] : Buttons)
		{
			Button.Draw(ScreenBuffer);
		}

		ScreenBuffer.Present();
	}

	void SGame::Update()
	{
	}

	void SGame::Activate()
	{
		IScreen::Activate();

		FEventSystem::Subscribe(EEventType::ButtonPressed, this);
		FEventSystem::Subscribe(EEventType::KeyReleased  , this);

		for (auto& [Key, Button] : Buttons)
		{
			Button.Enable();
		}
	}

	void SGame::Deactivate()
	{
		IScreen::Deactivate();

		FEventSystem::Unsubscribe(EEventType::ButtonPressed, this);
		FEventSystem::Unsubscribe(EEventType::KeyReleased  , this);

		for (auto& [Key, Button] : Buttons)
		{
			Button.Disable();
		}
	}


// Private Functions:

	void SGame::Init()
	{
		TextFields[0].SetPosition(COORD{ 10, 5 });

		Buttons[EButton::Choice_0].SetPosition(COORD{ 10, 22 }).SetWidth(30);
		Buttons[EButton::Choice_1].SetPosition(COORD{ 10, 24 }).SetWidth(30);
		Buttons[EButton::Choice_2].SetPosition(COORD{ 50, 22 }).SetWidth(30);
		Buttons[EButton::Choice_3].SetPosition(COORD{ 50, 24 }).SetWidth(30);
	}


// IEventListener Interface:

	void SGame::OnEvent(const FEvent* const Event)
	{
		switch (Event->GetType())
		{
			case EEventType::ApplicationStarted:
			{
				this->OnApplicationStart(Event);
			}
			break;

			case EEventType::ApplicationShutdown:
			{
				this->OnApplicationShutdown(Event);
			}
			break;

			case EEventType::ScreenSwitched:
			{
				this->OnScreenSwitch(Event);
			}
			break;

			case EEventType::ButtonPressed:
			{
				this->OnButtonPress(Event);
			}
			break;

			case EEventType::KeyReleased:
			{
				this->OnKeyRelease(Event);
			}
			break;
		}
	}


// Event Callbacks:

	void SGame::OnApplicationStart(const FEvent* const Event)
	{
	}

	void SGame::OnApplicationShutdown(const FEvent* const Event)
	{
	}

	void SGame::OnScreenSwitch(const FEvent* const Event)
	{
		if (Event->ScreenData.ToScreen == this->GetName())
		{
			this->Activate();
		}
		else
		{
			if (this->IsActive())
			{
				this->Deactivate();
			}			
		}
	}

	void SGame::OnButtonPress(const FEvent* const Event)
	{
	}

	void SGame::OnKeyRelease(const FEvent* const Event)
	{
		if (Event->KeyData.wVirtualKeyCode == FKey::Escape)
		{
			FEventSystem::PushEvent(FEvent(EEventType::ScreenSwitched, FScreenData{ this->GetName(), EScreen::Menu }));
		}
	}


}