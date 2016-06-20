#include "uitest.hxx"

namespace uitest
{
	void script(ScriptSheet* const sheet)
	{
		uint* param;
		RenderMesh* mesh;
		RenderText* text;
		ShaderSources shader;

		shader.push(GL_VERTEX_SHADER, Shader::vertex, Shader::vsize());
		shader.push(GL_FRAGMENT_SHADER, Shader::fragment, Shader::fsize());

		sheet->addNewFont("./font.ttf");

		sheet->addNewShaderProgram(shader);
		//sheet->addNewShape(RM_SHAPE_RECTANGLE);
		//sheet->addNewGui(GUI_MESSAGEBOX, "m1");
		sheet->addNewGui(GUI_TEXTINPUT, "m1");

		sheet->addNewEvent((E_SET | A_POSITION),
		eas(P_X | P_Y)(256.0f)(256.0f)());
		sheet->addNewEvent((E_SET | A_SCALE),
		eas(P_X | P_Y)(100.0f)(100.0f)());

		mesh = sheet->getGui("m1");
		((UITextInput*)mesh)->setTextPosition(4.0f, 4.0f);
		text = ((UITextInput*)mesh)->getText();

		text->setSize(14);
		text->setText("Hello from box!");

		sheet->buildKeyBoardAsTarget();

		//keymap 0
		{
			EASMap keymap;
			keymap['a']((E_SET | A_SCALE),
			eas(P_X | P_Y)(256.0f)(256.0f)());
			keymap['b']((E_SET | A_KEYMAPID), eas(1)());

			sheet->getKeyBoard()->addKeyMap(keymap);
		}

		param = new uint[2];
		param[0] = sizeof(uint);

		//keymap 1
		{
			EASMap keymap;
			keymap['a']((E_SET | A_SCALE),
			eas(P_X | P_Y)(128.0f)(128.0f)());
			keymap[KE_ALL_DOWN]((E_SET | A_WRITE), param);

			sheet->getKeyBoard()->addKeyMap(keymap);
		}

		//keymap 2
		{
			EASMap keymap;
			keymap[KE_ALL_DOWN]((E_GET | A_DATA), param);

			sheet->getKeyBoard()->addKeyMap(keymap);
		}

		sheet->addNewEvent((E_SET | A_KEYMAPID), eas(2)());
		sheet->addNewEvent((E_SET | A_TARGET), NULL);
		//eas(0)(0)(10));// 0 to 10
		//eas(2)(0)(1));// 0 and 1
	}
}

