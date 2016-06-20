#include "headers/ScriptSheet.hpp"

ScriptSheet::ScriptSheet(Script const init)
{
	this->init = init;
}

ScriptSheet::ScriptSheet() : RenderingManager(NULL)
{
	this->init = NULL;
}

ScriptSheet::~ScriptSheet()
{
	utils::dynamicDelete(this->sheets);
}

void ScriptSheet::draw(void)
{
	if(this->init != NULL)
	{
		if((!this->initialized))
		{
			this->init(this);
			this->initialized = true;
		}

		RenderingManager::draw();
	}
}

void ScriptSheet::addNewScriptSheet(Script const init, vuint* const tie)
{
	ScriptSheet* sheet;

	sheet = this->getScriptSheet(0, tie);
	
	if(sheet != NULL)
	{
		sheet->getSheets()->push_back(new ScriptSheet(init));
	}
	else cout << "Tie not available.\n";
}

ScriptSheet* ScriptSheet::getScriptSheet(uint const depth, vuint* const tie)
{
	uint nextdepth;

	nextdepth = depth + 1;

	if(nextdepth < tie->size())
	{
		uint i;

		i = tie->at(depth);

		if(i < this->sheets.size())
		{
			return this->sheets[i]->getScriptSheet(nextdepth, tie);
		}
		return NULL;
	}
	return this;
}

vector<ScriptSheet*>* ScriptSheet::getSheets(void)
{
	return &(this->sheets);
}
