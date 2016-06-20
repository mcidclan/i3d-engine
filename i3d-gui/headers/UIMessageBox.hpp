#ifndef UIMESSAGEBOX_HPP
#define UIMESSAGEBOX_HPP

	#include "utils.hpp"
	#include "RenderText.hpp"
	#include "RenderMesh.hpp"
	#include "uiconstants.hpp"

	class UIMessageBox : public RenderMesh
	{
		public:
			/// Constructor.
			UIMessageBox(FTGLPixmapFont* const, bool const = true);

			/// Destructor.
			~UIMessageBox();

			/// Drawing process.
			void drawGui(void);

			RenderText* getText(void);

			///@{
			/// Actions.
			void aSet_position(void* const);

			void aSet_scale(void* const);
			///@}

		public://protected:
			/// Load the skin resources.
			virtual void loadResources(void);

		protected:
			/// Message text displayed.
			RenderText* text;

		private:
			/// Allows to move the text to the center.
			void moveTextToCenter(void);

	};

#endif

