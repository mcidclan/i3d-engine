#ifndef ELEMENTACTIONS_HPP
#define ELEMENTACTIONS_HPP

	/// Defines all actions that can be called from an Event.
	class ElementActions
	{
		public:
			/// Allows to trace debug message.
			virtual void aSet_log(void* const);

			/// Allows to set a specific target.
			virtual void aSet_target(void* const);

			/// Allows to scale the current Element.
			virtual void aSet_scale(void* const);

			///
			virtual void aSet_KeyMapId(void* const);

			/// Allows to read the state of the
			/// runnable associated to the current Element.
			virtual void aGet_runnableState(void* const);

			/// Allows to move the Element or through it.
			virtual void aDo_move(void* const);

	};

	/// Define the ElementAction type.
	typedef void (ElementActions::*ElementAction)(void* const);

#endif
