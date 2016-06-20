#ifndef CLIENTCONNECTOR_HPP
#define CLIENTCONNECTOR_HPP

	#include "customtypes.hpp"
	#include <cppconn/driver.h>
	#include <cppconn/exception.h>
	
	using namespace sql;

	class ClientConnector
	{
		public:
			///
			ClientConnector();

			///
			~ClientConnector();

			///
			void open(void);

			///
			void setServer(string const);

			///
			void setDataBase(string const);

			///
			void setUser(string const, string const);

		private:
			///
			string server;

			///
			string username;

			///
			string userpass;

			///
			string database;

			///
			Connection *connection;

	};

#endif

