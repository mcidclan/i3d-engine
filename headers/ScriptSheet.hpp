#ifndef SCRIPTSHEET_HPP
#define SCRIPTSHEET_HPP

	#include "RenderingManager.hpp"

	class ScriptSheet;

	typedef void(* Script)(ScriptSheet* const);

	class ScriptSheet : public RenderingManager
	{
		public:
			///
			/// Constructor.
			///
			ScriptSheet(Script);

			///
			/// Call empty base constructor.
			///
			ScriptSheet();

			///
			///
			///
			~ScriptSheet();

			///
			///
			///
			void draw(void);

			///
			///
			///
			void addNewScriptSheet(Script const, vuint* const tie);
			
			///
			///
			///
			ScriptSheet* getScriptSheet(uint const, vuint* const tie);

			///
			///
			///
			vector<ScriptSheet*>* getSheets(void);

		private:
			///
			/// A flag to know if the init function was called.
			///
			bool initialized;

			///
			/// Children of the current ScriptSheet. 
			///
			vector<ScriptSheet*> sheets;

			///
			/// Init function.
			///
			Script init;

	};

#endif

/*
	move
	in create
	out delete
	script [OK]
*/
