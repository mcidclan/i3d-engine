#include "headers/RenderText.hpp"
#include <iostream>
RenderText::RenderText(FTGLPixmapFont* const font)
{
	//this->font =  new FTGLPixmapFont("./font.ttf");

	this->font = font;
	this->setSize(72);
	this->text = "";
}

RenderText::~RenderText()
{
}

void RenderText::setSize(unsigned int const size)
{
	this->size = size;
	this->font->FaceSize(size);
}

void RenderText::setText(string const text)
{
	this->text = text;
}

void RenderText::draw(void)
{
	this->font->Render(this->text.c_str());
}
