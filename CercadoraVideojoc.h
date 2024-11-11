#pragma once
#include "PassarellaVideojoc.h"
#include "Conexio.h"

class CercadoraVideojoc
{
public:
	CercadoraVideojoc() {};
	PassarellaVideojoc cercaVideojoc(std::string videojoc); //excepcio:ElemCompraNoExisteix
	std::vector<PassarellaVideojoc> cercaVideojocs();
	std::vector<PassarellaVideojoc> cercaNovetatsVideojocs(std::string data_llancament);
	std::vector<PassarellaVideojoc> cercaVQualificacioEdat(std::string edat);
};
