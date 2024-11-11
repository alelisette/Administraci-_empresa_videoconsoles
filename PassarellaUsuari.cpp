#include "PassarellaUsuari.h"


PassarellaUsuari::PassarellaUsuari() { //creadora
}

PassarellaUsuari::PassarellaUsuari(std::string nomU, std::string sobrenomU, std::string contrasenyaU, std::string correuElectronicU, std::string dataNaixementU) { //???
	_nom = nomU;
	_sobrenom = sobrenomU;
	_contrasenya = contrasenyaU;
	_correuElectronic = correuElectronicU;
	_dataNaixement = dataNaixementU;
}

PassarellaUsuari& PassarellaUsuari::operator=(const PassarellaUsuari& other) {
	_nom = other._nom;
	_sobrenom = other._sobrenom;
	_contrasenya = other._contrasenya;
	_correuElectronic = other._correuElectronic;
	_dataNaixement = other._dataNaixement;
	return *this;
}

//getters i setters per si de cas menys el de SOBRENOM ja q no es pot modificar? o el possem per si de cas? hauria de fer una excep qui la crida en cas q fos el mateix
std::string PassarellaUsuari::obteNom() {
	return _nom;
}
std::string PassarellaUsuari::obteSobrenom() {
	return _sobrenom;
}
std::string PassarellaUsuari::obteContrasenya() {
	return _contrasenya;
}
std::string PassarellaUsuari::obtecorreuElectronic() {
	return _correuElectronic;
}
std::string PassarellaUsuari::obtedataNaixement() {
	return _dataNaixement;
}

void PassarellaUsuari::posaNom(std::string nom) {
	_nom = nom;
}

void PassarellaUsuari::posaContrasenya(std::string contrasenya) {
	_contrasenya = contrasenya;
}
void PassarellaUsuari::posaCorreuElectronic(std::string correuElectronic) {
	_correuElectronic = correuElectronic;
}
void PassarellaUsuari::posaDataNaixement(std::string dataNaixement) {
	_dataNaixement = dataNaixement;
}


void PassarellaUsuari::insereix() { //exc:UsuariExisteix or CorreuExisteix
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "INSERT INTO usuari (nom, sobrenom, contrasenya, correu_electronic, data_naixement) VALUES ('" +
			_nom + "', '" +
			_sobrenom + "', '" +
			_contrasenya + "', '" +
			_correuElectronic + "', '" +
			_dataNaixement + "')";
		con.executar(query);
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al insertar usuari en la base de dades: " + std::string(e.what()));
	}
}
void PassarellaUsuari::modifica() { //exc: UsuariNoExisteix
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "UPDATE usuari SET nom='" + _nom + "', contrasenya='" + _contrasenya + "', correu_electronic='" + _correuElectronic + "', data_naixement='" + _dataNaixement + "' WHERE sobrenom='" + _sobrenom + "'";
		con.executar(query);
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al modificar usuari en la base de dades: " + std::string(e.what()));
	}
}
void PassarellaUsuari::esborra() {  //exc:UsuariNoExisteix
	Conexio& con = Conexio::getInstance();
	try {
		std::string query = "DELETE FROM usuari WHERE sobrenom='" + _sobrenom + "'";
		con.executar(query);
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error al esborrar usuari en la base de dades: " + std::string(e.what()));
	}
}

