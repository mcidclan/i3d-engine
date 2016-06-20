#ifndef RENDERSHAPE_HPP
#define RENDERSHAPE_HPP

	#include "math.hpp"
	#include "Element.hpp"
	#include "ShaderProgram.hpp"

	class RenderShape : public Element
	{
		public:
			/// Constructor
			RenderShape();

			/// Destructor
			~RenderShape();

			///
			void setShaderProgram(ShaderProgram* const);

			///
			void setBufferId(GLuint);

			/// Draw the current RenderShape.
			void draw(void);

			///
			virtual unsigned int getDataSize(void) = 0;

			///
			virtual GLfloat const* getData(void) = 0;

		private:
			/// Opengl projection matrix.
			//static GLfloat pmatrix[];

			/// Opengl view matrix.
			GLfloat* vmatrix;

			/// ProgramShader associated to the current RenderShape.
			ShaderProgram* shaderprogram;

			/// ProgramShader attributes pointers.
			GLuint avertice;

			///
			//GLint upmatrix;

			///
			//GLint uvmatrix;

			///
			GLuint bufferid;

			/// Init all shader variable locations.
			void initShaderVariableLocations(void);

			/// Init the variables having a default value.
			void initShaderVariables(void);

	};

#endif
