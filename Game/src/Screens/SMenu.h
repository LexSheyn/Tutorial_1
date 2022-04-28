#pragma once

#include "IScreen.h"
#include "../UI/EButton.h"
#include "../UI/FButton.h"

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
	};
}