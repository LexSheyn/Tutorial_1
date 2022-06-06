#pragma once

namespace wce
{
	class FSlider
	{
	public:

	// Constructors and Destructor:

		 FSlider    ();
		~FSlider    ();

	// Functions:

		void Draw        (class FScreenBuffer& ScreenBuffer);
		void Increase    (LONG Offset = 1);
		void Decrease    (LONG Offset = 1);

	// Accessors:

		const COORD& GetPosition         () const;
		const WORD&  GetAttributeBack    () const;
		const WORD&  GetAttributeFill    () const;
		const LONG&  GetSizeBack         () const;
		const LONG&  GetSizeFill         () const;

	// Modifiers:

		FSlider& SetPositon          (COORD Position);
		FSlider& SetAttributeBack    (WORD Attribute);
		FSlider& SetAttributeFill    (WORD Attribute);
		FSlider& SetSizeBack         (LONG Size);
		FSlider& SetSizeFill         (LONG Size);
		FSlider& SetRange            (SHORT Min, SHORT Max);
		FSlider& SetRange            (FLOAT Min, FLOAT Max);

	private:

	// Variables:

		COORD Position;
		WORD  AttributeBack;
		WORD  AttributeFill;
		LONG  SizeBack;
		LONG  SizeFill;
		SHORT ValueMin;
		SHORT ValueMax;
	};
}