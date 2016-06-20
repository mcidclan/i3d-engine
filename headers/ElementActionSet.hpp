#ifndef ElEMENTACTIONSET_HPP
#define ELEMENTACTIONSET_HPP

	#include "customtypes.hpp"

	class ElementActionSet
	{
		public:
			///@{
			///contructors.
			ElementActionSet();

			template <typename T>
			ElementActionSet(T);
			///@}

			/// Destructor.
			~ElementActionSet();

			/// Allows to set the action and param values.
			void operator()(uint const, void* const);

			///
			template<typename T>
			ElementActionSet& operator()(T);

			/// Allows to get the parameter data.
			void* operator()(void);

			/// Return the action reference.
			uint getAction(void) const;

			/// Return the action parameter.
			void* getParam(void) const;

			///	Allows to get a specific unit of parameter.
			template <typename T>
			static uint u(T const in);

		private:
			/// Action parameter.
			void* param;

			/// Action reference.
			uint action;

			///
			vector<uint> vparam;
	};

	typedef ElementActionSet eas;

	typedef ElementActionSet EAS;

	template <typename T>
	ElementActionSet::ElementActionSet(T v)
	{
		(*this)(v);
	}

	template<typename T>
	ElementActionSet& ElementActionSet::operator()(T v)
	{
		this->vparam.push_back(u(v));
		return *this;
	}

	template <typename T>
	uint ElementActionSet::u(T const in)
	{
		union un<T, uint> out;
		out.a = in;
		return out.b;
	}

#endif
