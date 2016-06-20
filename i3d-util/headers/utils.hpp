#ifndef UTILS_HPP
#define UTILS_HPP
	
	//#include "customtypes.hpp"
	#include "ShaderProgram.hpp"

	namespace utils
	{
		/// Allows to load a bmp24 to opengl.
		GLuint loadBmp24(const char*);

		/// Allows to delete dynamics instances through a vector.
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

		/// Allows to delete dynamics instances through a map.
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

		///
		template <typename T>
		void vectorFrom(vector<T>& out, T* const in, uint const size)
		{
			uint i;

			i = 0;
			while(i < size)
			{
				out.push_back(in[i]);
				i++;
			}
		}

		/// Allows to get the size of an array.
		template <typename T, unsigned int N>
		inline unsigned int count(const T(&)[N])
		{
			return N;
		}

		/// Copy a specific type to float.
		template <typename T>
		float alter(T const in)
		{
			union unfloat out;
			out.a = in;
			return out.b;
		}
	}

#endif
