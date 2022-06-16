#pragma once

#include "IScreen.h"
#include "../Data/FChoice.h"

namespace wce
{
	class SGame : public IScreen
	{
	public:

	// Constructors and Destructor:

		 SGame    ();
		~SGame    () override;

	// IScreen Interface:

		void Render        () override;
		void Update        () override;
		void Activate      () override;
		void Deactivate    () override;

	private:

	// Private Functions:

		void Init    ();

	// Components:

		std::map<size_t , FTextField> TextFields;
		std::map<EButton, FButton>    Buttons;

	// Variables:

		WORD Chapter;
		std::map<WORD, std::vector<std::wstring>> Dialogs;
		std::map<WORD, std::vector<FChoice>>      Choices;

	// IEventListener Interface:

		void OnEvent    (const FEvent* const Event);

	// Event Callbacks:

		void OnApplicationStart       (const FEvent* const Event);
		void OnApplicationShutdown    (const FEvent* const Event);
		void OnScreenSwitch           (const FEvent* const Event);
		void OnButtonPress            (const FEvent* const Event);
		void OnKeyRelease             (const FEvent* const Event);
	};
}