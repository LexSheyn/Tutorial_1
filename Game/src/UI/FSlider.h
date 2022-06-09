#pragma once

#include "FButton.h"

namespace wce
{
	class FSlider : public IEventListener
	{
	public:

	// Constructors and Destructor:

		 FSlider    ();
		~FSlider    ();

	// Functions:

		void Enable      ();
		void Disable     ();
		void Draw        (class FScreenBuffer& ScreenBuffer);
		void Increase    (LONG Offset = 1);
		void Decrease    (LONG Offset = 1);

	// Accessors:

		const COORD&        GetPosition         () const;
		const WORD&         GetAttributeBack    () const;
		const WORD&         GetAttributeFill    () const;
		const LONG&         GetSizeBack         () const;
		const LONG&         GetSizeFill         () const;
		const SHORT&        GetPadding          () const;
		const std::wstring& GetText             () const;
		const bool&         IsEnabled           () const;

	// Modifiers:

		FSlider& SetPosition         (COORD Position);
		FSlider& SetAttributeBack    (WORD Attribute);
		FSlider& SetAttributeFill    (WORD Attribute);
		FSlider& SetSizeBack         (LONG Size);
		FSlider& SetSizeFill         (LONG Size);
		FSlider& SetPadding          (SHORT Size);
		FSlider& SetText             (const std::wstring& Text);
		FSlider& SetRange            (SHORT Min, SHORT Max);
		FSlider& SetRange            (FLOAT Min, FLOAT Max);

	private:

	// Components:

		FButton    ButtonIncrease;
		FButton    ButtonDecrease;
		FTextField TextField;

	// Variables:

		COORD Position;
		WORD  AttributeBack;
		WORD  AttributeFill;
		LONG  SizeBack;
		LONG  SizeFill;
		SHORT Padding;
		SHORT ValueMin;
		SHORT ValueMax;
		bool  Enabled;

	// IEventListener Intarface:

		void OnEvent    (const FEvent* const Event) override;

	// Event Callbacks:

		void OnButtonPress    (const FEvent* const Event);
	};
}