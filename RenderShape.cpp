#include "headers/RenderShape.hpp"

RenderShape::RenderShape()
{
	this->bufferid = 0;
}

RenderShape::~RenderShape()
{
}

unsigned int RenderShape::getDataSize(void)
{
}

void RenderShape::setBufferId(GLuint bufferid)
{
	this->bufferid = bufferid;
}
