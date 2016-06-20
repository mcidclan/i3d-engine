#ifndef SHADER_HPP
#define SHADER_HPP

	#include <GL/glew.h>
	#include "utils.hpp"

	class Shader
	{
		public:
			///
			static GLchar const* vertex[];

			///
			static GLchar const* fragment[];

			///
			static uint vsize(void);

			///
			static uint fsize(void);

	};

#endif
