#include "UIMessageBox.hpp"

UIMessageBox::UIMessageBox(FTGLPixmapFont* const font) : RenderText(font)
{
	this->message = NULL;
	this->load(RES_UIMESSAGEBOX_MESH);
	this->setTextureId(utils::loadPng32(RES_UIMESSAGEBOX_SKIN));

}

UIMessageBox::~UIMessageBox()
{
}

void UIMessageBox::draw(void)
{
	RenderMesh::draw();
	RenderText::draw();
}

void UIMessageBox::aSet_position(void* const data)
{
	RenderMesh::aSet_position(data);
	RenderText::aSet_position(data);
	this->x += (tmatrix[0] / 2.0f) - centerx;
	this->y += (tmatrix[5] / 2.0f) - centery;
}

