#include "Thread.hpp"

Thread::Thread(void (* runnable)(void))
{
	this->runnable = runnable;
}

Thread::~Thread()
{
}

void* Thread::run(void* current)
{
	/*bool runnablestate;

	while(true)
	{
		current->getRunnableState(&runnablestate);

		if(!runnablestate)
		{
			break;
		}
		current->runnable();
	}*/

	return NULL;
}
