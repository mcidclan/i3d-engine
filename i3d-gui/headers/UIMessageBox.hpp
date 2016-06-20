#ifndef UIMESSAGEBOX_HPP
#define UIMESSAGEBOX_HPP

	#include "utils.hpp"
	#include "RenderText.hpp"
	#include "RenderMesh.hpp"

	class UIMessageBox : public RenderMesh, public RenderText
	{
		public:
			///
			UIMessageBox(FTGLPixmapFont* const);

			///
			~UIMessageBox();

			///
			void draw(void);

			///@{
			/// Actions.
			void aSet_position(void* const);
			///@}

		private:
			///
			RenderText* message;
	};

#endif

