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

void Event::addAction(uint const action)
{
	this->addAction(ElementActionInformer::getAction(action));
}

void Event::addParam(void* const param)
{
	this->paramlist.push_back(param);
}

void Event::setSource(Element* const source)
{
	this->source = source;
}

void Event::setTarget(Element* const target)
{
	this->target = target;
}

void Event::process(void)
{
	uint i;
	void* param;
	ElementAction action;

	i = 0;
	while(i < this->actionlist.size())
	{
		param = this->paramlist[i];
		action = this->actionlist[i];

		if(action != NULL)
		{
			(this->target->*action)(param);
		}
		i++;
	}
}
