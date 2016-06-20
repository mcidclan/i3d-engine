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

			/// Allows to move the Element or through it.
			virtual void aSet_move(void* const);

			/// Allows to scale the current Element.
			virtual void aSet_scale(void* const);

			/// Allows to set the position of the current Element.
			virtual void aSet_position(void* const);

			///
			virtual void aSet_KeyMapId(void* const);

			///
			virtual void aSet_write(void* const);

			///
			virtual void aSet_erase(void* const);


			/// Allows to read the state of the current runnable.
			virtual void aGet_runnableState(void* const);

			/// Allows to call the current keyboard data.
			virtual void aGet_data(void* const);


			/// Allows to move the Element or through it.
			virtual void aDo_move(void* const);

			virtual void aDo_write(void* const);


			/// Allows to call the current keyboard data.
			virtual void aCall_data(void* const);

	};

	/// Define the ElementAction type.
	typedef void (ElementActions::*ElementAction)(void* const);

#endif
