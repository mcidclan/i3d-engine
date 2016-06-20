#include "UITextInput.hpp"

UITextInput::UITextInput(FTGLPixmapFont* const font) :
UIMessageBox(font, false)
{
	this->textx = 0.0f;
	this->texty = 0.0f;

	this->cursor = 0;
	this->origin = 0;
	this->maxchar = 0;

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

void UITextInput::drawGui(void)
{
	UIMessageBox::drawGui();
}

void UITextInput::updateText(void)
{
	string text;

	text = this->data.substr(this->origin, this->getTail());

	utils::utf8Adjuster(text);
	this->text->setText(text);
}

void UITextInput::setTextSize(uint const size)
{
	this->text->setSize(size);
}

void UITextInput::addTextValue(string const value)
{
	this->data.insert(this->cursor, value);
	this->cursor += value.length();

	if(this->cursor > (this->origin + this->maxchar))
	{
		this->origin += value.length();
	}

	this->updateText();
}

void UITextInput::setTextPosition(float const x, float const y)
{
	this->textx = x;
	this->texty = y;
}

void UITextInput::setTextMaxCharacters(uint const max)
{
	this->maxchar = max;
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
	this->addTextValue(sdata);
}

uint UITextInput::getTail(void)
{
	return ((this->data.length() > this->maxchar) ?
	this->maxchar : this->data.length());
}

//0xC3
void UITextInput::aSet_erase(void* const)
{
	if(this->data.size() > 0)
	{
		if(this->cursor > 0) this->cursor--;
		if(this->origin > 0) this->origin--;

		this->data.erase(this->cursor, 1);
		this->updateText();
	}
}

void UITextInput::aDo_write(void* const data)
{
	this->aSet_write(data);
}

void UITextInput::aSet_move(void* const data)
{
	int step;

	step = (int)((uint*)data)[0];

	if(((this->cursor > 0) && (step < 0)) ||
	((this->cursor < this->data.length()) && (step > 0)))
	{
		this->cursor += step;
	}

	if((this->cursor < this->origin) ||
	(this->cursor > (this->origin + this->maxchar)))
	{
		this->origin += step;
		this->updateText();
	}
}

