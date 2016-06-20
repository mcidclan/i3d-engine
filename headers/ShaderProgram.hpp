#ifndef SHADERPROG_HPP
#define SHADERPROG_HPP

	#include <string>
	#include <vector>
	#include <stdexcept>

	#ifndef FLASCC
	#include <GL/glew.h>
	#else
	#include <GLES2/gl2.h>
	#endif

	using namespace std;

	class ShaderProgram
	{
		public:
			///
			/// Constructor.
			///
			ShaderProgram();

			///
			/// Destructor.
			///
			~ShaderProgram();

			///
			/// Must be called to be use.
			///
			void use(void);

			///
			/// Add a source (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
			///
			template <int L>
			void addSource(GLuint type, GLchar const* (&source)[L]);

		private:
			///
			/// Give the linking status.
			///
			bool linked;

			///
			/// Opengl shader program id
			///	associated to the current ShaderProgram.
			///
			GLuint program;
			
			///
			/// All shaders added to the current ShaderProgram.
			///
			vector<GLuint> shaders;
	};

	template <int L>
	void ShaderProgram::addSource(GLuint type, GLchar const* (&source)[L])
	{
		GLuint shader;
		GLint compiled;

		shader = glCreateShader(type);
		glShaderSource(shader, L, source, NULL);
		glCompileShader(shader);

		glAttachShader(this->program, shader);
		this->shaders.push_back(shader);
	}

#endif
