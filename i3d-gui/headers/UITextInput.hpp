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

			///
			void setTextPosition(float const, float const);

			///@{
			/// Actions.
			void aSet_write(void* const);

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

	};

#endif

