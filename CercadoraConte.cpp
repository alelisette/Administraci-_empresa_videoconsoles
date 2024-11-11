#include "CercadoraConte.h"

std::vector<PassarellaConte> CercadoraConte::cercaConte(std::string videojoc) {
	std::vector<PassarellaConte> sol;
	Conexio& con = Conexio::getInstance();
	std::string query = "SELECT * FROM conte WHERE videojoc = '" + videojoc + "'";
	pqxx::result result = con.executar(query);
	std::string v;
	std::string paquet;
	for (const auto& row : result) {
		v = row["videojoc"].as<std::string>();
		paquet = row["paquet"].as<std::string>();
		sol.push_back(PassarellaConte(paquet, v));
	}
	return sol;
}

std::vector<PassarellaConte> CercadoraConte::cercaConteP(std::string paquet) {
	std::vector<PassarellaConte> sol;
	Conexio& con = Conexio::getInstance();
	std::string query = "SELECT * FROM conte WHERE paquet = '" + paquet + "'";
	pqxx::result result = con.executar(query);
	std::string v;
	std::string p;
	for (const auto& row : result) {
		v = row["videojoc"].as<std::string>();
		p = row["paquet"].as<std::string>();
		sol.push_back(PassarellaConte(p, v));
	}
	return sol;
}