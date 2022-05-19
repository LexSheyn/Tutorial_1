#pragma once

#include "../Window/FConsole.h"
#include "../Events/FEventCatcher.h"
#include "../Events/FEventSystem.h"
#include "../Screens/SMenu.h"

namespace wce
{
	class FApplication
	{
	public:

	// Constructors and Destructor:

		 FApplication    ();
		~FApplication    ();

	// Functions:

		void Run           ();
		void PollEvents    ();
		void Update        ();
		void Render        ();

	private:

	// Private Functions:

		void Init    ();

	// Variables:

		bool ShouldClose;
		FEventCatcher EventCatcher;

	// Window:

		FConsole Console;

	// Screens:

		SMenu Menu;
	};
}