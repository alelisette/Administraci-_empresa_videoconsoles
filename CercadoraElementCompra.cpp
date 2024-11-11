#include "CercadoraElementCompra.h"


PassarellaElemCompra CercadoraElemCompra::cercaElement(std::string element) {
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "SELECT * FROM element_compra WHERE nom = '" + element + "'";
		pqxx::result result = con.executar(query);
		std::string nom;
		std::string descripcio;
		double preu;
		std::string tipus;
		if (result.size() == 0) {
			throw std::runtime_error("  ");
		}
		for (const auto& row : result) {
			nom = row["nom"].as<std::string>();
			descripcio = row["descripcio"].as<std::string>();
			preu = row["preu"].as<double>();
			tipus = row["tipus"].as<std::string>();
		}
		PassarellaElemCompra sol(nom, descripcio, preu, tipus);
		return sol;
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al cercar elementCompra en la base de dades: " + std::string(e.what()));
	}
}

double CercadoraElemCompra::cercaEstalvi(std::string element) {
	Conexio& con = Conexio::getInstance();
	try {
		double preu;
		std::string query = "SELECT * FROM preu_jocs WHERE nom_paquet = '" + element + "'";
		pqxx::result result = con.executar(query);
		for (const auto& row : result) {
			preu = row["preu_jocs"].as<double>();
		}
		return preu;
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al cercar elementCompra en la base de dades: " + std::string(e.what()));
	}
}