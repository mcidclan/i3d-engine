#ifndef RENDERSHAPE_HPP
#define RENDERSHAPE_HPP

	#include "Element.hpp"
	#include "ShaderProgram.hpp"

	class RenderShape : public Element
	{
		public:
			///
			/// Constructor
			///
			RenderShape();

			///
			/// Destructor
			///
			~RenderShape();

			///
			///
			///
			void setShaderProgram(ShaderProgram* const);

			///
			///
			///
			void setBufferId(GLuint);

			///
			/// Draw the current RenderShape.
			///
			void draw(void);

			///
			///
			///
			virtual unsigned int getDataSize(void) = 0;

			///
			///
			///
			virtual GLfloat const* getData(void) = 0;

		private:
			///
			/// ProgramShader associated to the current RenderShape.
			///
			ShaderProgram* shaderprogram;

			///
			/// ProgramShader attributes pointers.
			///
			GLuint avertice;
			//

			///
			///
			///
			GLuint bufferid;

			///
			///
			///
			void initAttributes(void);

	};

#endif
