#include "RenderText.hpp"

RenderText::RenderText(FTGLPixmapFont* const font)
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;

	this->size = 16;
	this->text = "";

	this->centerx = 0.0f;
	this->centery = 0.0f;

	this->font = font;
}

RenderText::~RenderText()
{
}

void RenderText::setSize(unsigned int const size)
{
	this->size = size;
	this->updateCenter();
}

void RenderText::setText(string const text)
{
	this->text = text;
	this->updateCenter();
}

void RenderText::updateCenter(void)
{
	this->centerx = this->size / 2.0f;
	this->centery = (this->size * this->text.length()) / 2.0f;
}

void RenderText::draw(void)
{
	glPushMatrix();
	glTranslatef(this->x, this->y, this->z);
	this->font->FaceSize(size);
	this->font->Render(this->text.c_str());
	glPopMatrix();
}

void RenderText::aSet_position(void* const data)
{
	uchar* const idata = (uchar*)data;
	float* const vdata = (float*)data;

	if(idata[0] & P_X) this->x = vdata[1];
	if(idata[0] & P_Y) this->y = vdata[2];
	if(idata[0] & P_Z) this->z = vdata[3];
}

