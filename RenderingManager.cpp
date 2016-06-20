#include "headers/RenderingManager.hpp"

ShapeType RenderingManager::type;

GLuint RenderingManager::buffers[];

RenderingManager::RenderingManager()
{
	unsigned int i;

	i = 0;
	while(sizeof(RenderingManager::buffers))
	{
		RenderingManager::buffers[i] = 0;
	}
}

RenderingManager::~RenderingManager()
{
}

RenderShape* RenderingManager::getNewBufferedShape(unsigned char const type)
{
	RenderShape* shape;

	shape = this->getNewElement();

	if(shape != NULL)
	{
		if(!RenderingManager::buffers[type]);
		{
			glGenBuffers(1, &RenderingManager::buffers[type]);
			glBindBuffer(GL_ARRAY_BUFFER, RenderingManager::buffers[type]);
			glBufferData(GL_ARRAY_BUFFER, shape->getDataSize());
		}
		shape->setBufferId(RenderingManager::buffers[type]);
	}
	return shape;
}

RenderShape* RenderingManager::getNewShape(unsigned char const type)
{
	switch(type)
	{
		case SHAPE_TRIANGLE: return new RenderTriangle();
		case SHAPE_RECTANGLE: return new RenderRectangle();
	}
	return NULL;
}
