#include "ScriptSheet.hpp"

ScriptSheet::ScriptSheet(Script const init)
{
	this->init = init;
	this->lasting = false;
}

ScriptSheet::ScriptSheet() : RenderingManager(NULL)
{
	this->init = NULL;
	this->lasting = false;
}

ScriptSheet::~ScriptSheet()
{
	utils::dynamicDelete(this->sheets);
}

void ScriptSheet::leave(void)
{
	if(this->initialized)
	{
		this->clean();
		this->initialized = false;
	}
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

		if(this->initialized)
		{
			RenderingManager::draw();
		}
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

void ScriptSheet::setLastingState(bool lasting)
{
	this->lasting = lasting;
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

bool ScriptSheet::getLastingState(void)
{
	return this->lasting;
}
