#pragma once
#include "Videoconsola.h"
#include "Conexio.h"
#include "PassarellaCompra.h"
#include <chrono>
#include <iomanip>

class TxNovaCompra
{
public:
	TxNovaCompra(std::string element, double preu);
	void executar();

private:
	std::string _element;
	double _preu;
};
