#include "Event.hpp"

Event::Event()
{
	this->source = NULL;
	this->target = NULL;
}

Event::~Event()
{
	if((this->source == NULL) ||
	(this->source->getGroup() != EG_CONTROL))
	{
		uint i;

		i = 0;
		while(i < this->paramlist.size())
		{
			delete [] reinterpret_cast<uint*>(this->paramlist[i]);
			i++;
		}
	}
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

Element* Event::getSource(void)
{
	return this->source;
}

Element* Event::getTarget(void)
{
	return this->target;
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

		if(action != NULL && target != NULL)
		{
			(this->target->*action)(param);
		}
		else cout << "Action does not exist.\n";

		i++;
	}
}
