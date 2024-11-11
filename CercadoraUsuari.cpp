#include "CercadoraUsuari.h"

PassarellaUsuari CercadoraUsuari::cercaUsuari(std::string sobrenomU) { //excepcio: UsuariNoExisteix
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
		pqxx::result result = con.executar(query);
		std::string nom;
		std::string sobrenom;
		std::string contrasenya;
		std::string correuElectronic;
		std::string dataNaixement;
		for (const auto& row : result) {
			nom = row["nom"].as<std::string>();
			contrasenya = row["contrasenya"].as<std::string>();
			correuElectronic = row["correu_electronic"].as<std::string>();
			dataNaixement = row["data_naixement"].as<std::string>();
		}
		PassarellaUsuari u(nom, sobrenomU, contrasenya, correuElectronic, dataNaixement);
		return u;
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al cercar usuari en la base de dades: " + std::string(e.what()));
	}

}