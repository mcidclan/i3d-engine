#include "ElementActionInformer.hpp"

ElementAction ElementActionInformer::getAction(uint const action)
{
	switch(action)
	{
		case (E_SET | A_POSITION) : return NULL;
		case (E_SET | A_LOG) : return &ElementActions::setLog;

		case (E_GET | A_RUNNABLE_STATE) : return NULL;

		case (E_DO | A_MOVE) : return NULL;
		case (E_DO | A_SCALE) : return &ElementActions::doScale;
	}

	return NULL;
}
