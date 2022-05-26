#pragma once

namespace wce
{
	enum class EEventType
	{
		KeyPressed,
		KeyReleased,

		MousePressed,
		MouseScrolled,
		MouseMoved,

		ScreenSwitched,

		ButtonPressed,

		MenuExit,

		ApplicationStarted,
		ApplicationShutdown
	};
}