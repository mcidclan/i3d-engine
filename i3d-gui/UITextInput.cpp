#include "UITextInput.hpp"

UITextInput::UITextInput(FTGLPixmapFont* const font) :
UIMessageBox(font, false)
{
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

void UITextInput::aSet_write(void* const data)
{
	string s = (char const*)(data + sizeof(uint));
	utils::utf8Adjuster(s);
	this->text->addText(s);
}

void UITextInput::aDo_write(void* const data)
{
	this->aSet_write(data);
}

