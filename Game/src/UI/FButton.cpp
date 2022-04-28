#include "../PCH/pch.h"
#include "FButton.h"

#include "../ScreenBuffer/FScreenBuffer.h"

namespace wce
{
// Constructors and Destructor:

	FButton::FButton()
		: Position  (COORD{}),
		  Width     (10),
		  Attribute (ButtonAttributeEnabled),
		  Enabled   (true)
	{
		this->GenerateId();

		this->Enable();
	}

	FButton::~FButton()
	{
	}


// Functions:

	void FButton::Enable()
	{
		TextField.Enable();

		this->SetAttribute(ButtonAttributeEnabled);

		Enabled = true;
	}

	void FButton::Disable()
	{
		TextField.Disable();

		this->SetAttribute(ButtonAttributeDisabled);

		Enabled = false;
	}

	void FButton::Draw(FScreenBuffer& ScreenBuffer)
	{
		TextField.Draw(ScreenBuffer);

		ScreenBuffer.FillWithAttribute(Position, static_cast<DWORD>(Width), Attribute);
	}


// Accessors:

	const WORD& FButton::GetId() const
	{
		return Id;
	}

	const COORD& FButton::GetPosition() const
	{
		return Position;
	}

	const SHORT& FButton::GetWidth() const
	{
		return Width;
	}

	const WORD& FButton::GetAttribute() const
	{
		return Attribute;
	}

	const std::wstring& FButton::GetText() const
	{
		return TextField.GetText();
	}

	const bool& FButton::IsEnabled() const
	{
		return Enabled;
	}


// Modifiers:

	FButton& FButton::SetPosition(COORD Position)
	{
		this->Position = Position;

		TextField.SetPosition(COORD{ static_cast<SHORT>(Position.X + 1), Position.Y });

		return *this;
	}

	FButton& FButton::SetWidth(SHORT Width)
	{
		this->Width = Width;

		return *this;
	}

	FButton& FButton::SetAttribute(WORD Attribute)
	{
		this->Attribute = Attribute;

		return *this;
	}

	FButton& FButton::SetText(const std::wstring& Text)
	{
		TextField.SetText(Text);

		return *this;
	}


// Private Functions:

	void FButton::GenerateId()
	{
		static WORD NewId = 0;

		Id = NewId++;
	}


}