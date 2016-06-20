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

	event->setSource(SSDataBridge::lastnewsource);
	event->setTarget(SSDataBridge::lastnewtarget);

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

	stack = this->eventstack[ES_PERSISTENT];
	i = stack->size();

	while(i--)
	{
		stack->at(i)->process();
		// Check auto-remove here.
	}
}

void EventSupervisor::processingEvents(void)
{
	this->processingTransientEvents();
	this->processingPersistentEvents();
}
