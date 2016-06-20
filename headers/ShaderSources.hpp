#ifndef SHADERSOURCES_HPP
#define SHADERSOURCES_HPP
	
	#include <vector>
	#include <iostream>
	#include <GL/glew.h>

	using namespace std;

	class ShaderSources : public vector<GLchar const**>
	{
		public:
			///
			///
			///
			ShaderSources();

			///
			///
			///
			~ShaderSources();

			///
			///
			///
			GLuint getType(unsigned int);
			
			///
			///
			///
			unsigned int getLineNumber(unsigned int);

			///
			///
			///
			//GLchar const** operator[](unsigned int);

			///
			///
			///
			template <int L>
			void push(GLuint type, GLchar const* (&source)[L])
			{
				this->push_back(source);
				this->types.push_back(type);
				this->linenumbers.push_back(L);
			}

		private:
			///
			///
			///
			vector<GLuint> types;

			///
			///
			///
			vector<unsigned int> linenumbers;

	};

#endif
