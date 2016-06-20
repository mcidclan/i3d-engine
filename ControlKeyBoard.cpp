#include "ControlKeyBoard.hpp"

ControlKeyBoard* ControlKeyBoard::current;

ControlKeyBoard::ControlKeyBoard(ScriptSheet* const sheet)
{
	this->sheet = sheet;
	ControlKeyBoard::current = this;

	glutKeyboardFunc(ControlKeyBoard::keyDown);
	glutKeyboardUpFunc(ControlKeyBoard::keyUp);

	this->currenttargetid = 0;
	this->targets.push_back(NULL);

	cout << "New ControlKeyBoard.\n";
}

ControlKeyBoard::~ControlKeyBoard()
{
}

void ControlKeyBoard::addKeyMap(map<uint, EAS> const keymap)
{
	this->keymaps.push_back(keymap);
}

void ControlKeyBoard::dispatchEvents(void)
{
	uint i;
	uint kmid;
	EAS* aset;
	EASMap* cmap;
	Element* target;

	i = 0;
	while(i < this->targets.size())
	{
		target = this->targets[i];

		if(target != NULL)
		{
			kmid = target->getKeyMapId();

			cmap = &this->keymaps[kmid];

			if(cmap->find(this->currentkey) != cmap->end())
			{
				aset = &cmap->at(this->currentkey);
				this->sheet->setEventTarget(target);
				this->sheet->addNewEvent(aset->getAction(), aset->getParam());
			}
		}
		i++;
	}

	this->currentkey = 0;
}

void ControlKeyBoard::keyDown(uchar key, int x, int y)
{
	ControlKeyBoard::current->currentkey = key;
}

void ControlKeyBoard::keyUp(uchar key, int x, int y)
{
	ControlKeyBoard::current->currentkey = 0x100;
	ControlKeyBoard::current->currentkey |= key;
}

void ControlKeyBoard::aSet_target(void* const)
{
	vector<RenderShape*>* shapes;

	shapes = this->sheet->getShapes();

	if(shapes->size() > 0)
	{
		this->targets[0] = shapes->at(this->currenttargetid);
		this->currenttargetid = (this->currenttargetid + 1) % shapes->size();
	}
}