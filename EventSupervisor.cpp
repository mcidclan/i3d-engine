#include "EventSupervisor.hpp"

EventSupervisor::EventSupervisor()
{
	this->eventstack[ES_TRANSIENT] = new EventStack();
	this->eventstack[ES_PERSISTENT] = new EventStack();
	//this->runnable = new Thread(EventSupervisor::processingEvents);
}

EventSupervisor::~EventSupervisor()
{
	delete this->eventstack[ES_TRANSIENT];
	delete this->eventstack[ES_PERSISTENT];
}

void EventSupervisor::addNewEvent(uint const action, void* const param)
{
	Event* event;

	event = new Event();

	event->setSource(SSDataBridge::source);
	event->setTarget(SSDataBridge::target);

	event->addAction(action);
	event->addParam(param);

	switch(action & E_CHECK)
	{
		case E_SET:
		case E_GET:
			this->addTransientEvent(event);
			break;

		case E_DO:
		case E_CALL:
			this->addPersistentEvent(event);
			break;
	}
}

void EventSupervisor::addTransientEvent(Event* const event)
{
	this->eventstack[ES_TRANSIENT]->push(event);
}

void EventSupervisor::addPersistentEvent(Event* const event)
{
	this->eventstack[ES_PERSISTENT]->push(event);
}

void EventSupervisor::processingTransientEvents(void)
{
	Event* event;
	EventStack* stack;

	stack = this->eventstack[ES_TRANSIENT];

	while(stack->size() > 0)
	{
		stack->pop(event);
		event->process();
		delete event;
	}
}

void EventSupervisor::processingPersistentEvents(void)
{
	uint i;
	EventStack* stack;

	i = 0;
	stack = this->eventstack[ES_PERSISTENT];	

	while(i < stack->size())
	{
		stack->at(i)->process();
		i++;
		// Check auto-remove here.
	}
}

void EventSupervisor::processingEvents(void)
{
	this->processingTransientEvents();
	this->processingPersistentEvents();
}
