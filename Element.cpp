#include "Element.hpp"

Element::Element()
{
	this->keymapid = 0;
	this->group = EG_UNDEFINED;
	this->runnablestate = false;
}

Element::~Element()
{
}

uint Element::getKeyMapId(void) const
{
	return this->keymapid;
}


uint Element::getGroup(void) const
{
	return this->group;
}

void Element::aGet_runnableState(void* const data)
{
	this->runnablestate = ((bool*)data)[0];
}

void Element::aSet_KeyMapId(void* const data)
{
	this->keymapid = ((uint*)data)[0];
}

