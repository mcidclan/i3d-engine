#ifndef CONTROLMOUSE_HPP
#define CONTROLMOUSE_HPP

	class ScriptSheet;
	#include "ScriptSheet.hpp"

	class ControlMouse : public Element
	{
		public:
			///
			ControlMouse(ScriptSheet* const);

			///
			~ControlMouse();
	};

#endif
