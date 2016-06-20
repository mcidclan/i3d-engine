#include "./headers/EventSupervisor.hpp"

EventSupervisor* EventSupervisor::current;

EventSupervisor::EventSupervisor()
{
	EventSupervisor::current = this;
	this->runnable = new Thread(EventSupervisor::run);
}

EventSupervisor::~EventSupervisor()
{
}

void* EventSupervisor::run(void* data)
{
	bool runnablestate;

	while(true)
	{
		current->getRunnableState(&runnablestate);

		if(!runnablestate)
		{
			break;
		}
		//current->eventstack;
	}

    return 0;
}
