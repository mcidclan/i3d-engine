#ifndef HOME_HXX
#define HOME_HXX

	#include "shaders.hpp"

	namespace home
	{
		void script(ScriptSheet* const sheet)
		{
			ShaderSources shadersources;

			shadersources.push(GL_VERTEX_SHADER, vertexshader);
			shadersources.push(GL_FRAGMENT_SHADER, fragmentshader);

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
	}

#endif
