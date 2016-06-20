#include "headers/ShaderProgram.hpp"

ShaderProgram::ShaderProgram()
{
	this->linked = false;
	this->program = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(this->program);

	while(this->shaders.size() != 0)
	{
		glDeleteShader(this->shaders.back());
		this->shaders.pop_back();
	}
}

void ShaderProgram::link(void)
{
	if(!this->linked)
	{
		glLinkProgram(this->program);
		this->linked = true;
	}
}

void ShaderProgram::use(void)
{
	this->link();
	glUseProgram(this->program);
}

GLuint ShaderProgram::getId()
{
	return this->program;
}

void ShaderProgram::addSource(GLuint type,
GLchar const** source, unsigned int linenumber)
{
	GLuint shader;

	shader = glCreateShader(type);
	glShaderSource(shader, linenumber, source, NULL);
	glCompileShader(shader);

	glAttachShader(this->program, shader);
	this->shaders.push_back(shader);
}
