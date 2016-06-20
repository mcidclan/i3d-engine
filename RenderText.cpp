#include "RenderText.hpp"

RenderText::RenderText(FTGLPixmapFont* const font)
{
	this->size = 16;
	this->text = "";

	this->centerx = 0.0f;
	this->centery = 0.0f;

	this->spaceadvance = 0.0f;

	this->scale = vec3<float>();
	this->position = vec3<float>();

	this->font = font;

	this->update();
}

RenderText::~RenderText()
{
}

void RenderText::setSize(unsigned int const size)
{
	this->size = size;
	this->update();
	this->spaceadvance = this->font->Advance(" ");
}

void RenderText::addText(string const text)
{
	this->text += text;
	this->update();
}

void RenderText::setText(string const text)
{
	this->text = text;
	this->update();
}

void RenderText::update(void)
{
	this->font->FaceSize(size);
	this->centery = this->font->Ascender() * 0.5f;
	this->centerx = this->font->Advance(this->text.c_str()) * 0.5f;
}

void RenderText::draw(void)
{
	glPushMatrix();
	glRasterPos3f(this->position.x, this->position.y, 0.0f);
	this->font->Render(this->text.c_str());
	glPopMatrix();
}

void RenderText::toCenter(void)
{
	this->position.add(-this->centerx, -this->centery, 0.0f);
}

void RenderText::situate(float const x, float const y, float const z)
{
	this->position.set(x, y, z);
}

void RenderText::translate(float const x, float const y, float const z)
{
	this->position.add(x, y, z);
}

string& RenderText::getData(void)
{
	return this->text;
}

vec3<float>& RenderText::getPosition(void)
{
	return this->position;
}

float RenderText::getSpaceAdvance(void)
{
	return this->spaceadvance;
}

void RenderText::aSet_position(void* const data)
{
	EAI::setTransformation(data, this->position);
}

void RenderText::aSet_scale(void* const data)
{
	//EAI::setTransformation(data, this->scale);
}

