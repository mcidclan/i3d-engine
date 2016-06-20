#ifndef UTILS_HPP
#define UTILS_HPP
	
	#include <stdio.h>
	#include <vector>

	using namespace std;

	namespace utils
	{
		///
		/// Allows to delete dynamics instances through a vector.
		///
		template <class T>
		void dynamicDelete(vector<T>& v)
		{
			unsigned int i;

			i = 0;
			while(i < v.size())
			{
				if(v[i] != NULL) delete v[i];
			}
			v.clear();
		}
	}

#endif
