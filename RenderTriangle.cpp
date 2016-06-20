#include "RenderTriangle.hpp"

GLfloat const RenderTriangle::data[] =
{
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

RenderTriangle::RenderTriangle()
{
	this->vertexnumber = 3;
}

RenderTriangle::~RenderTriangle()
{
}

unsigned int RenderTriangle::getDataSize(void)
{
	return sizeof(RenderTriangle::data);
}

GLfloat const* RenderTriangle::getData(void)
{
	return RenderTriangle::data;
}
