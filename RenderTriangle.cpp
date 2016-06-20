#include "RenderTriangle.hpp"

GLfloat const RenderTriangle::coordinates[] =
{
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

GLuint const RenderTriangle::indices[] =
{
	0, 1, 2
};

RenderTriangle::RenderTriangle()
{
	this->vertexnumber = 3;
	this->vertexindices = (uint*)RenderTriangle::indices;
}

RenderTriangle::~RenderTriangle()
{
}

unsigned int RenderTriangle::getDataSize(BufferType type) const
{
	return sizeof(RenderTriangle::coordinates);
}

GLfloat const* RenderTriangle::getData(BufferType type) const
{
	return RenderTriangle::coordinates;
}
