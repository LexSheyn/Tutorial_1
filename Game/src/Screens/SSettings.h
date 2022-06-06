#pragma once

#include "IScreen.h"

namespace wce
{
	class SSettings : public IScreen
	{
	public:

	// Constructors and Destructor:

		 SSettings    ();
		~SSettings    () override;

	// IScreen Interface:

		void Render        () override;
		void Update        () override;
		void Activate      () override;
		void Deactivate    () override;

	private:

	// Private Functions:

		void Init    ();

	// Components:

		std::map<EScreenField, FTextField> TextFields;
		std::map<EButton     , FButton>    Buttons;
		std::map<EScreenField, FSlider>    Sliders;

	// IEventListener Interface:

		void OnEvent    (const FEvent* const Event) override;

	// Event Callbacks:

		void OnApplicationStart       (const FEvent* const Event);
		void OnApplicationShutdown    (const FEvent* const Event);
		void OnScreenSwitch           (const FEvent* const Event);
		void OnButtonPress            (const FEvent* const Event);
		void OnKeyRelease             (const FEvent* const Event);
	};
}