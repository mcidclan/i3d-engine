#ifndef EVENTSUPERVISOR_HPP
#define EVENTSUPERVISOR_HPP

	#include "Thread.hpp"
	#include "EventStack.hpp"
	#include "SSDataBridge.hpp"

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

		protected:
			/// Last added source Element.
			Element* lastnewsource;
	
			/// Current added target Element.
			Element* lastnewtarget;

		private:
			/// Pointer to the runnable Thread.
			Thread* runnable;

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
