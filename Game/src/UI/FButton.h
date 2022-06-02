#pragma once

#include "FTextField.h"
#include "../Events/FEventSystem.h"
#include "../Input/FMouseButton.h"

namespace wce
{
	class FButton : public IEventListener
	{
	public:

	// Construcors and Destructor:

		 FButton    ();
		~FButton    ();

	// Functions:

		void Enable     ();
		void Disable    ();
		void Draw       (class FScreenBuffer& ScreenBuffer);

	// Accessors:

		const WORD&         GetId           () const;
		const COORD&        GetPosition     () const;
		const SHORT&        GetWidth        () const;
		const WORD&         GetAttribute    () const;
		const std::wstring& GetText         () const;
		const bool&         IsEnabled       () const;

	// Modifiers:

		FButton& SetPosition     (COORD Position);
		FButton& SetWidth        (SHORT Width);
		FButton& SetAttribute    (WORD Attribute);
		FButton& SetText         (const std::wstring& Text);

	private:

	// Private Functions:

		void GenerateId    ();

	// Components:

		FTextField TextField;

	// Varibles:

		WORD  Id;
		COORD Position;
		SHORT Width;
		WORD  Attribute;
		bool  Enabled;

		COORD MousePositionLast;

		static constexpr WORD ButtonAttributeEnabled  = BACKGROUND_GREEN | BACKGROUND_BLUE;
		static constexpr WORD ButtonAttributeDisabled = 8;
		static constexpr WORD ButtonAttributeHovered  = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;

	// IEventListener Interface:

		void OnEvent    (const FEvent* const Event) override;

	// Event Callbacks:

		void OnMouseMove     (const FEvent* const Event);
		void OnMousePress    (const FEvent* const Event);
	};
}