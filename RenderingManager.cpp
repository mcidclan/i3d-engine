#include "headers/RenderingManager.hpp"

RenderingManager* RenderingManager::current;

GLuint RenderingManager::buffers[RM_SHAPE_NUMBER];

RenderingManager::RenderingManager()
{
	unsigned int i;

	this->current = this;

	i = 0;
	while(sizeof(RenderingManager::buffers))
	{
		RenderingManager::buffers[i] = 0;
	}
}

RenderingManager::~RenderingManager()
{
	utils::dynamicDelete(this->shapes);
}

void RenderingManager::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderingManager::current->drawShape();
}

void RenderingManager::drawShape(void)
{
	unsigned int i;
	
	i = 0;
	while(i < this->shapes.size())
	{
		this->shapes[i]->draw();
	}
}

void RenderingManager::addNewBufferedShape(ShapeType const type)
{
	this->shapes.push_back(getNewBufferedShape(type));
}

RenderShape* RenderingManager::getNewBufferedShape(ShapeType const type)
{
	RenderShape* shape;

	shape = this->getNewShape(type);

	if(shape != NULL)
	{
		if(!RenderingManager::buffers[type])
		{
			glGenBuffers(1, &RenderingManager::buffers[type]);
			glBindBuffer(GL_ARRAY_BUFFER, RenderingManager::buffers[type]);
			glBufferData(GL_ARRAY_BUFFER, shape->getDataSize(),
			shape->getData(), GL_STATIC_DRAW);
		}
		shape->setBufferId(RenderingManager::buffers[type]);
	}
	return shape;
}

RenderShape* RenderingManager::getNewShape(ShapeType const type)
{
	switch(type)
	{
		case RM_SHAPE_TRIANGLE: return new RenderTriangle();
		case RM_SHAPE_RECTANGLE: return new RenderRectangle();
		case RM_SHAPE_NUMBER: return NULL;
	}
	return NULL;
}
