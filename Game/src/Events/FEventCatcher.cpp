#include "../PCH/pch.h"
#include "FEventCatcher.h"

namespace wce
{
// Functions:

	void FEventCatcher::Initialize()
	{
		StdInput = GetStdHandle(STD_INPUT_HANDLE);

		GetConsoleMode(StdInput, &ConsoleModeOld);

		SetConsoleMode(StdInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	}

	void FEventCatcher::CatchEvents()
	{
		ReadConsoleInputW(StdInput, EventData, 128, &NumRecordsRead);

		for (DWORD i = 0u; i < NumRecordsRead; i++)
		{
			switch (EventData[i].EventType)
			{
				case KEY_EVENT:
				{
					KeyEventProc(EventData[i].Event.KeyEvent);
				}
				break;

				case MOUSE_EVENT:
				{
					MouseEventProc(EventData[i].Event.MouseEvent);
				}
				break;

				case WINDOW_BUFFER_SIZE_EVENT:
				{
					ResizeEventProc(EventData[i].Event.WindowBufferSizeEvent);
				}
				break;
			}
		}
	}

	void FEventCatcher::Shutdown()
	{
		SetConsoleMode(StdInput, ConsoleModeOld);
	}


// Event Process Functions:

	void __stdcall FEventCatcher::KeyEventProc(KEY_EVENT_RECORD KeyData)
	{
		if (KeyData.bKeyDown)
		{
			// Key pressed event.
		}
		else if (KeyData.bKeyDown == false)
		{
			// Key released event.
		}
	}

	void __stdcall FEventCatcher::MouseEventProc(MOUSE_EVENT_RECORD MouseData)
	{
		switch (MouseData.dwEventFlags)
		{
			case 0:
			{
				// Mouse pressed event.
			}
			break;

			case MOUSE_WHEELED:
			{
				// Mouse scrolled event.
			}
			break;

			case MOUSE_MOVED:
			{
				// Mouse moved event.
			}
			break;
		}
	}

	void __stdcall FEventCatcher::ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD WindowBufferData)
	{
		// Window resized event.
	}

// Static Variables:

	HANDLE FEventCatcher::StdInput = nullptr;

	DWORD FEventCatcher::ConsoleMode    = 0;
	DWORD FEventCatcher::ConsoleModeOld = 0;

	INPUT_RECORD FEventCatcher::EventData[128];
	DWORD        FEventCatcher::NumRecordsRead = 0;

}