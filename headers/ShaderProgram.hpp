#ifndef SHADERPROG_HPP
#define SHADERPROG_HPP

	#include "ShaderSources.hpp"

	class ShaderProgram
	{
		public:
			/// Constructor.
			ShaderProgram();

			/// Destructor.
			~ShaderProgram();

			///
			void link(void);

			/// Must be called to be use.
			void use(void);

			///
			GLuint getId(void);

			/// Add a source (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
			void addSource(GLuint type, GLchar const**, unsigned int);

		private:
			/// Give the linking status.
			bool linked;

			/// Opengl shader program id
			///	associated to the current ShaderProgram.
			GLuint program;
			
			/// All shaders added to the current ShaderProgram.
			vector<GLuint> shaders;
	};

#endif
