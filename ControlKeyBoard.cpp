#include "ControlKeyBoard.hpp"

ControlKeyBoard* ControlKeyBoard::current;

ControlKeyBoard::ControlKeyBoard(ScriptSheet* const sheet)
{
	this->sheet = sheet;
	ControlKeyBoard::current = this;

	glutKeyboardFunc(ControlKeyBoard::keyDown);
	glutKeyboardUpFunc(ControlKeyBoard::keyUp);
}

ControlKeyBoard::~ControlKeyBoard()
{
}

void ControlKeyBoard::addKeyMap(map<uchar, EAS> const keymap)
{
	this->keymaps.push_back(keymap);
}

void ControlKeyBoard::dispatchEvents(void)
{
	uint i;
	uint kmid;
	EAS* aset;
	EASMap* cmap;

	i = 0;
	while(i < this->targets.size())
	{
		kmid = this->targets[i]->getKeyMapId();
		cmap = &this->keymaps[kmid];

		if(cmap->find(this->currentkey) != cmap->end())
		{
			aset = &cmap->at(this->currentkey);
			this->sheet->addNewEvent(aset->getAction(), aset->getParam());
			cmap->erase(this->currentkey);
		}
		i++;
	}
}

void ControlKeyBoard::keyDown(uchar key, int x, int y)
{
	ControlKeyBoard::current->currentkey = key;
}

void ControlKeyBoard::keyUp(uchar key, int x, int y)
{
	ControlKeyBoard::current->currentkey = key + '\1';
}
