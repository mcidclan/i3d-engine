#include "home.hxx"

namespace home
{
	void script(ScriptSheet* const sheet)
	{
		ShaderSources shader;

		shader.push(GL_VERTEX_SHADER, Shader::vertex, Shader::vsize());
		shader.push(GL_FRAGMENT_SHADER, Shader::fragment, Shader::fsize());

		sheet->addNewShaderProgram(shader);
		sheet->addNewBufferedShape(RM_SHAPE_TRIANGLE);

		sheet->addNewFont("./font.ttf");
		sheet->addNewRenderText("t1");
		sheet->addNewRenderText("t2");

		sheet->getRenderText("t1")->setSize(16);
		sheet->getRenderText("t1")->setText("Hello World!");
		sheet->getRenderText("t2")->setSize(32);
		sheet->getRenderText("t2")->setText("2");
	}
}
