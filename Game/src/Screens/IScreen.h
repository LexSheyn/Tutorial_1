#pragma once

#include "EScreen.h"
#include "EScreenField.h"
#include "../Input/FKey.h"
#include "../ScreenBuffer/FScreenBuffer.h"
#include "../UI/EButton.h"
#include "../UI/FButton.h"
#include "../UI/FSlider.h"
#include "../Events/FEventSystem.h"

namespace wce
{
	class IScreen : public IEventListener
	{
	public:

	// Constructors and Destructor:

		         IScreen    (EScreen Name);
		virtual ~IScreen    ();

	// Interface:

		virtual void Render        () = 0;
		virtual void Update        () = 0;
		virtual void Activate      ();
		virtual void Deactivate    ();

	// Accessors:

		const EScreen& GetName     () const;
		const bool&    IsActive    () const;

	// Components:

		FScreenBuffer ScreenBuffer;

	private:

	// Variables:

		EScreen Name;
		bool    Activated;

	public:

	// IEventListener Interface:

		virtual void OnEvent    (const FEvent* const Event) override = 0;
	};
}