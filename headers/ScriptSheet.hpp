#ifndef SCRIPTSHEET_HPP
#define SCRIPTSHEET_HPP

	#include "RenderingManager.hpp"

	class ScriptSheet;

	typedef void(* Script)(ScriptSheet* const);

	class ScriptSheet : public RenderingManager
	{
		public:
			/// Constructor.
			ScriptSheet(Script);

			/// Call empty RenderingManager constructor.
			ScriptSheet();

			///
			~ScriptSheet();

			///
			void leave(void);

			///
			void draw(void);

			///
			void addNewScriptSheet(Script const, vuint* const tie);
			
			///
			void setLastingState(bool);

			///
			ScriptSheet* getScriptSheet(uint const, vuint* const tie);

			///
			vector<ScriptSheet*>* getSheets(void);

			///
			bool getLastingState(void);

		private:
			/// A flag to know if the init function was called.
			bool initialized;

			///
			bool lasting;

			/// Children of the current ScriptSheet. 
			vector<ScriptSheet*> sheets;

			/// Init function.
			Script init;

	};

#endif
