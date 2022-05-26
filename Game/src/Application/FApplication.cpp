#include "../PCH/pch.h"
#include "FApplication.h"

namespace wce
{
// Constructors and Destructor:

	FApplication::FApplication()
		: ShouldClose(false)
	{
		this->Init();

		FEventSystem::Subscribe(EEventType::ApplicationShutdown, this);
		FEventSystem::Subscribe(EEventType::MenuExit           , this);

		FEventSystem::PushEvent(FEvent(EEventType::ScreenSwitched, FScreenData{ EScreen::None, EScreen::Menu }));
	}

	FApplication::~FApplication()
	{
		FEventSystem::UnsubscribeFromAll(this);
	}


// Functions:

	void FApplication::Run()
	{
		do
		{
			this->PollEvents();

			this->Update();

			this->Render();

			std::this_thread::sleep_for(std::chrono::milliseconds(33));

		} while (ShouldClose == false);
	}

	void FApplication::PollEvents()
	{
		EventCatcher.CatchEvents();
		FEventSystem::PollEvents();
	}

	void FApplication::Update()
	{
	}

	void FApplication::Render()
	{
		Menu.Render();
	}


// Private Functions:

	void FApplication::Init()
	{
		Console.SetTitle(L"Secret Game!");
		Console.ArrangeToCenter();
	}


// IEventListener Interface:

	void FApplication::OnEvent(const FEvent* const Event)
	{
		switch (Event->GetType())
		{
			case EEventType::ApplicationShutdown:
			{
				this->OnApplicationShutdown(Event);
			}
			break;

			case EEventType::MenuExit:
			{
				this->OnMenuExit(Event);
			}
			break;
		}
	}


// Event Callbacks:

	void FApplication::OnApplicationShutdown(const FEvent* const Event)
	{
		ShouldClose = true;
	}

	void FApplication::OnMenuExit(const FEvent* const Event)
	{
		FEventSystem::PushEvent({EEventType::ApplicationShutdown});
	}


}