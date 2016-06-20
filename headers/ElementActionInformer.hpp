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
		A_KEYMAPID,
		A_TARGET,
		A_SCALE,
		A_MOVE,
		A_LOG,
		A_RUNNABLE_STATE
	};

	///
	enum ElementGroup
	{
		EG_UNDEFINED = 0,
		EG_CONTROL,
		EG_GUI
	};

	///
	enum ElementType
	{
		CTRL_KEYBOARD = 0,
		CTRL_MOUSE
	};

	class ElementActionInformer
	{
		public:
			///
			static ElementAction getAction(uint const);

			///
			static void setTransformation(void* const, vec3<float>&);

			///
			static void setTransformation(void* const, float* const,
			uchar const, uchar const, uchar const);

	};

	typedef ElementActionInformer EAI;

#endif
