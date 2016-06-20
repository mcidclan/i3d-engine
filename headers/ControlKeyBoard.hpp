#ifndef CONTROLKEYBOARD_HPP
#define CONTROLKEYBOARD_HPP

	#include <GL/glut.h>
	#include "Element.hpp"

	class ControlKeyBoard
	{
		public:
			///
			ControlKeyBoard();

			///
			~ControlKeyBoard();

			///
			void dispatchEvents(void) const;

			///
			static void keyDown(uchar, int, int);

			///
			static void keyUp(uchar, int, int);

			///
			void setKeyMap(map<uchar, uint> const);

		private:
			///
			vector<Element*> targets;
	};

#endif