#include "PassarellaCompra.h"
PassarellaCompra::PassarellaCompra() {} //constructora
PassarellaCompra::PassarellaCompra(std::string element, std::string usuari, std::string data, double preu_pagat) {
	_element = element;
	_usuari = usuari;
	_data = data;
	_preu_pagat = preu_pagat;
}
PassarellaCompra& PassarellaCompra::operator=(const PassarellaCompra& other) {
	_element = other._element;
	_usuari = other._usuari;
	_data = other._data;
	_preu_pagat = other._preu_pagat;
	return *this;
}

std::string PassarellaCompra::obteElementCompra() {
	return _element;
}

double PassarellaCompra::obtePreu() {
	return _preu_pagat;
}

std::string PassarellaCompra::obteData() {
	return _data;
}


void PassarellaCompra::insereix() {
	Conexio& con = Conexio::getInstance();
	try {
		std::ostringstream queryStream;
		queryStream << "INSERT INTO compra (element, usuari, data, preu_pagat) VALUES ('"
			<< _element << "', '"
			<< _usuari << "', '"
			<< _data << "', "
			<< _preu_pagat << ")";
		std::string query = queryStream.str();
		con.executar(query);
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al insertar compra en la base de dades: " + std::string(e.what()));
	}
}