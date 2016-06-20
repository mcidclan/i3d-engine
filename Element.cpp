#include "Element.hpp"

Element::Element()
{
	this->runnablestate = false;
}

Element::~Element()
{
}

void Element::getRunnableState(void* const data)
{
	this->runnablestate = *((bool*)data);
}