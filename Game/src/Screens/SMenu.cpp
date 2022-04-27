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


// Functions:

	void SMenu::Render()
	{
		if (this->IsActive())
		{
			ScreenBuffer.Clear();

			ScreenBuffer.Write(COORD{ 50, 6 }, L"ULTIMATE SUPER GAME");

			ScreenBuffer.Present();
		}
	}

	void SMenu::Update()
	{
	}


// Private Functions:

	void SMenu::Init()
	{
	}


}