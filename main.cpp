#include "headers/Renderer.hpp"
#include "headers/RenderingManager.hpp"

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//triangle->draw();
}

int main(int argc, char** argv)
{
	Renderer renderer;
	RenderingManager renderingmanager;

	renderingmanager.addNewBufferedShape(RM_SHAPE_TRIANGLE);
	renderer.setProcess(drawingProcess);

	renderer.start(argc, argv);

	return 0;
}
