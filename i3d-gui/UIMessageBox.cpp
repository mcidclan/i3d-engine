#include "UIMessageBox.hpp"

UIMessageBox::UIMessageBox(FTGLPixmapFont* const font,
bool const loadresources)
{
	this->group = EG_GUI;
	this->text = new RenderText(font);

	if(loadresources)
	{
		this->loadResources();
	}
}

void UIMessageBox::loadResources(void)
{
	this->load(RES_UIMESSAGEBOX_MESH);
	this->setTextureId(utils::loadPng32(RES_UIMESSAGEBOX_SKIN));
}

UIMessageBox::~UIMessageBox()
{
	delete this->text;
}

void UIMessageBox::drawGui(void)
{
	RenderMesh::draw();
	this->text->draw();
}

RenderText* UIMessageBox::getText(void)
{
	return this->text;
}

void UIMessageBox::alignText(void)
{
	this->text->translate((tmatrix[0] / 2.0f),
	(tmatrix[5] / 2.0f), 0.0f);
	this->text->toCenter();
}

void UIMessageBox::aSet_position(void* const data)
{
	RenderMesh::aSet_position(data);
	this->text->aSet_position(data);
	this->alignText();
}

void UIMessageBox::aSet_scale(void* const data)
{
	RenderMesh::aSet_scale(data);
	this->text->situate(tmatrix[12], tmatrix[13], 0.0f);
	this->alignText();
}

