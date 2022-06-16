#pragma once

#include "../Window/FConsole.h"
#include "../Events/FEventCatcher.h"
#include "../Events/FEventSystem.h"
#include "../Screens/SMenu.h"
#include "../Screens/SGame.h"
#include "../Screens/SSettings.h"

namespace wce
{
	class FApplication : public IEventListener
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

		SMenu     Menu;
		SGame     Game;
		SSettings Settings;

	// IEventListener Interface:

		void OnEvent    (const FEvent* const Event) override;

	// Event Callbacks:

		void OnApplicationShutdown    (const FEvent* const Event);
		void OnMenuExit               (const FEvent* const Event);
	};
}