#ifndef ELEMENTACTIONLIST_HPP
#define ELEMENTACTIONLIST_HPP

    #include <vector>
	#include "ElementActions.hpp"

    using namespace std;

	class ElementActionList : public vector<ElementAction>
	{
		public:
			///
			/// Constructor.
			///
			ElementActionList();

			///
			/// Destructor.
			///
			~ElementActionList();

		private:

	};

#endif
