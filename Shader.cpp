#include "Shader.hpp"

/*GLchar const* Shader::vertex[] =
{
	"#version 120\n",
	"\n",
	"attribute vec3 a_vertex;\n",
	"\n",
	"uniform mat4 u_pmatrix;\n",
	"uniform mat4 u_tmatrix;\n",
	"uniform mat4 u_rmatrix;\n",
	"\n",
	"void main(void)\n",
	"{\n",
		"gl_Position = u_pmatrix * u_tmatrix * vec4(a_vertex, 1.0);\n",
	"}\n"
};

GLchar const* Shader::fragment[] =
{
	"#version 120\n",
	"\n",
	"void main(void)\n",
	"{\n",
		"gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n",
	"}\n"
};*/


GLchar const* Shader::vertex[] =
{//highp
	"#version 120\n",
	"\n",
	"varying vec2 v_uvcoord;\n",
	"\n",
	"attribute vec3 a_vertex;\n",
	"attribute vec2 a_uvcoord;\n",
	"\n",
	"uniform mat4 u_pmatrix;\n",
	"uniform mat4 u_tmatrix;\n",
	"uniform mat4 u_rmatrix;\n",
	"\n",
	"void main(void)\n",
	"{\n",
	"gl_Position = u_pmatrix * u_tmatrix * vec4(a_vertex, 1.0);\n",
		"v_uvcoord = a_uvcoord;\n",
	"}\n"
};

GLchar const* Shader::fragment[] =
{
	"#version 120\n",
	"\n",
	"varying vec2 v_uvcoord;\n",
	"\n",
	"uniform sampler2D u_tsampler;\n",
	"\n",
	"void main(void)\n",
	"{\n",
		"gl_FragColor = texture2D(u_tsampler, v_uvcoord);\n",
	"}\n"
//vec4(1.0, 0.0, 0.0, 1.0);
};

uint Shader::vsize(void)
{
	return utils::count(Shader::vertex);
}

uint Shader::fsize(void)
{
	return utils::count(Shader::fragment);
}
