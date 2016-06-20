#include "RenderText.hpp"

RenderText::RenderText(FTGLPixmapFont* const font)
{
	this->font = font;
	this->size = 16;
	this->text = "";
}

RenderText::~RenderText()
{
}

void RenderText::setSize(unsigned int const size)
{
	this->size = size;
}

void RenderText::setText(string const text)
{
	this->text = text;
}

void RenderText::draw(void)
{
	this->font->FaceSize(size);
	this->font->Render(this->text.c_str());
}
