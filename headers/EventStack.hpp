#ifndef EVENTSTACK_HPP
#define EVENTSTACK_HPP

	#include <vector>
	#include "Event.hpp"

	using namespace std;

	class EventStack : vector<Event*>
	{
		public:
			/// Constructor.
			EventStack();

			/// Destructor.
			~EventStack();

			/// Add a new Event at the top of the Stack.
			void push(Event* const);

			/// Remove an Event from the top of the Stack.
			void pop(Event*&);

		private:

	};

#endif
