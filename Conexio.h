#pragma once
#include <iostream>
#include <pqxx/pqxx>
class Conexio
{
private:
	// Atributs
	std::string _dbname;
	std::string _user;
	std::string _password;
	std::string _hostaddr;
	std::string _port;

	Conexio() {
		_dbname = "";
		_user = "";
		_password = "";
		_hostaddr = "";
		_port = "";
	}

public:
	//Metode per obtenir la 
	static Conexio& getInstance() {
		static Conexio instance;
		return instance;
	}

	pqxx::result executar(std::string& sentenciaSQL);

	void inicialitzar_atributs(std::string dbname, std::string user, std::string password, std::string hostaddr, std::string port);
};
