#ifndef ELEMENTACTIONINFORMER_HPP
#define ELEMENTACTIONINFORMER_HPP

	#include "ElementActions.hpp"
	#include "customtypes.hpp"

	/// Availables Event types.
	enum EventType
	{
		E_SET = 0x10000000,
		E_GET = 0x20000000,
		E_DO = 0x40000000,
		E_CALL = 0x80000000,
		E_CHECK = 0xF0000000
	};

	/// Parameter axis information.
	enum ParamAxis
	{
		P_X = '\1',
		P_Y = '\2',
		P_Z = '\4'
	};

	/// Availables Action Names.
	enum ElementActionNames
	{
		A_POSITION = 1,
		A_SCALE,
		A_MOVE,
		A_LOG,
		A_RUNNABLE_STATE
	};

	namespace ElementActionInformer
	{
		ElementAction getAction(uint const);
	}

#endif
