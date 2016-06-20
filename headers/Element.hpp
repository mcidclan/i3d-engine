#ifndef ELEMENT_HPP
#define ELEMENT_HPP

	#include "ElementActionInformer.hpp"

	class Element : public ElementActions
	{
		public:
			/// Constructor.
			Element();

			/// Destructor.
			~Element();

			///
			uint getKeyMapId(void) const;

			///@{
			/// Availables ElementActions.
			void aSet_KeyMapId(void* const);

			void aGet_runnableState(void* const);
			///@}

		private:
			/// Give the runnable state,
			/// in case it exist.
			bool runnablestate;

			///
			uint keymapid;
	};

#endif
