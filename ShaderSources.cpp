#include "ShaderSources.hpp"

ShaderSources::ShaderSources()
{
}

ShaderSources::~ShaderSources()
{
}

GLuint ShaderSources::getType(uint id)
{
	return this->types[id];
}

uint ShaderSources::getLineNumber(uint id)
{
	return this->linenumbers[id];
}

void ShaderSources::push(GLuint type,
GLchar const** source, uint const size)
{
	this->push_back(source);
	this->types.push_back(type);
	this->linenumbers.push_back(size);
}
