#pragma once

#include "IScreen.h"

namespace wce
{
	class SMenu : public IScreen
	{
	public:

	// Constructors and Destructor:

		 SMenu    ();
		~SMenu    ();

	// IScreen Inteface:

		void Render    () override;
		void Update    () override;

	private:

	// Private Functions:

		void Init    ();

	// Components:

		std::map<EButton, FButton> Buttons;

	public:

	// IEventListener Interface:

		void OnEvent    (const FEvent* const Event) override;

	private:

	// Event Callbacks:

		void OnScreenSwitch    (const FEvent* const Event);
		void OnButtonPress     (const FEvent* const Event);
	};
}