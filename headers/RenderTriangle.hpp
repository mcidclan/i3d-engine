#ifndef RENDERTRIANGLE_HPP
#define RENDERTRIANGLE_HPP

	#include "RenderShape.hpp"

	class RenderTriangle : public RenderShape
	{
		public:
			/// Constructor.
			RenderTriangle();

			/// Destructor.
			~RenderTriangle();

			///
			unsigned int getDataSize(BufferType) const;

			///
			GLfloat const* getData(BufferType) const;

		private:
			/// Internal indices data.
			static GLuint const indices[];

			/// Internal coordinates data.
			static GLfloat const coordinates[];

	};

#endif
