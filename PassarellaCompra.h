#pragma once
#include<iostream>
#include "Conexio.h"

class PassarellaCompra
{
public:
	PassarellaCompra(); //constructora
	PassarellaCompra(std::string element, std::string usuari, std::string data, double preu_pagat);
	PassarellaCompra& operator=(const PassarellaCompra& other);
	std::string obteElementCompra();
	double obtePreu();
	std::string obteData();
	void insereix();

private:
	std::string _usuari;
	std::string _element;
	std::string _data;
	double _preu_pagat;
};
