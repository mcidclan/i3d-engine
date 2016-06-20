#ifndef RENDERTEXT_HPP
#define RENDERTEXT_HPP
	
	#include <map>
	#include <string>
	#include <GL/glew.h>
	#include <FTGL/ftgl.h>
	#include "Element.hpp"
	
	using namespace std;

	class RenderText : public Element
	{
		public:
			/// Constructor.
			RenderText(FTGLPixmapFont* const);

			/// Destructor.
			~RenderText();

			/// Set the text size.
			void setSize(unsigned int const);

			/// Set the text value.
			void setText(string const);

			/// Draw the text.
			void draw(void);

			///@{
			/// Actions.
			void aSet_position(void* const);
			///@}

		protected:
			/// Text value.
			string text;

			/// Text size.
			unsigned int size;

			///@{
			/// Current RenderText position.
			float x;

			float y;

			float z;
			///@}

		private:
			/// FTGLPixmapFont linked to the current RenderText.
			FTGLPixmapFont* font;

	};

#endif
