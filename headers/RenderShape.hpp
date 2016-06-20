#ifndef RENDERSHAPE_HPP
#define RENDERSHAPE_HPP

	#include "math.hpp"
	#include "Element.hpp"
	#include "ShaderProgram.hpp"
	#include "constants.hpp"

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

			///
			void setTextureId(GLint const);

			/// Draw the current RenderShape.
			void draw(void);

			///
			virtual void drawGui(void);

			///
			virtual unsigned int getDataSize(BufferType) const = 0;

			///
			virtual GLfloat const* getData(BufferType) const = 0;

			///@{
			/// Actions.
			void aSet_position(void* const data);

			void aSet_scale(void* const);

			void aSet_log(void* const);
			///@}

		protected:
			/// Number of vertices to be rendered.
			uint vertexnumber;

			/// Pointer to the indices data.
			uint* vertexindices;

			/// Opengl scale and translate matrix.
			GLfloat* tmatrix;

			/// Opengl rotate matrix.
			GLfloat* rmatrix;

		private:
			/// Opengl projection matrix.
			static GLfloat pmatrix[];

			/// Current shape texture id.
			GLint textureid;

			///@{
			/// Allows to know if the shape is textured.
			bool sampled;

			bool textured;
			///@}

			/// ProgramShader associated to the current RenderShape.
			ShaderProgram* shaderprogram;

			///@{
			/// ProgramShader attributes pointers.
			GLuint avertex;

			GLuint auvcoord;
			///@}

			/// Texture 'sampling state' id.
			GLuint usampled;

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
