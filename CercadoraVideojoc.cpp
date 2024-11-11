#include "CercadoraVideojoc.h"

PassarellaVideojoc CercadoraVideojoc::cercaVideojoc(std::string videojoc) {
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "SELECT * FROM videojoc WHERE nom = '" + videojoc + "'";
		pqxx::result result = con.executar(query);
		std::string nom;
		std::string genere;
		std::string data_llansament;
		int mins_estimat = 0;
		int qualificacio_edat = 0;
		if (result.size() == 0) {
			throw std::runtime_error("No results found for the given videojoc");
		}
		for (const auto& row : result) {
			nom = row["nom"].as<std::string>();
			genere = row["genere"].as<std::string>();
			data_llansament = row["data_llansament"].as<std::string>();
			if (not row["mins_estimat"].is_null()) mins_estimat = row["mins_estimat"].as<int>();
			else mins_estimat = 0;
			qualificacio_edat = row["qualificacio_edat"].as<int>();
		}
		PassarellaVideojoc sol(nom, genere, qualificacio_edat, data_llansament, mins_estimat);
		return sol;
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al cercar Videojoc en la base de dades: " + std::string(e.what()));
	}
}


std::vector<PassarellaVideojoc> CercadoraVideojoc::cercaVideojocs() {
	Conexio& con = Conexio::getInstance();
	try {

		std::string query = "SELECT * FROM videojoc ORDER BY data_llansament DESC";
		pqxx::result result = con.executar(query);
		std::string nom;
		std::string genere;
		std::string data_llansament;
		int mins_estimat = 0;
		int qualificacio_edat = 0;
		std::vector<PassarellaVideojoc> res;
		for (const auto& row : result) {
			nom = row["nom"].as<std::string>();
			genere = row["genere"].as<std::string>();
			data_llansament = row["data_llansament"].as<std::string>();
			if (not row["mins_estimat"].is_null()) mins_estimat = row["mins_estimat"].as<int>();
			else mins_estimat = 0;
			qualificacio_edat = row["qualificacio_edat"].as<int>();
			PassarellaVideojoc sol(nom, genere, qualificacio_edat, data_llansament, mins_estimat);
			res.push_back(sol);
		}
		return res;
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al cercar Videojoc en la base de dades: " + std::string(e.what()));
	}
}


std::vector<PassarellaVideojoc> CercadoraVideojoc::cercaNovetatsVideojocs(std::string Data_llansament) {
	Conexio& con = Conexio::getInstance();
	try {
		std::string query;
		if (Data_llansament.empty()) {
			query = "SELECT * FROM videojoc WHERE data_llansament >= CURRENT_TIMESTAMP ORDER BY data_llansament DESC";
		}
		else {
			query = "SELECT * FROM videojoc WHERE data_llansament >= '" + Data_llansament + "' ORDER BY data_llansament DESC";
		}
		pqxx::result result = con.executar(query);
		std::string nom;
		std::string genere;
		std::string data_llansament;
		int mins_estimat = 0;
		int qualificacio_edat = 0;
		//FALTA POSAR QUE SI RESULT.SIZE()==0 THROW ERROR
		//if (result.size() == 0) throw (e);
		std::vector<PassarellaVideojoc> v;
		for (const auto& row : result) {
			nom = row["nom"].as<std::string>();
			genere = row["genere"].as<std::string>();
			data_llansament = row["data_llansament"].as<std::string>();
			if (not row["mins_estimat"].is_null()) mins_estimat = row["mins_estimat"].as<int>();   //Vigilar cuando es vacio que
			else mins_estimat = 0;
			qualificacio_edat = row["qualificacio_edat"].as<int>();
			PassarellaVideojoc sol(nom, genere, qualificacio_edat, data_llansament, mins_estimat);
			v.push_back(sol);
		}
		return v;
	}
	catch (const pqxx::sql_error& e) {
		std::cout << std::string(e.what()) << std::endl;
		throw std::runtime_error("Error al cercar Videojoc en la base de dades: " + std::string(e.what()));
	}
}


std::vector<PassarellaVideojoc> CercadoraVideojoc::cercaVQualificacioEdat(std::string edat) {
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "SELECT * FROM public.videojoc WHERE qualificacio_edat <= '" + edat + "' ORDER BY qualificacio_edat DESC";
		pqxx::result result = con.executar(query);
		std::string nom;
		std::string genere;
		std::string data_llansament;
		int mins_estimat = 0;
		int qualificacio_edat = 0;
		std::vector<PassarellaVideojoc> v;
		for (const auto& row : result) {
			nom = row["nom"].as<std::string>();
			genere = row["genere"].as<std::string>();
			data_llansament = row["data_llansament"].as<std::string>();
			if (not row["mins_estimat"].is_null()) mins_estimat = row["mins_estimat"].as<int>();   //Vigilar cuando es vacio que
			else mins_estimat = 0;
			qualificacio_edat = row["qualificacio_edat"].as<int>();
			PassarellaVideojoc sol(nom, genere, qualificacio_edat, data_llansament, mins_estimat);
			v.push_back(sol);
		}
		return v;
	}
	catch (const pqxx::sql_error& e) {
		std::cout << std::string(e.what()) << std::endl;
		throw std::runtime_error("Error al cercar Videojoc en la base de dades: " + std::string(e.what()));
	}
}