#ifndef RENDERTEXT_HPP
#define RENDERTEXT_HPP
	
	#include <map>
	#include <string>
	#include <FTGL/ftgl.h>
	#include "Element.hpp"
	
	using namespace std;

	class RenderText : public Element
	{
		public:
			///
			/// Constructor.
			///
			RenderText(FTGLPixmapFont* const);

			///
			/// Destructor.
			///
			~RenderText();

			///
			/// Set the text size.
			///
			void setSize(unsigned int const);

			///
			/// Set the text value.
			///
			void setText(string const);

			///
			/// Draw the text.
			///
			void draw(void);

		private:
			///
			/// FTGLPixmapFont linked to the current RenderText.
			///
			FTGLPixmapFont* font;

			///
			/// Text value.
			///
			string text;

			///
			/// Text size.
			///
			unsigned int size;

	};

#endif
