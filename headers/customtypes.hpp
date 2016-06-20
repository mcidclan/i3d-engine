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

	template <typename T>
	union unfloat
	{
		T a;
		float b;
	};

#endif
