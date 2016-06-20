#ifndef CUSTOMTYPES_HPP
#define CUSTOMTYPES_HPP

	#include <map>
	#include <string>
	#include <vector>
	#include <cstdio>
	#include <cstdarg>
	#include <cstring>
	#include <iostream>

	#include <malloc.h>

	using namespace std;

	typedef unsigned int uint;
	typedef unsigned char uchar;
	typedef vector<unsigned int> vuint;

	template <typename T1, typename T2>
	union un
	{
		T1 a;
		T2 b;
	};

	template <typename T>
	class vec3
	{
		public:
			///
			T x, y, z;

			///
			vec3()
			{
				this->init(0.0f, 0.0f, 0.0f);
			}

			///
			vec3(T const x, T const y, T const z)
			{
				this->init(x, y, z);
			}

			///
			void set(T const x, T const y, T const z)
			{
				this->init(x, y, z);
			}

			///
			void add(T const x, T const y, T const z)
			{
				this->x += x;
				this->y += y;
				this->z += z;
			}
			
		private:
			///
			void init(T const x, T const y, T const z)
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}
	};

#endif
