#include "headers/RenderShape.hpp"

RenderShape::RenderShape()
{
	this->bufferid = 0;
}

RenderShape::~RenderShape()
{
}

void RenderShape::setBufferId(GLuint bufferid)
{
	this->bufferid = bufferid;
}

void RenderShape::draw(void)
{
	//bufferid
}
