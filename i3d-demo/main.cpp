#include <cstdio>
#include <iostream>
using namespace std;

#include "Renderer.hpp"
#include "scripts.hpp"

#include "MeshLoader.hpp"

static ScriptTree scripttree;

void initTies(void)
{
    {
        uint tie[] = {0};
        scripttree.setCurrentTie(tie);
        scripttree.addNewScriptSheet(home::script);
    }

    {
        uint tie[] = {0, 0};
        scripttree.setCurrentTie(tie);
        scripttree.addNewScriptSheet(area::script);
    }

    {
        uint tie[] = {0, 1};
        scripttree.setCurrentTie(tie);
        scripttree.addNewScriptSheet(uitest::script);
    }

    uint tie[] = {0, 1};
    scripttree.setCurrentTie(tie);
    scripttree.setCurrentScriptSheet();
}

int main(int argc, char** argv)
{
    initTies();

    Renderer renderer(argc, argv);
    renderer.setProcess(ScriptTree::draw);
    renderer.start();

    return 0;
}
