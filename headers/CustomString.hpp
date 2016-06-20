#ifndef CUSTOMSTRING_HPP
#define CUSTOMSTRING_HPP

	#include "customtypes.hpp"

	class CustomString
	{
		public:
			/// Contructor.
			CustomString(const char* const content);

			/// Destructor.
			~CustomString();

			///
			string find_part_after_last_of(const char* const) const;

			///
			char const* c_str(void) const;

		private:
			///
			string* content;
	};

#endif
