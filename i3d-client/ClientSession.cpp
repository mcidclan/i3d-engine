#include "ClientSession.hpp"

ClientSession::ClientSession()
{
}

ClientSession::~ClientSession()
{
}

ClData& ClientSession::getData(void)
{
	return this->data;
}

void ClientSession::aGet_data(void* const data)
{
	uint* cdata = (uint*)data;
	char const* value = (char const*)(cdata[1]);
	cdata[2] = eas::u(cli::getData(this->data, cdata[0], string(value)));
}

