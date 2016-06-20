#ifndef EVENT_HPP
#define EVENT_HPP

	#include "utils.hpp"
	#include "Element.hpp"
	#include "ElementActionList.hpp"
	#include "ElementActionInformer.hpp"

	class Event
	{
		public:
			/// Constructor.
			Event();

			/// Destructor.
			~Event();

			///@{
			/// Add a new requested action.
			void addAction(ElementAction const);

			void addAction(uint const);
			///@}

			/// Add a new param memory pointer.
			void addParam(void* const);
			
			/// Set the current source.
			void setSource(Element* const);
			
			/// Set the current target.
			void setTarget(Element* const);

			///
			Element* getSource(void);

			///
			Element* getTarget(void);

			///
			void process(void);

		private:
			/// The source where the Event comes from.
			Element* source;

			/// The target to which the Event is sent.
			Element* target;

			/// All Actions requested by the Source.
			ElementActionList actionlist;

			/// Parameters applied to the actionlist.
			vector<void*> paramlist;

	};

#endif
