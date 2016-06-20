#include "ElementActionInformer.hpp"

ElementAction EAI::getAction(uint const action)
{
	switch(action)
	{
		// Action Set.
		case (E_SET | A_POSITION):
			return &ElementActions::aSet_position;
		
		case (E_SET | A_LOG):
			return &ElementActions::aSet_log;

		case (E_SET | A_TARGET):
			return &ElementActions::aSet_target;

		case (E_SET | A_MOVE):
			return &ElementActions::aSet_move;

		case (E_SET | A_SCALE):
			return &ElementActions::aSet_scale;

		case (E_SET | A_KEYMAPID):
			return &ElementActions::aSet_KeyMapId;

		case (E_SET | A_WRITE):
			return &ElementActions::aSet_write;

		case (E_SET | A_ERASE):
			return &ElementActions::aSet_erase;

		// Action Get.
		case (E_GET | A_RUNNABLE_STATE):
			return &ElementActions::aGet_runnableState;

		case (E_GET | A_DATA):
			return &ElementActions::aGet_data;

		// Action Do.
		case (E_DO | A_MOVE):
			return &ElementActions::aDo_move;

		case (E_DO | A_WRITE):
			return &ElementActions::aDo_write;

		// Action Call.
		case (E_CALL | A_DATA):
			return &ElementActions::aCall_data;
	}

	return NULL;
}

void EAI::setTransformation(void* const src, vec3<float>& dest)
{
	uchar* const isrc = (uchar*)src;
	float* const vsrc = (float*)src;

	if(isrc[0] & P_X) dest.x = vsrc[1];
	if(isrc[0] & P_Y) dest.y = vsrc[2];
	if(isrc[0] & P_Z) dest.z = vsrc[3];
}

void EAI::setTransformation(void* const src, float* const dest,
uchar const a, uchar const b, uchar const c)
{
	uchar* const isrc = (uchar*)src;
	float* const vsrc = (float*)src;

	if(isrc[0] & P_X) dest[a] = vsrc[1];
	if(isrc[0] & P_Y) dest[b] = vsrc[2];
	if(isrc[0] & P_Z) dest[c] = vsrc[3];
}

