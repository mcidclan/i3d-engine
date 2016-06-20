#include "CustomString.hpp"

CustomString::CustomString(const char* const content)
{
	this->content = new string(content); 
}

CustomString::~CustomString()
{
	delete content;
}

string CustomString::find_part_after_last_of(char const* const s) const
{
	uint i;

	i = this->content->find_last_of(s);
	return this->content->substr(i + 1);
}

char const* CustomString::c_str(void) const
{
	return this->content->c_str();
}