#pragma once

#include "EEventType.h"
#include "EventData.h"

#pragma warning( push )
#pragma warning( disable : 26495 ) // Uninitialized variables. Unions does not allow default initialization.

namespace wce
{
	class FEvent
	{
	public:

	// Constructors and Destructor:

		FEvent    (EEventType Type, KEY_EVENT_RECORD          KeyData)          : Type(Type), KeyData          (KeyData)          {}
		FEvent    (EEventType Type, MOUSE_EVENT_RECORD        MouseData)        : Type(Type), MouseData        (MouseData)        {}
		FEvent    (EEventType Type, WINDOW_BUFFER_SIZE_RECORD WindowBufferData) : Type(Type), WindowBufferData (WindowBufferData) {}
		FEvent    (EEventType Type, FButtonData               ButtonData)       : Type(Type), ButtonData       (ButtonData)       {}

		~FEvent    () {}

	// Accessors:

		inline const EEventType& GetType    () const { return Type; }

	// Public Variables:

		union
		{
			KEY_EVENT_RECORD          KeyData;
			MOUSE_EVENT_RECORD        MouseData;
			WINDOW_BUFFER_SIZE_RECORD WindowBufferData;
			FButtonData               ButtonData;
		};

	private:

	// Variables:

		EEventType Type;
	};
}

#pragma warning( pop )