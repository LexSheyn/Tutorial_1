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
		Menu.Activate();

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
		Menu.Render();
	}


// Private Functions:

	void FApplication::Init()
	{
	}


}