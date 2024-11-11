#include "Conexio.h"

pqxx::result Conexio::executar(std::string& sentenciaSQL) {
	pqxx::connection conn("dbname=" + _dbname + " user=" + _user + " password=" + _password + " hostaddr=" + _hostaddr + " port=" + _port);

	if (conn.is_open()) {
		//std::cout << "Conexio exitosa amb la base de dades" << std::endl;
	}
	else {
		std::cerr << "Error connexio base de dades" << std::endl;
	}
	pqxx::work txn(conn);
	pqxx::result result = txn.exec(sentenciaSQL);
	txn.commit();
	return result;
}

void Conexio::inicialitzar_atributs(std::string dbname, std::string user, std::string password, std::string hostaddr, std::string port) {
	_dbname = dbname;
	_user = user;
	_password = password;
	_hostaddr = hostaddr;
	_port = port;
}