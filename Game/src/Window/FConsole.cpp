#include "../PCH/pch.h"
#include "FConsole.h"

namespace wce
{
// Constructors and Destructor:

	FConsole::FConsole()
		:
		Console(GetConsoleWindow()),
		Desktop(GetDesktopWindow())
	{
		Style = GetWindowLongW(Console, GWL_STYLE);
		Style &= ~WS_MAXIMIZEBOX;
		Style &= ~WS_SIZEBOX;

		SetWindowLongW(Console, GWL_STYLE, Style);
	}

	FConsole::~FConsole()
	{
	}


// Functions:

	void FConsole::ArrangeToCenter()
	{
		GetWindowRect(Console, &ConsoleRect);
		GetWindowRect(Desktop, &DesktopRect);

		SetWindowPos(Console,
			         nullptr,
			         static_cast<INT>( (static_cast<FLOAT>(DesktopRect.right ) / 2.0f) - (static_cast<FLOAT>(ConsoleRect.right ) / 2.0f) ),
			         static_cast<INT>( (static_cast<FLOAT>(DesktopRect.bottom) / 2.0f) - (static_cast<FLOAT>(ConsoleRect.bottom) / 2.0f) ),
			         0,
			         0,
			         SWP_NOSIZE);
	}


// Modifiers:

	FConsole& FConsole::SetPosition(INT X, INT Y)
	{
		SetWindowPos(Console, nullptr, X, Y, 0, 0, SWP_NOSIZE);

		return *this;
	}

	FConsole& FConsole::SetSize(INT Width, INT Height)
	{
		SetWindowPos(Console, nullptr, 0, 0, Width, Height, SWP_NOMOVE);

		return *this;
	}

	FConsole& FConsole::SetStyle(LONG Style)
	{
		SetWindowLongW(Console, GWL_STYLE, Style);

		return *this;
	}

	FConsole& FConsole::SetTitle(const std::wstring& Title)
	{
		SetConsoleTitleW(Title.c_str());

		return *this;
	}


}