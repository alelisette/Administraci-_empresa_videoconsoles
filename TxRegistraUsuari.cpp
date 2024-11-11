#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(std::string nU, std::string snU, std::string conU, std::string ceU, std::string dnU) {
	_nomU = nU;
	_sobrenomU = snU;
	_contrasenyaU = conU;
	_correuElectronicU = ceU;
	_dataNaixementU = dnU;
}
void TxRegistraUsuari::executar() { //implementar amb el daigrama
	PassarellaUsuari u(_nomU, _sobrenomU, _contrasenyaU, _correuElectronicU, _dataNaixementU);
	try {
		u.insereix();
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error inserir Usuari");
	}
}