#include "../PCH/pch.h"
#include "IScreen.h"

namespace wce
{
// Constructors and Destructor:

	IScreen::IScreen(EScreen Name)
		: Name      (Name),
		  Activated (false)
	{
	}

	IScreen::~IScreen()
	{
	}


// Interface:

	void IScreen::Activate()
	{
		Activated = true;

		ScreenBuffer.Activate();		
	}

	void IScreen::Deactivate()
	{
		Activated = false;
	}


// Accessors:

	const EScreen& IScreen::GetName() const
	{
		return Name;
	}

	const bool& IScreen::IsActive() const
	{
		return Activated;
	}

}