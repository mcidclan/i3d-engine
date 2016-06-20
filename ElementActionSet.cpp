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

uint ElementActionSet::getAction(void) const
{
	return this->action;
}

void* ElementActionSet::getParam(void) const
{
	return this->param;
}
