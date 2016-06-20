#ifndef RENDERTRIANGLE_HPP
#define RENDERTRIANGLE_HPP

	#include "RenderShape.hpp"

	class RenderTriangle : public RenderShape
	{
		public:
			///
			/// Constructor.
			///
			RenderTriangle();

			///
			/// Destructor.
			///
			~RenderTriangle();

		private:
			///
			/// Internal data.
			///
			static const GLfloat data[]
			{
				-1.0f, -1.0f, 0.0f,
				1.0f, -1.0f, 0.0f,
				0.0f, 1.0f, 0.0f
			};
	};

#endif
