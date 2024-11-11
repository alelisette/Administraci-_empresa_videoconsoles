#pragma once
#include "PassarellaConte.h"
#include "Conexio.h"
#include <iostream>
#include <vector>
class CercadoraConte
{
public:
	CercadoraConte() {};
	std::vector <PassarellaConte> cercaConte(std::string videojoc); //excepcio:CompraNoExisteix
	std::vector <PassarellaConte> cercaConteP(std::string paquet);
};


