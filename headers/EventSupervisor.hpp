#ifndef EVENTSUPERVISOR_HPP
#define EVENTSUPERVISOR_HPP

	#include "Thread.hpp"
	#include "EventStack.hpp"

	class EventSupervisor : private Element
	{
		public:
			/// Stack used as the Event queue.
			EventStack* eventstack[2];

			/// Constructor.
			EventSupervisor();

			/// Destructor.
			~EventSupervisor();

			///
			void addNewEvent(uint const, void* const);

			///
			void processingEvents(void);

		private:
			/// Pointer to the runnable Thread.
			Thread* runnable;

			/// Current source Element.
			Element* currentsource;
	
			/// Current target Element.
			Element* currenttarget;

			///
			void addTransientEvent(Event* const);

			///
			void addPersistentEvent(Event* const);

			///@{
			/// Core process of the supevisor.
			/// This is where all Events are processed.
			void processingTransientEvents(void);

			void processingPersistentEvents(void);
			///@}

	};

#endif
