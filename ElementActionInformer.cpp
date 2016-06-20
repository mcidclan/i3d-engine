#include "ElementActionInformer.hpp"

ElementAction ElementActionInformer::getAction(uint const action)
{
	switch(action)
	{
		case (E_SET | A_POSITION):
			return NULL;
		
		case (E_SET | A_LOG):
			return &ElementActions::aSet_log;

		case (E_SET | A_TARGET):
			return &ElementActions::aSet_target;

		case (E_SET | A_SCALE):
			return &ElementActions::aSet_scale;

		case (E_SET | A_KEYMAPID):
			return &ElementActions::aSet_KeyMapId;

		case (E_GET | A_RUNNABLE_STATE):
			return &ElementActions::aGet_runnableState;

		case (E_DO | A_MOVE):
			return &ElementActions::aDo_move;
	}

	return NULL;
}
