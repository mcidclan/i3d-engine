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

void Element::getRunnableState(void* const data)
{
	this->runnablestate = *((bool*)data);
}
