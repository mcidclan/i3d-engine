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

			/// Destructor.
			~ScriptSheet();

			/// Leave the current ScriptSheet by calling the clean process.
			void leave(void);

			/// Call the draw process from the current RenderingManager.
			void draw(void);

			///
			void addNewScriptSheet(Script const, vuint* const tie);
			
			/// Set the parent ScriptSheet.
			void setParent(ScriptSheet* const);

			/// Set the persistence state.
			void setLastingState(bool);

			/// Return the parent ScriptSheet.
			ScriptSheet* getParent(void) const;

			///
			ScriptSheet* getScriptSheet(uint const, vuint* const tie);

			/// Returns the children ScriptSheet.
			vector<ScriptSheet*>* getSheets(void);

			/// Get the persistence state.
			bool getLastingState(void);

		private:
			/// A flag to know if the init function was called.
			bool initialized;

			/// Allows to know if it's persistant or not.
			bool lasting;

			/// The parent ScriptSheet.
			ScriptSheet* parent;

			/// Children of the current ScriptSheet. 
			vector<ScriptSheet*> sheets;

			/// Init function.
			Script init;

			/// Init the attributes common to the both contructors.
			void initAttributes(void);

	};

#endif