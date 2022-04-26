#include "../PCH/pch.h"
#include "FApplication.h"

namespace wce
{
// Constructors and Destructor:

	FApplication::FApplication()
		: ShouldClose(false)
	{
		this->Init();
	}

	FApplication::~FApplication()
	{
	}


// Functions:

	void FApplication::Run()
	{
		ScreenBuffer.Activate();

		while (ShouldClose == false)
		{
			this->Update();

			this->Render();

			std::this_thread::sleep_for(std::chrono::milliseconds(33));
		}
	}

	void FApplication::Update()
	{
	}

	void FApplication::Render()
	{
		ScreenBuffer.Clear();

		ScreenBuffer.Write(COORD{ 50, 15 }, L"Test text for game!");

		ScreenBuffer.Present();
	}


// Private Functions:

	void FApplication::Init()
	{
	}


}