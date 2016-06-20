#ifndef CONTROLKEYBOARD_HPP
#define CONTROLKEYBOARD_HPP

	class ScriptSheet;
	#include "ScriptSheet.hpp"
	#include "ElementActionSet.hpp"
	#include <GL/glut.h>

	#define up | 0x100
	
	typedef map<uint, EAS> EASMap;

	/// Allows to use the keyboard events in the current ScriptSheet.
	class ControlKeyBoard : public Element
	{
		public:
			/// Constructor.
			ControlKeyBoard(ScriptSheet* const);

			/// Destructor.
			~ControlKeyBoard();

			/// Dispatches the Events to the currents targets.
			void dispatchEvents(void);

			/// Allows to add a new map.
			void addKeyMap(EASMap const);

			/// Allows to get the current key down.
			static void keyDown(uchar, int, int);

			/// Allows to get the current key up.
			static void keyUp(uchar, int, int);

			///@{
			/// Actions
			void aSet_target(void* const);
			///@}

		private:
			/// Current ControlKeyBoard used by the current ScriptSheet.
			static ControlKeyBoard* current;

			/// The sheet to which the keyboard is linked.
			ScriptSheet* sheet;

			/// Cursor to the current target id;
			uint currenttargetid;

			/// Current used key.
			uint currentkey;

			/// List of availables maps between keys and actions.
			vector<EASMap> keymaps;

			/// List of all currents targets.
			vector<Element*> targets;
	};

#endif