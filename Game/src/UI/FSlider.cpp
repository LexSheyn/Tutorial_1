#include "../PCH/pch.h"
#include "FSlider.h"

#include "../ScreenBuffer/FScreenBuffer.h"

namespace wce
{
// Constructors and Destructor:

	FSlider::FSlider()
		: Position      (COORD{}),
		  AttributeBack (128),
		  AttributeFill (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY),
		  SizeBack      (10),
		  SizeFill      (0)
	{
	}

	FSlider::~FSlider()
	{
	}


// Functions:

	void FSlider::Draw(FScreenBuffer& ScreenBuffer)
	{
		ScreenBuffer.FillWithAttribute(Position, static_cast<DWORD>(SizeBack), AttributeBack);
		ScreenBuffer.FillWithAttribute(Position, static_cast<DWORD>(SizeFill), AttributeFill);
	}

	void FSlider::Increase(LONG Offset)
	{
		SizeFill += Offset;

		if (SizeFill > SizeBack)
		{
			SizeFill = SizeBack;
		}
	}

	void FSlider::Decrease(LONG Offset)
	{
		SizeFill -= Offset;

		if (SizeFill < 0)
		{
			SizeFill = 0;
		}
	}


// Accessors:

	const COORD& FSlider::GetPosition() const
	{
		return Position;
	}

	const WORD& FSlider::GetAttributeBack() const
	{
		return AttributeBack;
	}

	const WORD& FSlider::GetAttributeFill() const
	{
		return AttributeFill;
	}

	const LONG& FSlider::GetSizeBack() const
	{
		return SizeBack;
	}

	const LONG& FSlider::GetSizeFill() const
	{
		return SizeFill;
	}


// Modifiers:

	FSlider& FSlider::SetPositon(COORD Position)
	{
		this->Position = Position;

		return *this;
	}

	FSlider& FSlider::SetAttributeBack(WORD Attribute)
	{
		AttributeBack = Attribute;

		return *this;
	}

	FSlider& FSlider::SetAttributeFill(WORD Attribute)
	{
		AttributeFill = Attribute;

		return *this;
	}

	FSlider& FSlider::SetSizeBack(LONG Size)
	{
		SizeBack = Size;

		return *this;
	}

	FSlider& FSlider::SetSizeFill(LONG Size)
	{
		SizeFill = Size;

		return *this;
	}

	FSlider& FSlider::SetRange(SHORT Min, SHORT Max)
	{
		ValueMin = Min;
		ValueMax = Max;

		return *this;
	}

	FSlider& FSlider::SetRange(FLOAT Min, FLOAT Max)
	{
		ValueMin = static_cast<SHORT>(Min);
		ValueMax = static_cast<SHORT>(Max);

		return *this;
	}


}