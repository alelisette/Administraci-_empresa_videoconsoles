#include "CercadoraPaquet.h"

std::vector<std::string> CercadoraPaquet::cercaPaquets() {
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "SELECT * FROM paquet_videojoc";
		pqxx::result result = con.executar(query);
		std::vector<std::string> res;
		std::string nom;
		if (result.size() == 0) {
			throw std::runtime_error("  ");
		}
		for (const auto& row : result) {
			nom = row["nom"].as<std::string>();
			res.push_back(nom);
		}
		return res;
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al cercar Videojoc en la base de dades: " + std::string(e.what()));
	}
}
