#include "area.hpp"

namespace area
{
    void script(ScriptSheet* const sheet)
    {
        RenderText* rendertext;

        sheet->addNewFont("./ressources/font.ttf");
        sheet->addNewRenderText("t1");

        rendertext = sheet->getRenderText("t1");

        if(rendertext != NULL)
        {
            rendertext->setSize(16);
            rendertext->setText("Hello world from area!");
        }
    }
}
