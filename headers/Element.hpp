#ifndef ELEMENT_HPP
#define ELEMENT_HPP

	#include "utils.hpp"
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

			/// Return the group of the current element. 
			uint getGroup(void) const;

			///@{
			/// Availables ElementActions.
			void aSet_KeyMapId(void* const);

			void aGet_runnableState(void* const);
			///@}

		protected:
			/// Element group.
			uint group;

		private:
			/// Give the runnable state,
			/// in case it exist.
			bool runnablestate;

			///
			uint keymapid;

	};

#endif
