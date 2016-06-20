#ifndef CONTROLKEYBOARD_HPP
#define CONTROLKEYBOARD_HPP

	class ScriptSheet;
	#include "ScriptSheet.hpp"
	#include "ElementActionSet.hpp"
	#include <GL/glut.h>

	enum KeyInfos
	{
		K_DEL = 0x8,
		K_TAB = 0x9,
		K_ENTER = 0x13,

		/*SK_LEFT = 0x0,
		SK_LRIGHT = 0x0,
		SK_UP = 0x0,
		SK_DOWN = 0x0,*/

		KE_UP = 0x100,
		KE_DOWN = 0x200,
		KE_ALL = 0x400
	};
	
	typedef map<uint, EAS> EASMap;

	/// Allows to use the keyboard events in the current ScriptSheet.
	class ControlKeyBoard : public Element
	{
		public:
			/// Constructor.
			ControlKeyBoard(ScriptSheet* const);

			/// Destructor.
			~ControlKeyBoard();

			/// Allows to auto-focus himself.
			void asTarget(void);

			/// Dispatches the Events to the currents targets.
			void dispatchEvents(void);

			/// Allows to add a new map.
			void addKeyMap(EASMap const);

			///
			void pushToData(uchar const);

			/// Allows to get the current key down.
			static void keyDown(uchar, int, int);

			/// Allows to get the current key up.
			static void keyUp(uchar, int, int);

			///@{
			/// Actions
			void aSet_target(void* const);

			void aGet_data(void* const);

			void aCall_data(void* const);
			///@}

		private:
			/// Current ControlKeyBoard used by the current ScriptSheet.
			static ControlKeyBoard* current;

			/// The sheet to which the keyboard is linked.
			ScriptSheet* sheet;

			/// Prime target id.
			uint primetarget;

			/// Cursor to the current target id;
			uint currenttarget;

			/// Current used key.
			uint currentkey;

			string data;

			/// List of availables maps between keys and actions.
			vector<EASMap> keymaps;

			/// List of all currents targets.
			vector<Element*> targets;
	};

#endif
