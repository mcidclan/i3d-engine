#include "uitest.hxx"

namespace uitest
{
	void script(ScriptSheet* const sheet)
	{
		ShaderSources shader;

		shader.push(GL_VERTEX_SHADER, Shader::vertex, Shader::vsize());
		shader.push(GL_FRAGMENT_SHADER, Shader::fragment, Shader::fsize());

		sheet->addNewFont("./font.ttf");

		sheet->addNewShaderProgram(shader);
		sheet->addNewTexturedMesh("model.i3d", "suzanne.png");	

		//sheet->addNewShape(RM_SHAPE_RECTANGLE);
		//sheet->addNewGui(GUI_MESSAGEBOX, "m1");

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
