#ifndef RENDERSHAPE_HPP
#define RENDERSHAPE_HPP

	#include "math.hpp"
	#include "Element.hpp"
	#include "ShaderProgram.hpp"
	#include "constants.hpp"

	#include "texture.hpp"

	enum BufferType
	{
		V_BUFFER = 0,
		UV_BUFFER,
		BUFFER_NUMBER
	};

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
			void setBufferId(BufferType const, GLuint const);

			/// Draw the current RenderShape.
			void draw(void);

			///
			virtual unsigned int getDataSize(BufferType) const = 0;

			///
			virtual GLfloat const* getData(BufferType) const = 0;

			///@{
			/// Actions.
			void setLog(void* const);

			void doScale(void* const);
			///@}

		protected:
			/// Number of vertices to be rendered.
			uint vertexnumber;

			/// Pointer to the indices data.
			uint* vertexindices;

		private:
			/// Opengl projection matrix.
			static GLfloat pmatrix[];

			/// Current shape texture id.
			GLuint textureid;

			/// Allows to know if the shape is textured.
			bool textured;

			/// Opengl transform matrix.
			GLfloat* tmatrix;

			/// Opengl rotate matrix.
			GLfloat* rmatrix;

			/// ProgramShader associated to the current RenderShape.
			ShaderProgram* shaderprogram;

			///@{
			/// ProgramShader attributes pointers.
			GLuint avertex;

			GLuint auvcoord;
			///@}

			/// Texture sample id.
			GLuint utsampler;

			/// Projection matrix id.
			GLint upmatrix;

			/// Transform matrix id.
			GLint utmatrix;

			/// Rotate matrix id.
			GLint urmatrix;

			///
			GLuint bufferid[BUFFER_NUMBER];

			/// Init all shader variable locations.
			void initShaderVariableLocations(void);

			/// Update the uniform shader variables.
			void updateUniformShaderVariables(void);

	};

#endif
