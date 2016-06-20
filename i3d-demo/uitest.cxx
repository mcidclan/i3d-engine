#include "uitest.hxx"

namespace uitest
{
	void script(ScriptSheet* const sheet)
	{
		RenderMesh* mesh;
		RenderText* text;
		ShaderSources shader;

		shader.push(GL_VERTEX_SHADER, Shader::vertex, Shader::vsize());
		shader.push(GL_FRAGMENT_SHADER, Shader::fragment, Shader::fsize());

		sheet->addNewFont("./font.ttf");

		sheet->addNewShaderProgram(shader);
		//sheet->addNewShape(RM_SHAPE_RECTANGLE);
		sheet->addNewGui(GUI_MESSAGEBOX, "m1");

		sheet->addNewEvent((E_SET | A_POSITION),
		eas(P_X | P_Y)(100.0f)(100.0f)());

		sheet->addNewEvent((E_SET | A_SCALE),
		eas(P_X | P_Y)(100.0f)(100.0f)());

		mesh = sheet->getGui("m1");
		text = ((UIMessageBox*)mesh)->getText();

		text->setSize(12);
		text->setText("Hello  From  Box!");

		sheet->buildKeyBoard();

		{
			EASMap keymap;
			keymap['a']((E_SET | A_SCALE),
			eas(P_X | P_Y)(256.0f)(256.0f)());
			keymap['b']((E_SET | A_KEYMAPID), eas(1)());

			sheet->getKeyBoard()->addKeyMap(keymap);
		}

		{
			EASMap keymap;
			keymap['a']((E_SET | A_SCALE),
			eas(P_X | P_Y)(128.0f)(128.0f)());

			sheet->getKeyBoard()->addKeyMap(keymap);
		}

		sheet->addNewEvent((E_SET | A_TARGET), eas(0)());
	}
}
