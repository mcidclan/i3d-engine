#include "ScriptSheet.hpp"

ScriptSheet::ScriptSheet(Script const init)
{
	this->init = init;
	this->initAttributes();
}

ScriptSheet::ScriptSheet() : RenderingManager(NULL)
{
	this->init = NULL;
	this->initAttributes();
}

ScriptSheet::~ScriptSheet()
{
	if(this->mouse != NULL) delete this->mouse;
	if(this->keyboard != NULL) delete this->keyboard;
	
	utils::dynamicDelete(this->sheets);
}

void ScriptSheet::initAttributes(void)
{
	this->mouse = NULL;
	this->keyboard = NULL;

	this->parent = NULL;
	this->lasting = false;
	this->initialized = false;
}

void ScriptSheet::buildMouse(void)
{
	this->mouse = new ControlMouse(this);
	this->setEventTarget(CTRL_MOUSE);
}

void ScriptSheet::buildKeyBoard(void)
{
	this->keyboard = new ControlKeyBoard(this);
	this->setEventTarget(CTRL_KEYBOARD);
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
			if(this->keyboard != NULL)
			{
				this->keyboard->dispatchEvents();
			}
			this->processingEvents();
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
		ScriptSheet* child;

		child = new ScriptSheet(init);
		child->setParent(sheet);

		sheet->getSheets()->push_back(child);
	}
	else cout << "Tie not available.\n";
}

void ScriptSheet::setParent(ScriptSheet* const parent)
{
	this->parent = parent;
}

void ScriptSheet::setLastingState(bool lasting)
{
	this->lasting = lasting;
}

void ScriptSheet::setEventSource(Element* const source)
{
	SSDataBridge::source = source;
}

void ScriptSheet::setEventSource(ElementType const source)
{
	setDataBridge(SSDataBridge::source, source);
}

void ScriptSheet::setEventTarget(Element* const target)
{
	SSDataBridge::target = target;
}

void ScriptSheet::setEventTarget(ElementType const target)
{
	setDataBridge(SSDataBridge::target, target);
}

void ScriptSheet::setDataBridge(Element*& element, ElementType const type)
{
	switch(type)
	{
		case CTRL_KEYBOARD:
			if(this->keyboard != NULL)
			{
				element = this->keyboard;
			}
			break;

		case CTRL_MOUSE:
			if(this->mouse != NULL)
			{
				element = this->mouse;
			}
			break;
	}
}

ScriptSheet* ScriptSheet::getParent(void) const
{
	return this->parent;
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

ControlMouse* ScriptSheet::getMouse(void) const
{
	return this->mouse;
}

ControlKeyBoard* ScriptSheet::getKeyBoard(void) const
{
	return this->keyboard;
}
