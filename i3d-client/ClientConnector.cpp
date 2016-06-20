#include "ClientConnector.hpp"

ClientConnector::ClientConnector()
{
	this->server = "";
	this->username = "";
	this->userpass = "";
	this->database = "";
}

ClientConnector::~ClientConnector()
{
	delete this->connection;
}

void ClientConnector::open(void)
{
	try
	{
		Driver* driver;

		driver = get_driver_instance();
		driver->connect(this->server, this->username, this->userpass);

		this->connection->setSchema(this->database);
	}
	catch (sql::SQLException &e)
	{
		cout << "Error: " << e.what();
		cout << "MySQL error code: " << e.getErrorCode();
		cout << "SQLState: " << e.getSQLState() << endl;
	}
}

void ClientConnector::setServer(string const server)
{
	this->server = server;
}

void ClientConnector::setDataBase(string const database)
{
	this->database = database;
}

void ClientConnector::setUser(string const username, string const userpass)
{
	this->username = username;
	this->userpass = userpass;
}

