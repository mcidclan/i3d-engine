#include "RenderRectangle.hpp"

GLuint const RenderRectangle::indices[] =
{
	0, 1, 2, 2, 3, 0
};

GLfloat const RenderRectangle::coordinates[] =
{
	0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

RenderRectangle::RenderRectangle()
{
	this->vertexnumber = 6;
	this->vertexindices = (uint*)RenderRectangle::indices;
}

RenderRectangle::~RenderRectangle()
{
}

unsigned int RenderRectangle::getDataSize(BufferType type) const
{
	return sizeof(RenderRectangle::coordinates);
}

GLfloat const* RenderRectangle::getData(BufferType type) const
{
	return RenderRectangle::coordinates;
}

