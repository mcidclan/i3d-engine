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

			/// Allows to center the text.
			void toCenter(void);

			/// Allows to set the position.
			void situate(float const, float const, float const);

			/// Allows to translate the text.
			void translate(float const, float const, float const);

			///@{
			/// Actions.
			void aSet_position(void* const);

			void aSet_scale(void* const);
			///@}

		protected:
			/// Text value.
			string text;

			/// Center of the text in x.
			float centerx;

			/// Center of the text in y.
			float centery;

			/// Current RenderText scale.
			vec3<float> scale;

			/// Current RenderText position.
			vec3<float> position;

		private:
			/// FTTextureFont linked to the current RenderText.
			FTGLPixmapFont* font;

			/// Text size.
			unsigned int size;

			/// Allows to update some specifics properties.
			void update(void);

	};

#endif
