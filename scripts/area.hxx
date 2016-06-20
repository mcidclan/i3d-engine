#ifndef AREA_HXX
#define AREA_HXX

	#include "shaders.hpp"

	namespace area
	{

		void script(ScriptSheet* const sheet)
		{
			sheet->addNewFont("./font.ttf");
			sheet->addNewRenderText("t1");

			sheet->getRenderText("t1")->setSize(16);
			sheet->getRenderText("t1")->setText("Hello from script 02.");
		}
	}

#endif
