#ifndef ElEMENTACTIONSET_HPP
#define ELEMENTACTIONSET_HPP

	#include "customtypes.hpp"

	class ElementActionSet
	{
		public:
			/// Default contructor.
			ElementActionSet();

			/// Destructor.
			~ElementActionSet();

			/// Allows to set the action and param values.
			void operator()(uint const, void* const);

			/// Return the action reference.
			uint getAction(void) const;

			/// Return the action parameter.
			void* getParam(void) const;

			///	Allows to get the parameter data.
			template <typename T = float>
			static void* p(uint const psize, ...);

			///	Allows to get a specific unit of parameter.
			template <typename T>
			static float u(T const in);

		private:
			/// Action parameter.
			void* param;

			/// Action reference.
			uint action;
	};

	typedef ElementActionSet eas;

	typedef ElementActionSet EAS;

	template <typename T>
	void* ElementActionSet::p(uint const psize, ...)
	{
		uint i;
		T* param;
		va_list plist;

		i = 0;
		param = new T[psize];

		va_start(plist, psize);

		while(i < psize)
		{
			param[i] = va_arg(plist, T);
			i++;
		}

		return (void*)param;
	}

	template <typename T>
	float ElementActionSet::u(T const in)
	{
		union unfloat out;
		out.a = in;
		return out.b;
	}

#endif
