#ifndef UTILS_HPP
#define UTILS_HPP
	
	#include <map>
	#include <vector>
	#include <iostream>

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

		///
		/// Allows to delete dynamics instances through a map.
		///
		template <typename T1, class T2>
		void dynamicDelete(map<T1, T2>& m)
		{
			typename map<T1, T2>::const_iterator a, b;

			a = m.begin();
			b = m.end();

			while(a != b)
			{
				delete a->second;
				a++;
			}
			m.clear();
		}
	}

#endif
