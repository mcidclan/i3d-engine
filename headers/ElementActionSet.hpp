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

			/// Allows to set the action and param informations.
			void operator()(uint const, void* const);

			/// Allows to add a param value.
			template<typename T>
			ElementActionSet& operator()(T);

			/// Allows to get the parameter data.
			void* operator()(void);

			/// Return the action reference.
			uint getAction(void) const;

			/// Return the action parameter.
			void* getParam(void) const;

			///	Allows to get a specific unit of parameter.
			template <typename T2 = uint, typename T1>
			static T2 u(T1 const in);

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

	template <typename T2, typename T1>
	T2 ElementActionSet::u(T1 const in)
	{
		union un<T1, T2> out;
		out.a = in;
		return out.b;
	}

#endif
