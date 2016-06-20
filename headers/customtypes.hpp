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

#endif
