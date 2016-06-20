#include "ClientInformer.hpp"

void* ClientInformer::getData(ClData& data,
uint const type, string const value)
{
	switch(type)
	{
		case CL_DATA_INT:
		{
			int* out = new int[1];
			*out = utils::readFrom<int>(data[value]);
			return &(out[0]);
		}

		case CL_DATA_UINT:
		{
			uint* out = new uint[1];
			*out = utils::readFrom<uint>(data[value]);
			return &(out[0]);
		}

		case CL_DATA_CHAR:
		{
			char* out = new char[1];
			*out = utils::readFrom<char>(data[value]);
			return &(out[0]);
		}

		case CL_DATA_FLOAT:
		{
			float* out = new float[1];
			*out = utils::readFrom<float>(data[value]);
			return &(out[0]);
		}

		case CL_DATA_DOUBLE:
		{
			double* out = new double[1];
			*out = utils::readFrom<double>(data[value]);
			return &(out[0]);
		}

		case CL_DATA_STRING:
		{
			string* out = new string[1];
			*out = utils::readFrom<string>(data[value]);
			return &(out[0]);
		}
	}

	return NULL;
}

