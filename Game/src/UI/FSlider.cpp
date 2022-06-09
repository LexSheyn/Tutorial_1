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
		  SizeFill      (0),
		  Padding       (1), // Default padding set to 1, otherwise it will equal to value that has presented before in this memory, like -11051 or anything else. // M
		  Enabled       (false)
	{
		ButtonIncrease.SetWidth(3).SetText(L"+"); // Width set to 3. // M
		ButtonDecrease.SetWidth(3).SetText(L"-"); // Width set to 3. // M
	}

	FSlider::~FSlider()
	{
	}


// Functions:

	void FSlider::Enable()
	{
		Enabled = true;

		ButtonIncrease.Enable();
		ButtonDecrease.Enable();

		TextField.Enable();

		FEventSystem::Subscribe(EEventType::ButtonPressed, this);
	}

	void FSlider::Disable()
	{
		Enabled = false;

		ButtonIncrease.Disable();
		ButtonDecrease.Disable();

		TextField.Disable();

		FEventSystem::Unsubscribe(EEventType::ButtonPressed, this);
	}

	void FSlider::Draw(FScreenBuffer& ScreenBuffer)
	{
		ScreenBuffer.FillWithAttribute(Position, static_cast<DWORD>(SizeBack), AttributeBack);
		ScreenBuffer.FillWithAttribute(Position, static_cast<DWORD>(SizeFill), AttributeFill);

		ButtonIncrease.Draw(ScreenBuffer);
		ButtonDecrease.Draw(ScreenBuffer);

		TextField.Draw(ScreenBuffer);
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

	const SHORT& FSlider::GetPadding() const
	{
		return Padding;
	}

	const std::wstring& FSlider::GetText() const
	{
		return TextField.GetText();
	}

	const bool& FSlider::IsEnabled() const
	{
		return Enabled;
	}


// Modifiers:

	FSlider& FSlider::SetPosition(COORD Position)
	{
		this->Position = Position;

		ButtonIncrease.SetPosition(COORD{ static_cast<SHORT>(this->Position.X + SizeBack + Padding), this->Position.Y });
		ButtonDecrease.SetPosition(COORD{ static_cast<SHORT>(ButtonIncrease.GetPosition().X + ButtonIncrease.GetWidth() + Padding), ButtonIncrease.GetPosition().Y });

		TextField.SetPosition(COORD{ static_cast<SHORT>(ButtonDecrease.GetPosition().X + ButtonDecrease.GetWidth() + Padding), ButtonDecrease.GetPosition().Y });

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

	FSlider& FSlider::SetPadding(SHORT Size)
	{
		Padding = Size;

		return *this;
	}

	FSlider& FSlider::SetText(const std::wstring& Text)
	{
		TextField.SetText(Text);

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


// IEventListener Interface:

	void FSlider::OnEvent(const FEvent* const Event)
	{
		switch (Event->GetType())
		{
			case EEventType::ButtonPressed:
			{
				this->OnButtonPress(Event);
			}
			break;
		}
	}


// Event Callbacks:

	void FSlider::OnButtonPress(const FEvent* const Event)
	{
		if (Event->ButtonData.Id == ButtonIncrease.GetId())
		{
			this->Increase();
		}
		else if (Event->ButtonData.Id == ButtonDecrease.GetId())
		{
			this->Decrease();
		}
	}


}