#ifndef UITEXTINPUT_HPP
#define UITEXTINPUT_HPP

	#include "UIMessageBox.hpp"

	class UITextInput : public UIMessageBox
	{
		public:
			/// Constructor.
			UITextInput(FTGLPixmapFont* const);

			/// Destructor.
			~UITextInput();

			virtual void drawGui(void);

			///
			void setTextSize(uint const);

			///
			void setTextPosition(float const, float const);

			///
			void setTextMaxCharacters(uint const);

			///@{
			/// Actions.
			void aSet_move(void* const);

			void aSet_write(void* const);

			void aSet_erase(void* const);

			void aDo_write(void* const);
			///@}

		protected:
			/// Load the skin resources.
			virtual void loadResources(void);

			///
			virtual void alignText(void);

		private:
			///
			float textx;

			///
			float texty;

			///
			string data;

			///
			uint cursor;

			///
			uint origin;

			///
			uint maxchar;

			///
			void updateBorders(void);

			///
			void updateText(void);

			///
			void addTextValue(string const);

			///
			uint getTail(void);

	};

#endif

