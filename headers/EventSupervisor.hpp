#ifndef EVENTSUPERVISOR_HPP
#define EVENTSUPERVISOR_HPP

	#include "Thread.hpp"
	#include "EventStack.hpp"

	class EventSupervisor : private Element
	{
		public:
			///
			/// Constructor.
			///
			EventSupervisor();

			///
			/// Destructor.
			///
			~EventSupervisor();

            ///
			/// Core process of the supevisor.
			/// This is where all Events are processed.
			///
			static void* run(void* data);

		private:
			///
			/// Stack used as the Event queue.
			///
			EventStack eventstack;

			///
			/// Pointer to the runnable Thread.
			///
			Thread* runnable;

			///
			/// Pointer on the current supervisor,
			/// to be used from the core process.
			///
			static EventSupervisor* current;
	};

#endif
