#include "../PCH/pch.h"
#include "FEventSystem.h"

namespace wce
{
// Functions:

	void FEventSystem::PushEvent(const FEvent& Event)
	{
	}

	void FEventSystem::PollEvents()
	{
	}

	void FEventSystem::Subscribe(EEventType Type, IEventListener* Listener)
	{
	}

	void FEventSystem::Unsubscribe(EEventType Type, IEventListener* Listener)
	{
	}

	void FEventSystem::UnsubscribeFromAll(IEventListener* Listener)
	{
	}

	bool FEventSystem::IsSubscribed(EEventType Type, IEventListener* Listener)
	{
		return false;
	}

	void FEventSystem::ClearEventQueue()
	{
	}

	void FEventSystem::ClearListenerRegistry()
	{
	}


// Private Functions:

	void FEventSystem::Distapch(FEvent* Event)
	{
	}


// Static Variables:

	std::list<FEvent>                                    FEventSystem::EventQueue;
	std::unordered_multimap<EEventType, IEventListener*> FEventSystem::ListenerRegistry;


}