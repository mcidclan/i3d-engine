#ifndef SCRIPTTREE_HPP
#define SCRIPTTREE_HPP

	#include "ScriptSheet.hpp"

	class ScriptTree : public Element
	{
		public:
			/// Constructor.
			ScriptTree();

			/// Destructor.
			~ScriptTree();

			///
			static void draw(void);

			///
			void addNewScriptSheet(Script const);

			/// Set the current ScriptSheet by passing
			/// a vector which describe the path.
			void setCurrentScriptSheet(uint const);

			///
			template <uint D>
			void setCurrentTie(uint (&)[D]);

			/// Action.
			void doMove(void*);

		private:
			///	Allows access to the current instance,
			/// from static functions.
			static ScriptTree* current;

			/// The root of the ScriptSheet tree.
			ScriptSheet* root;

			/// Current ScriptSheet.
			ScriptSheet* currentsheet;

			/// Current tie information.
			uint* tie;

			/// Current tie information.
			uint tiedepth;

			/// Allows to switch properly to an other ScriptSheet.
			void switchSheet(ScriptSheet* const);

			///@{
			/// Allow to move through the ScriptTree.
			void moveToUp(void);

			void moveToDown(void);

			void moveToLeft(void);

			void moveToRight(void);
			///@}

	};

	/// Set the current tie on which we have to work.
	template <uint D>
	void ScriptTree::setCurrentTie(uint (&tie)[D])
	{
		this->tie = tie;
		this->tiedepth = D;
	}

#endif
