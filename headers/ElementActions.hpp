#ifndef ELEMENTACTIONS_HPP
#define ELEMENTACTIONS_HPP

	class ElementActions
	{
		public:
			///
			/// Allow to trace debug message.
			///
			virtual void setLog(void* const);

			///
			/// Allow to read the state of the
			/// runnable associated to the current Element.
			///
			virtual void getRunnableState(void* const);
	};

	///
	/// Define the ElementAction type.
	///
	typedef void (ElementActions::*ElementAction)(void* const);

#endif
