#include "../PCH/pch.h"
#include "SSettings.h"

namespace wce
{
// Constructors and Destructor:

	SSettings::SSettings() : IScreen(EScreen::Settings)
	{
		this->Init();

		FEventSystem::Subscribe(EEventType::ApplicationStarted , this);
		FEventSystem::Subscribe(EEventType::ApplicationShutdown, this);
		FEventSystem::Subscribe(EEventType::ScreenSwitched     , this);
	}

	SSettings::~SSettings()
	{
		FEventSystem::UnsubscribeFromAll(this);
	}


// IScreen Interface:

	void SSettings::Render()
	{
		if (this->IsActive())
		{
			ScreenBuffer.Clear();

			for (auto& [Key, Slider] : Sliders)
			{
				Slider.Draw(ScreenBuffer);
			}

			for (auto& [Key, Button] : Buttons)
			{
				Button.Draw(ScreenBuffer);
			}

			ScreenBuffer.Present();
		}
	}

	void SSettings::Update()
	{
	}

	void SSettings::Activate()
	{
		IScreen::Activate();

		FEventSystem::Subscribe(EEventType::ButtonPressed, this);
		FEventSystem::Subscribe(EEventType::KeyReleased  , this);

		for (auto& [Key, Slider] : Sliders)
		{
			Slider.Enable();
		}

		for (auto& [Key, Button] : Buttons)
		{
			Button.Enable();
		}
	}

	void SSettings::Deactivate()
	{
		IScreen::Deactivate();

		FEventSystem::Unsubscribe(EEventType::ButtonPressed, this);
		FEventSystem::Unsubscribe(EEventType::KeyReleased  , this);

		for (auto& [Key, Slider] : Sliders)
		{
			Slider.Disable();
		}

		for (auto& [Key, Button] : Buttons)
		{
			Button.Disable();
		}
	}


// Private Functions:

	void SSettings::Init()
	{
		Sliders[EScreenField::FontSize]   .SetPosition(COORD{ 10, 10 }).SetText(L"Font size");
		Sliders[EScreenField::SoundVolume].SetPosition(COORD{ 10, 12 }).SetText(L"Sound volume");
		Sliders[EScreenField::MusicVolume].SetPosition(COORD{ 10, 14 }).SetText(L"Music volume");

		Buttons[EButton::Back].SetPosition(COORD{ 10, 16 }).SetWidth(12).SetText(L"Back");
	}


// IEventListener Interface:

	void SSettings::OnEvent(const FEvent* const Event)
	{
		switch (Event->GetType())
		{
			case EEventType::ApplicationStarted:
			{
				this->OnApplicationStart(Event);
			}
			break;

			case EEventType::ApplicationShutdown:
			{
				this->OnApplicationShutdown(Event);
			}
			break;

			case EEventType::ScreenSwitched:
			{
				this->OnScreenSwitch(Event);
			}
			break;

			case EEventType::ButtonPressed:
			{
				this->OnButtonPress(Event);
			}
			break;

			case EEventType::KeyReleased:
			{
				this->OnKeyRelease(Event);
			}
			break;
		}
	}


// Event Callbacks:

	void SSettings::OnApplicationStart(const FEvent* const Event)
	{
	}

	void SSettings::OnApplicationShutdown(const FEvent* const Event)
	{
	}

	void SSettings::OnScreenSwitch(const FEvent* const Event)
	{
		if (Event->ScreenData.ToScreen == this->GetName())
		{
			this->Activate();
		}
		else
		{
			if (this->IsActive())
			{
				this->Deactivate();
			}			
		}
	}

	void SSettings::OnButtonPress(const FEvent* const Event)
	{
		if (Event->ButtonData.Id == Buttons.at(EButton::Back).GetId() && (Event->ButtonData.MouseButton == FMouseButton::Left))
		{
			FEventSystem::PushEvent(FEvent(EEventType::ScreenSwitched, FScreenData{ this->GetName(), EScreen::Menu }));
		}
	}

	void SSettings::OnKeyRelease(const FEvent* const Event)
	{
		if (Event->KeyData.wVirtualKeyCode == FKey::Escape)
		{
			FEventSystem::PushEvent(FEvent(EEventType::ScreenSwitched, FScreenData{ this->GetName(), EScreen::Menu }));
		}
	}


}