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
			unsigned int getDataSize(void) const;

			///
			GLfloat const* getData(void) const;

		private:
			/// Internal indices data.
			static GLuint const indices[];

			/// Internal coordinates data.
			static GLfloat const coordinates[];

	};

#endif
