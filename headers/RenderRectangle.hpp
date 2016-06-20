#ifndef RENDERRECTANGLE_HPP
#define RENDERRECTANGLE_HPP

	#include "RenderShape.hpp"

	class RenderRectangle : public RenderShape
	{
		public:
			///
			/// Constructor.
			///
			RenderRectangle();

			///
			/// Destructor.
			///
			~RenderRectangle();

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
