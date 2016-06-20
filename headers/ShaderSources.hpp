#ifndef SHADERSOURCES_HPP
#define SHADERSOURCES_HPP
	
	#include <vector>
	#include <iostream>
	#include <GL/glew.h>
	#include "customtypes.hpp"

	using namespace std;

	/// warning non-polymorphic
	class ShaderSources : public vector<GLchar const**>
	{
		public:
			///
			ShaderSources();

			///
			~ShaderSources();

			///
			GLuint getType(uint);
			
			///
			uint getLineNumber(uint);

			///
			void push(GLuint type, GLchar const**, uint const);

			///
			template <uint L>
			void push(GLuint type, GLchar const* (&source)[L])
			{
				this->push_back(source);
				this->types.push_back(type);
				this->linenumbers.push_back(L);
			}

		private:
			///
			vector<GLuint> types;

			///
			vector<uint> linenumbers;

	};

#endif
