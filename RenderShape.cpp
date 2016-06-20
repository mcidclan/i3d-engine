#include "RenderShape.hpp"

GLfloat RenderShape::pmatrix[] =
{
	(2.0f/(GLfloat)SCR_WIDTH), 0.0f, 0.0f, 0.0f,
	0.0f, (2.0f/(GLfloat)SCR_HEIGHT), 0.0f, 0.0f,
	0.0f, 0.0f, -1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f, 1.0f
};

RenderShape::RenderShape()
{
	this->textured = true;
	this->textureid = loadBMP_custom("uvtemplate.bmp");

	this->bufferid[V_BUFFER] = 0;
	this->bufferid[UV_BUFFER] = 0;

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

	this->avertex = glGetAttribLocation(shpid, "a_vertex");
	this->auvcoord = glGetAttribLocation(shpid, "a_uvcoord");

	this->utsampler = glGetUniformLocation(shpid, "u_tsampler");

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

void RenderShape::setBufferId(BufferType const buffertype,
GLuint const bufferid)
{
	this->bufferid[buffertype] = bufferid;
}

void RenderShape::draw(void)
{
	this->shaderprogram->use();
	this->updateUniformShaderVariables();

	cout << V_BUFFER << this->bufferid[V_BUFFER] << "\n";

	glEnableVertexAttribArray(V_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, this->bufferid[V_BUFFER]);
	glVertexAttribPointer(this->avertex, 3,
	GL_FLOAT, GL_FALSE, 0, NULL);

	if(this->textured)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->textureid);
		glUniform1i(this->utsampler, 0);

		glEnableVertexAttribArray(UV_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->bufferid[UV_BUFFER]);
		glVertexAttribPointer(this->auvcoord, 2,
		GL_FLOAT, GL_FALSE, 0, NULL);
	}
	
	glDrawElements(GL_TRIANGLES, this->vertexnumber,
	GL_UNSIGNED_INT, this->vertexindices);

	glDisableVertexAttribArray(V_BUFFER);

	if(this->textured)
	{
		glDisableVertexAttribArray(UV_BUFFER);
	}
}

/*
void RenderShape::doTranslate(void* data)
{
	this->tmatrix[12]
	this->tmatrix[13]
	this->tmatrix[14]
}
*/

void RenderShape::doScale(void* const data)
{
	uchar* const idata = (uchar*)data;
	float* const vdata = (float*)data;

	if(idata[0] & P_X) this->tmatrix[0] = vdata[1];
	if(idata[0] & P_Y) this->tmatrix[5] = vdata[2];
	if(idata[0] & P_Z) this->tmatrix[10] = vdata[3];
}

void RenderShape::setLog(void* const data)
{
	cout << "setLog not available yet.\n";
}
