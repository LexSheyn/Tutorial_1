#pragma once

#include "IScreen.h"

namespace wce
{
	class SMenu : public IScreen
	{
	public:

	// Constructors and Destructor:

		 SMenu    ();
		~SMenu    () override;

	// IScreen Inteface:

		void Render        () override;
		void Update        () override;
		void Activate      () override;
		void Deactivate    () override;

	private:

	// Private Functions:

		void Init    ();

	// Components:

		std::map<EButton, FButton> Buttons;

	// IEventListener Interface:

		void OnEvent    (const FEvent* const Event) override;

	// Event Callbacks:

		void OnScreenSwitch    (const FEvent* const Event);
		void OnButtonPress     (const FEvent* const Event);
	};
}