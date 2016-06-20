#ifndef EVENTSTACK_HPP
#define EVENTSTACK_HPP

	#include <vector>
	#include "Event.hpp"

	using namespace std;

	enum EventStackType
	{
		ES_TRANSIENT = 0,
		ES_PERSISTENT
	};

	class EventStack : public vector<Event*>
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
