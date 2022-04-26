#pragma once

#include "../ScreenBuffer/FScreenBuffer.h"

namespace wce
{
	class FApplication
	{
	public:

	// Constructors and Destructor:

		 FApplication    ();
		~FApplication    ();

	// Functions:

		void Run       ();
		void Update    ();
		void Render    ();

	private:

	// Private Functions:

		void Init    ();

	// Variables:

		bool ShouldClose;

		// TEST:

		FScreenBuffer ScreenBuffer;
	};
}