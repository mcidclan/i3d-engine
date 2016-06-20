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
			///
			///
			GLuint bufferid;

	};

#endif
