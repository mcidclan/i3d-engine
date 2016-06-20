#include "uitest.hpp"

namespace uitest
{
    void script(ScriptSheet* const sheet)
    {
        uint* param;
        float* logcp;
        //RenderMesh* mesh;
        //RenderText* text;
        UITextInput* uiti;
        ShaderSources shader;

        shader.push(GL_VERTEX_SHADER, Shader::vertex, Shader::vsize());
        shader.push(GL_FRAGMENT_SHADER, Shader::fragment, Shader::fsize());

        sheet->addNewFont("./ressources/uifont.ttf");

        sheet->addNewShaderProgram(shader);
        //sheet->addNewShape(RM_SHAPE_RECTANGLE);
        //sheet->addNewGui(GUI_MESSAGEBOX, "m1");

        logcp = new float[3];
        logcp[0] = eas::u<float>(P_X | P_Y);

        sheet->addNewGui(GUI_TEXTINPUT, "m1");

        sheet->addNewEvent((E_CALL | A_CURSOR_POSITION), logcp);
        sheet->addNewEvent((E_SET | A_POSITION), eas(P_X | P_Y)(256.0f)(256.0f)());
        sheet->addNewEvent((E_SET | A_SCALE), eas(P_X | P_Y)(100.0f)(100.0f)());

        uiti = (UITextInput*)sheet->getGui("m1");

        uiti->setTextSize(14);
        uiti->setTextMaxCharacters(14);
        uiti->setTextPosition(4.0f, 4.0f);

        sheet->buildKeyBoardAsTarget();

        //keymap 0
        {
            EASMap keymap;
            keymap['a' | KE_DOWN]((E_SET | A_SCALE),
            eas(P_X | P_Y)(256.0f)(256.0f)());
            //keymap['b' | KE_DOWN]((E_SET | A_KEYMAPID), eas(1)());
            keymap[SK_UP | SKE_DOWN]((E_SET | A_KEYMAPID), eas(1)());
            sheet->getKeyBoard()->addKeyMap(keymap);
        }

        param = new uint[2];
        param[0] = sizeof(uint);

        //keymap 1
        {
            EASMap keymap;
            keymap['a' | KE_DOWN]((E_SET | A_SCALE),
            eas(P_X | P_Y)(128.0f)(128.0f)());
            keymap[K_ALL | KE_DOWN]((E_SET | A_WRITE), param);
            keymap[K_DEL | KE_DOWN]((E_SET | A_ERASE), NULL);

            keymap[SK_LEFT | SKE_DOWN]((E_SET | A_MOVE), eas(-1)());
            keymap[SK_RIGHT | SKE_DOWN]((E_SET | A_MOVE), eas(1)());

            sheet->getKeyBoard()->addKeyMap(keymap);
        }

        //keymap 2
        {
            EASMap keymap;
            keymap[K_ALL | KE_DOWN]((E_GET | A_DATA), param);

            sheet->getKeyBoard()->addKeyMap(keymap);
        }

        sheet->addNewEvent((E_SET | A_KEYMAPID), eas(2)());
        sheet->addNewEvent((E_SET | A_TARGET), NULL);
        //eas(0)(0)(10));// 0 to 10
        //eas(2)(0)(1));// 0 and 1


        sheet->addNewShape(RM_SHAPE_RECTANGLE);
        sheet->addNewEvent((E_SET | A_SCALE), eas(P_X | P_Y)(2.0f)(14.0f)());
        sheet->addNewEvent((E_DO | A_POSITION), logcp);

    }
}

