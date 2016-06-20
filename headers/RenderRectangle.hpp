#ifndef RENDERRECTANGLE_HPP
#define RENDERRECTANGLE_HPP

	#include "RenderShape.hpp"

	class RenderRectangle : public RenderShape
	{
		public:
			/// Constructor.
			RenderRectangle();

			/// Destructor.
			~RenderRectangle();

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
