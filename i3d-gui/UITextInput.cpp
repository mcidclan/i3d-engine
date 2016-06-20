#include "UITextInput.hpp"

UITextInput::UITextInput(FTGLPixmapFont* const font) :
UIMessageBox(font, false)
{
	this->textx =
	this->texty = 0.0f;

	this->loadResources();
}

void UITextInput::loadResources(void)
{
	this->load(RES_UITEXTINPUT_MESH);
	this->setTextureId(utils::loadPng32(RES_UITEXTINPUT_SKIN));
}

UITextInput::~UITextInput()
{
}

void UITextInput::setTextPosition(float const x, float const y)
{
	this->textx = x;
	this->texty = y;
}

void UITextInput::alignText(void)
{
	this->text->translate(this->textx, this->texty, 0.0f);
}

void UITextInput::aSet_write(void* const data)
{	
	uint idata;
	string sdata;
	char* cdata;

	idata = ((uint*)data)[0];
	cdata = &(((char*)data)[sizeof(uint)]);

	sdata = cdata;
	memset(cdata, 0x0, idata);

	utils::utf8Adjuster(sdata);
	this->text->addText(sdata);
}

void UITextInput::aDo_write(void* const data)
{
	this->aSet_write(data);
}

