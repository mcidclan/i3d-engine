#ifndef UIMESSAGEBOX_HPP
#define UIMESSAGEBOX_HPP

	#include "RenderText.hpp"
	#include "RenderMesh.hpp"

	class UIMessageBox : public RenderMesh
	{
		public:
			///
			UIMessageBox();

			///
			~UIMessageBox();		
		
		private:
			///
			RenderText* message;
	};

#endif

