#ifndef ELEMENTACTIONS_HPP
#define ELEMENTACTIONS_HPP

	class ElementActions
	{
		public:
			///
			/// Allow to trace debug message.
			///
			virtual void log(void* const);

		private:
	};

	typedef void (ElementActions::*ElementAction)(void* const);

#endif
