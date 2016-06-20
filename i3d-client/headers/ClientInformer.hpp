#ifndef CLIENTINFORMER_HPP
#define CLIENTINFORMER_HPP

	#include "customtypes.hpp"
	#include "utils.hpp"

	/// Availables client data types.
	enum ClientDataTypes
	{
		CL_DATA_INT = 0,
		CL_DATA_UINT,
		CL_DATA_CHAR,
		CL_DATA_FLOAT,
		CL_DATA_DOUBLE,
		CL_DATA_STRING		
	};

	typedef ClientDataTypes ClDataType;
	typedef map<string const, string const> ClData;

	class ClientInformer
	{
		public:
			///
			static void* getData(ClData& data,
			uint const type, string const value);

	};

	///
	typedef ClientInformer cli;

#endif

