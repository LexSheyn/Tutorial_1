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
		  Enabled   (false)
	{
		this->GenerateId();
	}

	FButton::~FButton()
	{
	}


// Functions:

	void FButton::Enable()
	{
		Enabled = true;

		TextField.Enable();

		this->SetAttribute(ButtonAttributeEnabled);		

		FEventSystem::Subscribe(EEventType::MouseMoved  , this);
		FEventSystem::Subscribe(EEventType::MousePressed, this);
	}

	void FButton::Disable()
	{
		Enabled = false;

		TextField.Disable();

		this->SetAttribute(ButtonAttributeDisabled);	

		FEventSystem::Unsubscribe(EEventType::MouseMoved  , this);
		FEventSystem::Unsubscribe(EEventType::MousePressed, this);
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


// IEventListener Interface:

	void FButton::OnEvent(const FEvent* const Event)
	{
		switch (Event->GetType())
		{
			case EEventType::MouseMoved:
			{
				this->OnMouseMove(Event);
			}
			break;

			case EEventType::MousePressed:
			{
				this->OnMousePress(Event);
			}
			break;
		}
	}


// Event Callbacks:

	void FButton::OnMouseMove(const FEvent* const Event)
	{
		MousePositionLast = Event->MouseData.dwMousePosition;

		if ( (MousePositionLast.X >= Position.X) && (MousePositionLast.X <= Position.X + Width) && (MousePositionLast.Y == Position.Y) )
		{
			this->SetAttribute(ButtonAttributeHovered);
		}
		else
		{
			this->SetAttribute(ButtonAttributeEnabled);
		}
	}

	void FButton::OnMousePress(const FEvent* const Event)
	{
		if ((MousePositionLast.X >= Position.X) && (MousePositionLast.X <= Position.X + Width) && (MousePositionLast.Y == Position.Y))
		{
			if (Event->MouseData.dwButtonState == FMouseButton::Left)
			{
				FEventSystem::PushEvent(FEvent(EEventType::ButtonPressed, FButtonData{ this->GetId(), FMouseButton::Left }));
			}
		}
	}


}