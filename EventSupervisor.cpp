#include "./headers/EventSupervisor.hpp"

/*
 * Constructor
 */
EventSupervisor::EventSupervisor()
{
	this.runnable = new Thread(EventSupervisor::run);
}

/*
 * Destructor
 */
EventSupervisor::~EventSupervisor()
{
}

/*
 * run
 */
bool EventSupervisor::run()
{
	
}
