#include "RenderShape.hpp"

/*GLfloat RenderShape::pmatrix[] =
{
	(2.0f/768.0f), 0.0f, 0.0f, -1.0f,
	0.0f, (2.0f/1024.0f), 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};*/

RenderShape::RenderShape()
{
	this->bufferid = 0;
	//this->vmatrix = new GLfloat[16];
	//math::setIdentityMatrix(this->vmatrix);
}

RenderShape::~RenderShape()
{
	delete [] this->vmatrix;
}

void RenderShape::initShaderVariableLocations(void)
{
	GLuint shpid;

	shpid = this->shaderprogram->getId();

	this->avertice = glGetAttribLocation(shpid, "a_vertice");
	//this->upmatrix = glGetUniformLocation(shpid, "u_pmatrix");
	//this->uvmatrix = glGetUniformLocation(shpid, "u_vmatrix");
}

void RenderShape::initShaderVariables()
{
	//glUniformMatrix4fv(this->upmatrix, 16, false, RenderShape::pmatrix);
	//glUniformMatrix4fv(this->uvmatrix, 16, false, this->vmatrix);
}

void RenderShape::setShaderProgram(ShaderProgram* const shaderprogram)
{
	this->shaderprogram = shaderprogram;
	this->shaderprogram->link();

	this->initShaderVariableLocations();
	//this->initShaderVariables();
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
