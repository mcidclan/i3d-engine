#include "Event.hpp"

Event::Event()
{
}

Event::~Event()
{
}

void Event::addAction(ElementAction const action)
{
	this->actionlist.push_back(action);
}
