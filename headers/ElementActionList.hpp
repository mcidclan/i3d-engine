#ifndef ELEMENTACTIONLIST_HPP
#define ELEMENTACTIONLIST_HPP

    #include <vector>
	#include "ElementActions.hpp"

    using namespace std;

	/// warning non-polymorphic
	class ElementActionList : public vector<ElementAction>
	{
		public:
			/// Constructor.
			ElementActionList();

			/// Destructor.
			~ElementActionList();

		private:

	};

#endif
