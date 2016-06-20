#include "headers/RenderShape.hpp"

RenderShape::RenderShape()
{
	this->bufferid = 0;
}

RenderShape::~RenderShape()
{
}

void RenderShape::initAttributes(void)
{
	GLuint shpid;

	shpid = this->shaderprogram->getId();

	this->avertice = glGetAttribLocation(shpid, "a_vertice");	
}

void RenderShape::setShaderProgram(ShaderProgram* const shaderprogram)
{
	this->shaderprogram = shaderprogram;
	this->shaderprogram->link();
	this->initAttributes();
}

void RenderShape::setBufferId(GLuint bufferid)
{
	this->bufferid = bufferid;
}

void RenderShape::draw(void)
{
	this->shaderprogram->use();

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, this->bufferid);

	glVertexAttribPointer(this->avertice, 3,
	GL_FLOAT, GL_FALSE, 0, NULL);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}
