#include "Element.hpp"

Element::Element()
{
	this->keymapid = 0;
	this->runnablestate = false;
}

Element::~Element()
{
}

uint Element::getKeyMapId(void) const
{
	return this->keymapid;
}

void Element::aGet_runnableState(void* const data)
{
	this->runnablestate = ((bool*)data)[0];
}

void Element::aSet_KeyMapId(void* const data)
{
	this->keymapid = ((uint*)data)[0];
}
