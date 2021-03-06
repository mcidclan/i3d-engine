#include "home.hpp"

namespace home
{
    void script(ScriptSheet* const sheet)
    {
        RenderText* rendertext;
        ShaderSources shader;
        
        char const* const model = "./ressources/model.i3d";
        char const* const texture = "./ressources/suzanne.png";
        char const* const font = "./ressources/font.ttf";
        
        shader.push(GL_VERTEX_SHADER, Shader::vertex, Shader::vsize());
        shader.push(GL_FRAGMENT_SHADER, Shader::fragment, Shader::fsize());

        sheet->addNewShaderProgram(shader);
        sheet->addNewTexturedMesh(model, texture);
        //sheet->addNewMesh("./model.i3d");

        sheet->addNewEvent((E_SET | A_LOG),
        eas(0.0f)(0.0f)(0.0f)());

        sheet->addNewEvent((E_SET | A_SCALE),
        eas(P_X | P_Y)(256.0f)(256.0f)());

        sheet->addNewFont(font);
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
