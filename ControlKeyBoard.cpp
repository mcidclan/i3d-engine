#include "ControlKeyBoard.hpp"

ControlKeyBoard::ControlKeyBoard()
{
	glutKeyboardFunc(ControlKeyBoard::keyDown);
	glutKeyboardUpFunc(ControlKeyBoard::keyUp);
}

ControlKeyBoard::~ControlKeyBoard()
{
}

void ControlKeyBoard::keyDown(uchar key, int x, int y)
{

}

void ControlKeyBoard::keyUp(uchar key, int x, int y)
{
}

void ControlKeyBoard::setKeyMap(map<uchar, uint> const keymap)
{
	
}

//
void ControlKeyBoard::dispatchEvents(void) const
{
	uint i;

	i = 0;
	while(i < this->targets.size())
	{
		//this->currentsheet->addNewEvent((E_SET | A_?),
		//new ?[?]{?});
		i++;
	}
}
