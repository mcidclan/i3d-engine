#include "uitest.hxx"

namespace uitest
{
	void script(ScriptSheet* const sheet)
	{
		ControlKeyBoard* controlkeyboard;

		map<uchar, uint> keymap;
		keymap['a'] = (E_SET | A_LOG);

		controlkeyboard->setKeyMap(keymap);
	}
}
