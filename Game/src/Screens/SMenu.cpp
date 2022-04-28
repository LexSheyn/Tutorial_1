#include "../PCH/pch.h"
#include "SMenu.h"

namespace wce
{
// Constructors and Destructor:

	SMenu::SMenu() : IScreen(EScreen::Menu)
	{
		this->Init();
	}

	SMenu::~SMenu()
	{
	}


// IScreen Inteface:

	void SMenu::Render()
	{
		if (this->IsActive())
		{
			ScreenBuffer.Clear();

			for (auto&[Key, Button] : Buttons)
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


}