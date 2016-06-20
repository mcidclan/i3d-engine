#include "headers/Renderer.hpp"
#include "headers/ShaderProgram.hpp"

GLchar const* vertexshader[] =
{
	"attribute vec3 currentvertice;\n",
	"\n",
	"void main(void)\n",
	"{\n",
	"	gl_Position = vec4(currentvertice, 1.0);\n",
	"}\n"
};

GLchar const* fragmentshader[] =
{
	"void main(void)\n",
	"{\n",
	"	gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n",
	"}\n"
};

void drawingProcess(void)
{
	//
}

int main(int argc, char** argv)
{
	Renderer renderer(argc, argv);
	renderer.setProcess(drawingProcess);

	return 0;
}
