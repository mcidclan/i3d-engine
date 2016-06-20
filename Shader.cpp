#include "Shader.hpp"

GLchar const* Shader::vertex[] =
{
	//"#version 120\n",
	//"\n",
	"attribute vec3 a_vertice;\n",

	//"uniform mat4 u_pmatrix;\n",
	//"uniform mat4 u_vmatrix;\n",
	"\n",
	"void main(void)\n",
	"{\n",
	"	gl_Position = vec4(a_vertice, 1.0);\n",
	"}\n"
};

//u_pmatrix * u_vmatrix * 
GLchar const* Shader::fragment[] =
{
	//"#version 120\n",
	//"\n",
	"void main(void)\n",
	"{\n",
	"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n",
	"}\n"
};

uint Shader::vsize(void)
{
	return utils::count(Shader::vertex);
}

uint Shader::fsize(void)
{
	return utils::count(Shader::fragment);
}
