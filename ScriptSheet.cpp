#include "headers/ScriptSheet.hpp"

ScriptSheet::ScriptSheet(void(* init)(void))
{
	this->init = init;
}

ScriptSheet::~ScriptSheet()
{
	utils::dynamicDelete(this->sheets);
}

void ScriptSheet::draw(void)
{
	if(!this->initialized)
	{
		this->init();
		this->initialized = true;
	}

	RenderingManager::draw();
}

vector<ScriptSheet*>* ScriptSheet::getSheets(void)
{
	return &(this->sheets);
}

void ScriptSheet::addNewScriptSheet(void(* init)(void),
vector<unsigned int>* const tie)
{
	ScriptSheet* sheet;

	sheet = this->getScriptSheet(0, tie);
	sheet->getSheets()->push_back(new ScriptSheet(init));
}

ScriptSheet* ScriptSheet::getScriptSheet(unsigned int const depth,
vector<unsigned int>* const tie) const
{
	unsigned int i;
	ScriptSheet* sheet;
	
	i = tie->at(depth);

	if(i < this->sheets.size())
	{
		if(depth < (tie->size() - 1))
		{
			sheet = this->sheets[i]->getScriptSheet((depth + 1), tie);
		}
		else return this->sheets[i];
	}
	else cout << "An error was occured: Tie not available.";

	return sheet;
}


/*move
in create
out delete
script*/

	/*if(depth < tie->size())
	{
		unsigned int i;

		i = tie->at(depth);

		if(i < this->sheets.size())
		{
			this->sheets[i]->addNewScriptSheet(tie, init, depth + 1);
		}
		else cout << "An error was occured: Tie not available.";
	}
	else this->sheets.push_back(new ScriptSheet(init));*/