#include "../PCH/pch.h"
#include "FApplication.h"

namespace wce
{
// Constructors and Destructor:

	FApplication::FApplication()
		: ShouldClose(false)
	{
		this->Init();

		FEventSystem::PushEvent(FEvent(EEventType::ScreenSwitched, FScreenData{ EScreen::None, EScreen::Menu }));
	}

	FApplication::~FApplication()
	{
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


}