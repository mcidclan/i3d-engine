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

			///@{
			/// Actions.
			void aSet_write(void* const);

			void aDo_write(void* const);
			///@}

		public:
			/// Load the skin resources.
			virtual void loadResources(void);

	};

#endif

