#include "headers/ScriptTree.hpp"

ScriptTree* ScriptTree::current;

ScriptTree::ScriptTree()
{
	this->current = this;
	this->root = new ScriptSheet();
	this->tie = NULL;
}

ScriptTree::~ScriptTree()
{
}

void ScriptTree::draw(void)
{
	ScriptTree::current->currentsheet->draw();
}

void ScriptTree::addNewScriptSheet(Script const init)
{
	if(this->tie != NULL)
	{
		vector<uint> vtie;

		utils::vectorFrom(vtie, this->tie, this->tiedepth);
		this->root->addNewScriptSheet(init, &vtie);
	}
	else cout << "Can't use current tie.\n";
}

void ScriptTree::setCurrentScriptSheet(uint const id)
{
	if(this->tie != NULL)
	{
		vector<uint> vtie;
		ScriptSheet* sheet;

		utils::vectorFrom(vtie, this->tie, this->tiedepth);
		sheet = this->root->getScriptSheet(0, &vtie);

		if((sheet != NULL) && (id < sheet->getSheets()->size()))
		{
			this->currentsheet = sheet->getSheets()->at(id);
		}
		else cout << "Currentsheet does not exist!\n";
	}
	else cout << "Can't use current tie.\n";
}
