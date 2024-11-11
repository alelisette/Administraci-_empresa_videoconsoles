#pragma once
#include<iostream>

class PassarellaElemCompra
{
public:
	PassarellaElemCompra(); //constructora
	PassarellaElemCompra(std::string nom, std::string descripcio, double preu, std::string tipus);
	PassarellaElemCompra& operator=(const PassarellaElemCompra& other);

	std::string obteTipus();
	std::string obteNom();
	double obtePreu();
	std::string obteDescripcio();

private:
	std::string _nom;
	std::string _descripcio;
	double _preu;
	std::string _tipus;
};