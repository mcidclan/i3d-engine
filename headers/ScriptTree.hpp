#ifndef SCRIPTTREE_HPP
#define SCRIPTTREE_HPP

	#include "ScriptSheet.hpp"

	class ScriptTree
	{
		public:
			///
			/// Constructor.
			///
			ScriptTree();

			///
			/// Destructor.
			///
			~ScriptTree();

			///
			/// Set the current ScriptSheet by passing
			/// a vector which describe the path.
			///
			void setCurrentScriptSheet(vector<unsigned int>* const);

			///
			///
			///
			void addNewScriptSheet(void(* const)(void),
			vector<unsigned int>* const);

			///
			///
			///
			static void draw(void);

		private:
			///  
			///	Allows access to the current instance,
			/// from static functions.
			///
			static ScriptTree* current;

			///
			/// The root of the ScriptSheet tree.
			///
			ScriptSheet* root;

			///
			/// Current ScriptSheet.
			///
			ScriptSheet* currentsheet;

	};

#endif




