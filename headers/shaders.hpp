#ifndef SHADERS_HPP
#define SHADERS_HPP

	#include "ScriptTree.hpp"

	static GLchar const* vertexshader[] =
	{
		"#version 120",
		"\n",
		"attribute vec3 a_vertice;\n",
		"\n",
		"void main(void)\n",
		"{\n",
		"	gl_Position = vec4(a_vertice, 1.0);\n",
		"}\n"
	};

	static GLchar const* fragmentshader[] =
	{
		"#version 120",
		"\n",
		"void main(void)\n",
		"{\n",
		"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n",
		"}\n"
	};

#endif
