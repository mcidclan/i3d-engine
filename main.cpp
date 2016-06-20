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

int main(int argc, char** argv)
{
	Renderer renderer;
	RenderingManager renderingmanager;

	renderingmanager.addNewBufferedShape(RM_SHAPE_TRIANGLE);
	renderer.setProcess(RenderingManager::draw);

	renderer.start(argc, argv);

	return 0;
}
