#include "./headers/EventSupervisor.hpp"

EventSupervisor* EventSupervisor::supervisor;

EventSupervisor::EventSupervisor()
{
	EventSupervisor::supervisor = this;
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
		supervisor->getRunnableState(&runnablestate);

		if(!runnablestate)
		{
			break;
		}
		//supervisor->eventstack;
	}

    return 0;
}
