#include "PassarellaElemCompra.h"

PassarellaElemCompra::PassarellaElemCompra() {
	_preu = 0;
} //constructora
PassarellaElemCompra::PassarellaElemCompra(std::string nom, std::string descripcio, double preu, std::string tipus) {
	_nom = nom;
	_descripcio = descripcio;
	_preu = preu;
	_tipus = tipus;
}

PassarellaElemCompra& PassarellaElemCompra::operator=(const PassarellaElemCompra& other) {
	_nom = other._nom;
	_descripcio = other._descripcio;
	_preu = other._preu;
	_tipus = other._tipus;
	return *this;
}
std::string PassarellaElemCompra::obteNom() {
	return _nom;
}

std::string PassarellaElemCompra::obteTipus() {
	return _tipus;
}

double PassarellaElemCompra::obtePreu() {
	return _preu;
}

std::string PassarellaElemCompra::obteDescripcio() {
	return _descripcio;
}