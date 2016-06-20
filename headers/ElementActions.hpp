#ifndef ELEMENTACTIONS_HPP
#define ELEMENTACTIONS_HPP

	/// Defines all actions that can be called from an Event.
	class ElementActions
	{
		public:
			/// Allows to trace debug message.
			virtual void setLog(void* const);

			/// Allows to read the state of the
			/// runnable associated to the current Element.
			virtual void getRunnableState(void* const);

			/// Allows to move the Element or through it.
			virtual void doMove(void* const);

			/// Allows to scale the current Element.
			virtual void doScale(void* const);
	};

	/// Define the ElementAction type.
	typedef void (ElementActions::*ElementAction)(void* const);

#endif
