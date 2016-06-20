#include "RenderShape.hpp"

/*GLfloat RenderShape::pmatrix[] =
{
	(2.0f/(GLfloat)SCR_WIDTH), 0.0f, 0.0f, 0.0f,
	0.0f, -(2.0f/(GLfloat)SCR_HEIGHT), 0.0f, 0.0f,
	0.0f, 0.0f, -2.0f, 0.0f,
	-1.0f, 1.0f, -1.0f, 1.0f
};*/

GLfloat RenderShape::pmatrix[] =
{
	(2.0f/(GLfloat)SCR_WIDTH), 0.0f, 0.0f, 0.0f,
	0.0f, (2.0f/(GLfloat)SCR_HEIGHT), 0.0f, 0.0f,
	0.0f, 0.0f, -1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f, 1.0f
};

RenderShape::RenderShape()
{
	this->bufferid = 0;
	this->tmatrix = new GLfloat[16];
	this->rmatrix = new GLfloat[16];

	math::setIdentityMatrix4x4(this->tmatrix);
	math::setIdentityMatrix4x4(this->rmatrix);
}

RenderShape::~RenderShape()
{
	delete [] this->tmatrix;
	delete [] this->rmatrix;
}

void RenderShape::initShaderVariableLocations(void)
{
	GLuint shpid;

	shpid = this->shaderprogram->getId();

	this->avertice = glGetAttribLocation(shpid, "a_vertice");
	this->upmatrix = glGetUniformLocation(shpid, "u_pmatrix");
	this->utmatrix = glGetUniformLocation(shpid, "u_tmatrix");
}

void RenderShape::updateUniformShaderVariables(void)
{
	glUniformMatrix4fv(this->upmatrix, 1, GL_FALSE, RenderShape::pmatrix);
	glUniformMatrix4fv(this->utmatrix, 1, GL_FALSE, this->tmatrix);
	glUniformMatrix4fv(this->urmatrix, 1, GL_FALSE, this->rmatrix);
}

void RenderShape::setShaderProgram(ShaderProgram* const shaderprogram)
{
	this->shaderprogram = shaderprogram;
	this->shaderprogram->link();
	this->initShaderVariableLocations();
}

void RenderShape::setBufferId(GLuint bufferid)
{
	this->bufferid = bufferid;
}

static float test[] = {0.0f, 1024.0f, 256.0f, 1.0f};

void RenderShape::draw(void)
{
	this->shaderprogram->use();
	this->updateUniformShaderVariables();

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, this->bufferid);

	glVertexAttribPointer(this->avertice, 3,
	GL_FLOAT, GL_FALSE, 0, NULL);

	glDrawArrays(GL_TRIANGLES, 0, this->vertexnumber);

	glDisableVertexAttribArray(0);

	((uchar*)test)[0] = 7;
	this->doScale(test);
}

/*void RenderShape::doTranslate(void* data)
{
	this->tmatrix[12]
	this->tmatrix[13]
	this->tmatrix[14]
}*/

void RenderShape::doScale(void* const data)
{
	uchar* const idata = (uchar*)data;
	float* const vdata = (float*)data;

	if(idata[0] & 1) this->tmatrix[0] = vdata[1];
	if(idata[0] & 2) this->tmatrix[5] = vdata[2];
	if(idata[0] & 4) this->tmatrix[10] = vdata[3];
}
