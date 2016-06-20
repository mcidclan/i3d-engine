#include "ControlKeyBoard.hpp"

ControlKeyBoard* ControlKeyBoard::current;

ControlKeyBoard::ControlKeyBoard(ScriptSheet* const sheet)
{
	this->group = EG_CONTROL;

	this->sheet = sheet;
	ControlKeyBoard::current = this;

	glutKeyboardFunc(ControlKeyBoard::keyDown);
	glutKeyboardUpFunc(ControlKeyBoard::keyUp);

	this->primetarget = 0;
	this->currenttarget = 0;
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

void ControlKeyBoard::asTarget(void)
{
	this->targets.insert(this->targets.begin(), this);
	this->primetarget = 1;
}

void ControlKeyBoard::dispatchEvents(void)
{
	uint i;
	uint kmid;
	EASMap* cmap;
	Element* target;
	EASMap::const_iterator a, b;

	i = 0;
	while(i < this->targets.size())
	{
		target = this->targets[i];

		if(target != NULL)
		{
			kmid = target->getKeyMapId();
			cmap = &this->keymaps[kmid];

			a = cmap->begin();
			b = cmap->end();

			while(a != b)
			{
				if((a->first == (this->currentkey & 0xFF)) ||
				(a->first == (this->currentkey & 0xF00)))
				{
					this->sheet->setEventSource(this);
					this->sheet->setEventTarget(target);
					this->sheet->addNewEvent(a->second.getAction(),
					a->second.getParam());
				}
				a++;
			}
		}
		i++;
	}

	this->currentkey = 0;
}

void ControlKeyBoard::pushToData(uchar const key)
{
	if(((key >= 32) && (key <= 126)) || (key >= 161))
	{
		this->data.append((const char*)&key, 1);
	}
}

void ControlKeyBoard::keyDown(uchar key, int x, int y)
{
	ControlKeyBoard::current->pushToData(key);
	ControlKeyBoard::current->currentkey = key;
	ControlKeyBoard::current->currentkey |= KE_ALL_DOWN;	
}

void ControlKeyBoard::keyUp(uchar key, int x, int y)
{
	cout << ": " << (uint)key << "\n";
	ControlKeyBoard::current->currentkey = key;
	ControlKeyBoard::current->currentkey |= KE_UP;
	ControlKeyBoard::current->currentkey |= KE_ALL_UP;
}

void ControlKeyBoard::aSet_target(void* const)
{
	vector<RenderShape*>* shapes;

	shapes = this->sheet->getShapes();

	if(shapes->size() > 0)
	{
		this->targets[this->primetarget] = shapes->at(this->currenttarget);
		this->currenttarget = (this->currenttarget + 1) % shapes->size();
	}
}

void ControlKeyBoard::aGet_data(void* const data)
{
	uint* idata = (uint*)data;

	if(this->data.length() > 0)
	{
		memcpy(&idata[1], this->data.c_str(), idata[0]);
		((uchar*)data)[(sizeof(uint) - 1) + idata[0]] = '\0';
		this->data.clear();
	}
}

void ControlKeyBoard::aCall_data(void* const data)
{
	this->aGet_data(data);
}

