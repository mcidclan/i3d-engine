#ifndef SCRIPTSHEET_HPP
#define SCRIPTSHEET_HPP

	#include "RenderingManager.hpp"

	class ScriptSheet : public RenderingManager
	{
		public:
			///
			///
			///
			ScriptSheet(void(*)(void));

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
			vector<ScriptSheet*>* getSheets(void);

			///
			///
			///
			void addNewScriptSheet(void(*)(void),
			vector<unsigned int>* const);
			
			///
			///
			///
			ScriptSheet* getScriptSheet(unsigned int const,
			vector<unsigned int>* const) const;

		private:
			///
			///
			///
			bool initialized;

			///
			///
			///
			vector<ScriptSheet*> sheets;

			///
			///
			///
			void(* init)(void);

	};

#endif

