#include "home.hxx"

namespace home
{
	void script(ScriptSheet* const sheet)
	{
		ShaderSources shader;
		RenderText* rendertext;

		shader.push(GL_VERTEX_SHADER, Shader::vertex, Shader::vsize());
		shader.push(GL_FRAGMENT_SHADER, Shader::fragment, Shader::fsize());

		sheet->addNewShaderProgram(shader);
		//sheet->addNewShape(RM_SHAPE_RECTANGLE);
		sheet->addNewMesh("./model.i3d");

		{
			sheet->addNewEvent((E_SET | A_LOG),
			new float[3]{0.0f, 0.0f, 0.0f});
		}

		{
			sheet->addNewEvent((E_DO | A_SCALE),
			new float[3]{utils::alter(P_X | P_Y), 512.0f, 256.0f});
		}

		sheet->addNewFont("./font.ttf");
		sheet->addNewRenderText("t1");
		sheet->addNewRenderText("t2");

		rendertext = sheet->getRenderText("t1");
		if(rendertext != NULL)
		{
			rendertext->setSize(16);
			rendertext->setText("Small Text.");
		}

		rendertext = sheet->getRenderText("t2");
		if(rendertext != NULL)
		{
			rendertext->setSize(32);
			rendertext->setText("Big Text.");
		}
	}
}
