#ifndef UTILS_HPP
#define UTILS_HPP
	
	#include "customtypes.hpp"
	#include "ShaderProgram.hpp"

	namespace utils
	{
		/// Allows to load a bmp24 to opengl.
		GLuint loadBmp24(const char*);

		/// Allows to load a png32 to opengl.
		GLuint loadPng32(const char*);

		/// Allows to create an Opengl mimapped texture from a specific buffer.
		GLuint getMipMap(uchar* const, uint const, uint const, GLint const);

		///
		void utf8Adjuster(string& data);

		/// Allows to delete dynamics instances through a vector.
		template <class T>
		void dynamicDelete(vector<T>& v, bool isarray = false)
		{
			unsigned int i;

			i = 0;
			while(i < v.size())
			{
				if(v[i] != NULL)
				{
					if(isarray)
					{
						delete [] v[i];
					} else delete v[i];
				}
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

		/// Allows to get a specific type value from string.
		template<typename T>
		T readFrom(string const& in)
		{
			T out;
			istringstream tmp(in);
			tmp >> out;
			return out;
		}

		/// Allows to get the size of an array.
		template <typename T, unsigned int N>
		inline unsigned int count(const T(&)[N])
		{
			return N;
		}

	}

#endif
