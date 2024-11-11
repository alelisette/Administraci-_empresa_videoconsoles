#pragma once
#include <iostream>
#include "PassarellaElemCompra.h"
#include "Conexio.h"
#include <pqxx/pqxx>
class CercadoraElemCompra
{
public:
	CercadoraElemCompra() {};
	PassarellaElemCompra cercaElement(std::string elem); //excepcio:ElemCompraNoExisteix
	double cercaEstalvi(std::string elem);
};

