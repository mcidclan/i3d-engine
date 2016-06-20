#include "headers/Renderer.hpp"
#include "headers/shaders.hpp"

static ScriptTree scripttree;
static ShaderSources shadersources;

void script_0(ScriptSheet* const sheet)
{
	sheet->addNewShaderProgram(shadersources);
	sheet->addNewBufferedShape(RM_SHAPE_TRIANGLE);

	sheet->addNewFont("./font.ttf");
	sheet->addNewRenderText("t1");
	sheet->addNewRenderText("t2");

	sheet->getRenderText("t1")->setSize(16);
	sheet->getRenderText("t1")->setText("Hello World!");
	sheet->getRenderText("t2")->setSize(32);
	sheet->getRenderText("t2")->setText("2");
}

void script_0_0(ScriptSheet* const sheet)
{
	sheet->addNewFont("./font.ttf");
	sheet->addNewRenderText("t1");

	sheet->getRenderText("t1")->setSize(16);
	sheet->getRenderText("t1")->setText("Hello from script 02.");
}

void initTies(void)
{
	{
		uint tie[] = {0};
		scripttree.setCurrentTie(tie);
		scripttree.addNewScriptSheet(&script_0);
	}

	{
		uint tie[] = {0, 0};
		scripttree.setCurrentTie(tie);
		scripttree.addNewScriptSheet(&script_0_0);
	}

	uint tie[] = {0, 0};
	scripttree.setCurrentTie(tie);
	scripttree.setCurrentScriptSheet(0);
}

int main(int argc, char** argv)
{
	initTies();

	Renderer renderer(argc, argv);

	shadersources.push(GL_VERTEX_SHADER, vertexshader);
	shadersources.push(GL_FRAGMENT_SHADER, fragmentshader);

	renderer.setProcess(ScriptTree::draw);
	renderer.start();

	return 0;
}
