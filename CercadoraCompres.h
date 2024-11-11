#pragma once
#include "PassarellaCompra.h"
#include "Conexio.h"
#include <iostream>
#include <vector>
class CercadoraCompres
{
public:
	CercadoraCompres() {};
	std::vector <PassarellaCompra> cercaCompra(std::string sobrenomU); //excepcio:CompraNoExisteix
};

