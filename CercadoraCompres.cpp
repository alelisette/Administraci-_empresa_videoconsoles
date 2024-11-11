#include "CercadoraCompres.h"


std::vector <PassarellaCompra> CercadoraCompres::cercaCompra(std::string sobrenomU) {
	std::vector<PassarellaCompra> sol;
	Conexio& con = Conexio::getInstance();
	std::string query = "SELECT * FROM compra WHERE usuari = '" + sobrenomU + "'";
	pqxx::result result = con.executar(query);
	std::string element;
	std::string usuari;
	std::string data;
	double preu_pagat;
	std::string dataNaixement;
	for (const auto& row : result) {
		element = row["element"].as<std::string>();
		usuari = row["usuari"].as<std::string>();
		data = row["data"].as<std::string>();
		preu_pagat = row["preu_pagat"].as<double>();
		sol.push_back(PassarellaCompra(element, usuari, data, preu_pagat));
	}
	return sol;
}
