#ifndef ELEMENTACTIONINFORMER_HPP
#define ELEMENTACTIONINFORMER_HPP

	#include "ElementActions.hpp"
	#include "customtypes.hpp"

	/// Availables Event types.
	enum EventType
	{
		E_SET = 10000000,
		E_GET = 20000000,
		E_DO = 40000000,
		E_CALL = 80000000
	};

	/// Availables Action Names.
	enum ElementActionNames
	{
		A_POSITION = 1,
		A_MOVE,
		A_LOG,
		A_RUNNABLE_STATE
	};

	namespace ElementActionInformer
	{
		ElementAction getAction(uint const);
	}

#endif
