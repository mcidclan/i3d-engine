#ifndef EVENT_HPP
#define EVENT_HPP

	#include "Element.hpp"
	#include "ElementActionList.hpp"

	class Event
	{
		public:
			/// Constructor.
			Event();

			/// Destructor.
			~Event();

			/// Add a new requested action.
			void addAction(ElementAction const);

		private:
			/// The Source where the Event comes from.
			Element* source;

			/// All Actions requested by the Source.
			ElementActionList actionlist;

	};

#endif
