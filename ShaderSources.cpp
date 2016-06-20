#include "headers/ShaderSources.hpp"

ShaderSources::ShaderSources()
{
}

ShaderSources::~ShaderSources()
{
}

GLuint ShaderSources::getType(unsigned int id)
{
	return this->types[id];
}

unsigned int ShaderSources::getLineNumber(unsigned int id)
{
	return this->linenumbers[id];
}
