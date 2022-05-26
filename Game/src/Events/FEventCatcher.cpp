#include "../PCH/pch.h"
#include "FEventCatcher.h"

namespace wce
{
// Constructors and Destructor:

	FEventCatcher::FEventCatcher()
	{
		this->Initialize();
	}

	FEventCatcher::~FEventCatcher()
	{
		this->Shutdown();
	}


// Functions:

	void FEventCatcher::CatchEvents()
	{
		ReadConsoleInputW(StdInput, EventData, 128, &NumRecordsRead);

		for (DWORD i = 0; i < NumRecordsRead; i++)
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

				case MENU_EVENT:
				{
					// To do...
				}
				break;

				case FOCUS_EVENT:
				{
					// To do...
				}
				break;

				default:
				{
				}
				break;
			}
		}
	}


// Private Functions:

	void FEventCatcher::Initialize()
	{
		StdInput = GetStdHandle(STD_INPUT_HANDLE);

		GetConsoleMode(StdInput, &ConsoleModeOld);

		SetConsoleMode(StdInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	}

	void FEventCatcher::Shutdown()
	{
		SetConsoleMode(StdInput, ConsoleModeOld);
	}


// Event Process Functions:

	void __stdcall FEventCatcher::KeyEventProc(KEY_EVENT_RECORD KeyData)
	{
		if      (KeyData.bKeyDown)
		{
			//
		}
		else if (!KeyData.bKeyDown)
		{
			//
		}
	}

	void __stdcall FEventCatcher::MouseEventProc(MOUSE_EVENT_RECORD MouseData)
	{
		switch (MouseData.dwEventFlags)
		{
			case 0: // Mouse button press.
			{
				FEventSystem::PushEvent(FEvent(EEventType::MousePressed, MouseData));
			}
			break;

			case MOUSE_WHEELED:
			{
				//
			}
			break;

			case MOUSE_MOVED:
			{
				FEventSystem::PushEvent(FEvent(EEventType::MouseMoved, MouseData));
			}
			break;

			default:
			{
			}
			break;
		}
	}

	void __stdcall FEventCatcher::ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD WindowBufferData)
	{
		//
	}


}