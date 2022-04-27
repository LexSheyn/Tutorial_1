#pragma once

#include "EScreen.h"
#include "../ScreenBuffer/FScreenBuffer.h"

namespace wce
{
	class IScreen
	{
	public:

	// Constructors and Destructor:

		         IScreen    (EScreen Name);
		virtual ~IScreen    ();

	// Interface:

		virtual void Render    () = 0;
		virtual void Update    () = 0;

	// Functions:

		void Activate      ();
		void Deactivate    ();

	// Accessors:

		const EScreen& GetName     () const;
		const bool&    IsActive    () const;

	// Components:

		FScreenBuffer ScreenBuffer;

	private:

	// Variables:

		EScreen Name;
		bool    Activated;
	};
}