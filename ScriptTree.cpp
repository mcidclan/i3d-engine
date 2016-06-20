#include "ScriptTree.hpp"

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
			this->switchSheet(sheet->getSheets()->at(id));
		}
		else cout << "Currentsheet does not exist!\n";
	}
	else cout << "Can't use current tie.\n";
}

void ScriptTree::switchSheet(ScriptSheet* const sheet)
{
	if(this->currentsheet != NULL)
	{
		if(this->currentsheet->getLastingState())
		{
			this->currentsheet->leave();
		}
	}
	this->currentsheet = sheet;
}

void ScriptTree::doMove(void* data)
{
	if(this->currentsheet != NULL)
	{
		switch(*((char*)data))
		{
			case 'u': this->moveToUp(); break;
			case 'd': this->moveToDown(); break;
			case 'l': this->moveToLeft(); break;
			case 'r': this->moveToRight(); break;
		}
	}
}

void ScriptTree::moveToUp(void)
{
	//this->switchSheet(this->currentsheet->getParent());
}

void ScriptTree::moveToDown(void)
{
	vector<ScriptSheet*>* sheets;

	sheets = this->currentsheet->getSheets();
	if(sheets->size() > 0)
	{
		this->switchSheet(sheets->at(0));
	}
}

void ScriptTree::moveToLeft(void)
{
	//if(this->currentsheet
}

void ScriptTree::moveToRight(void)
{
}
