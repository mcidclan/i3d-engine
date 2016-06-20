#include "ElementActionSet.hpp"

ElementActionSet::ElementActionSet()
{
	this->action = 0;
	this->param = NULL;
}

ElementActionSet::~ElementActionSet()
{
}

void ElementActionSet::operator()(uint const action, void* const param)
{
	this->action = action;
	this->param = param;
}

void* ElementActionSet::operator()(void)
{
	uint* p;

	p = new uint[this->vparam.size()];
	copy(this->vparam.begin(), this->vparam.end(), p);

	this->param = p;
	return p;
}

uint ElementActionSet::getAction(void) const
{
	return this->action;
}

void* ElementActionSet::getParam(void) const
{
	return this->param;
}
