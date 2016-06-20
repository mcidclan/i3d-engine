#ifndef SSDATABRIDGE_HPP
#define SSDATABRIDGE_HPP

	#include <stdlib.h>
	#include "Element.hpp"

	class SSDataBridge
	{
		public:
			/// Last added source Element.
			static Element* source;

			/// Current added target Element.
			static Element* target;
	};

#endif
