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

		//
	};
}