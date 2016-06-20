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
	ShaderSources shadersources;
	Renderer renderer(argc, argv);
	RenderingManager renderingmanager;

	
	shadersources.push(GL_VERTEX_SHADER, vertexshader);
	shadersources.push(GL_FRAGMENT_SHADER, fragmentshader);

	renderingmanager.addNewShaderProgram(shadersources);
	renderingmanager.addNewBufferedShape(RM_SHAPE_TRIANGLE);

	renderingmanager.addNewFont("./font.ttf");
	renderingmanager.addNewRenderText("test");
	renderingmanager.setRenderTextValue("test", "Hello World!");

	renderer.setProcess(RenderingManager::draw);
	renderer.start();

	return 0;
}
