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

			///
			///
			///
			unsigned int getDataSize(void);

			///
			///
			///
			GLfloat const* getData(void);

		private:
			///
			/// Internal data.
			///
			static GLfloat const data[];
	};

#endif
