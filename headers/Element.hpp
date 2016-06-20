#ifndef ELEMENT_HPP
#define ELEMENT_HPP

	#include "ElementActions.hpp"

	class Element : public ElementActions
	{
		public:
			///
			/// Constructor.
			///
			Element();

			///
			/// Destructor.
			///
			~Element();

			void getRunnableState(void* const);

		private:
			///
			/// Give the runnable state,
			/// in case it exist.
			///
			bool runnablestate;
	};

#endif
