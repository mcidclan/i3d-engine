#include "headers/Renderer.hpp"
#include "headers/RenderingManager.hpp"

GLchar const* vertexshader[] =
{
	//"#version 120",
	"attribute vec3 a_vertice;\n",
	"\n",
	"void main(void)\n",
	"{\n",
	"	gl_Position = vec4(a_vertice, 1.0);\n",
	"}\n"
};

GLchar const* fragmentshader[] =
{
	//"#version 120",
	"\n",
	"void main(void)\n",
	"{\n",
	"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n",
	"}\n"
};

int main(int argc, char** argv)
{
	/*ShaderSources shadersources;
	Renderer renderer(argc, argv);
	RenderingManager renderingmanager;

	
	shadersources.push(GL_VERTEX_SHADER, vertexshader);
	shadersources.push(GL_FRAGMENT_SHADER, fragmentshader);

	renderingmanager.addNewShaderProgram(shadersources);
	renderingmanager.addNewBufferedShape(RM_SHAPE_TRIANGLE);

	renderingmanager.addNewFont("./font.ttf");
	renderingmanager.addNewRenderText("t1");
	renderingmanager.addNewRenderText("t2");

	renderingmanager.getRenderText("t1")->setSize(16);
	renderingmanager.getRenderText("t1")->setText("Hello World!");
	renderingmanager.getRenderText("t2")->setSize(32);
	renderingmanager.getRenderText("t2")->setText("2");

	renderer.setProcess(RenderingManager::draw);
	renderer.start();*/

	return 0;
}
