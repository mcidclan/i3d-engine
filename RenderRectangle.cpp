#include "RenderRectangle.hpp"

GLfloat const RenderRectangle::data[] =
{
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	1.0f, 1.0f, 0.0f,
	-1.0f, 1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f
};

RenderRectangle::RenderRectangle()
{
}

RenderRectangle::~RenderRectangle()
{
}

unsigned int RenderRectangle::getDataSize(void)
{
	return sizeof(RenderRectangle::data);
}

GLfloat const* RenderRectangle::getData(void)
{
	return RenderRectangle::data;
}
