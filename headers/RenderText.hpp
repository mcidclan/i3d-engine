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

			/// Concat a text to the current text value.
			void addText(string const);

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

			/// Return the text value.
			string& getData(void);

			/// Return the position corresponding to the
			/// left bottom corner of the text.
			vec3<float>& getPosition(void);

			/// Return the space advance value.
			float getSpaceAdvance(void);

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

			/// Space advance value.
			float spaceadvance;

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
