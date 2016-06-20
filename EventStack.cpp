#include "EventStack.hpp"

EventStack::EventStack()
{
}

EventStack::~EventStack()
{
}

void EventStack::push(Event* const event)
{
	this->push_back(new Event());
}

void EventStack::pop(Event*& event)
{
	event = this->back();
	this->pop_back();
}
