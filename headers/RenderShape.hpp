#ifndef RENDERSHAPE_HPP
#define RENDERSHAPE_HPP

	#include "Element.hpp"

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
			unsigned int getDataSize(void)

			///
			///
			///
			void setBufferId(GLuint);

		private:
			///
			///
			///
			bufferid;

	};

#endif
