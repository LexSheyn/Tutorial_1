#include "../PCH/pch.h"
#include "FEventSystem.h"

namespace wce
{
// Functions:

	void FEventSystem::PushEvent(const FEvent& Event)
	{
		EventQueue.push_back(Event);
	}

	void FEventSystem::PollEvents()
	{
		while (EventQueue.empty() == false)
		{
			Dispatch(&EventQueue.front());

			EventQueue.pop_front();
		}
	}

	void FEventSystem::Subscribe(EEventType Type, IEventListener* Listener)
	{
		if (IsSubscribed(Type, Listener))
		{
			return;
		}

		ListenerRegistry.insert({ Type, Listener });
	}

	void FEventSystem::Unsubscribe(EEventType Type, IEventListener* Listener)
	{
		if (IsSubscribed(Type, Listener) == false)
		{
			return;
		}

		std::pair Range = ListenerRegistry.equal_range(Type);

		for (auto& Entry = Range.first; Entry != Range.second; ++Entry)
		{
			if (Entry->second == Listener)
			{
				Entry = ListenerRegistry.erase(Entry);
	
				return;
			}
		}
	}

	void FEventSystem::UnsubscribeFromAll(IEventListener* Listener)
	{
		std::unordered_multimap<EEventType, IEventListener*>::iterator Entry = ListenerRegistry.begin();

		while (Entry != ListenerRegistry.end())
		{
			if (Entry->second == Listener)
			{
				Entry = ListenerRegistry.erase(Entry);
			}
			else
			{
				++Entry;
			}
		}
	}

	bool FEventSystem::IsSubscribed(EEventType Type, IEventListener* Listener)
	{
		std::pair Range = ListenerRegistry.equal_range(Type);

		for (auto& Entry = Range.first; Entry != Range.second; ++Entry)
		{
			if (Entry->second == Listener)
			{
				return true;
			}
		}

		return false;
	}

	void FEventSystem::ClearEventQueue()
	{
		EventQueue.clear();
	}

	void FEventSystem::ClearListenerRegistry()
	{
		ListenerRegistry.clear();
	}


// Private Functions:

	void FEventSystem::Dispatch(FEvent* Event)
	{
		std::pair Range = ListenerRegistry.equal_range(Event->GetType());

		for (auto& Entry = Range.first; Entry != Range.second; ++Entry)
		{
			Entry->second->OnEvent(Event);
		}
	}


// Static Variables:

	std::list<FEvent>                                    FEventSystem::EventQueue;
	std::unordered_multimap<EEventType, IEventListener*> FEventSystem::ListenerRegistry;


}