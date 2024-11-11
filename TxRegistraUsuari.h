#pragma once
#include "PassarellaUsuari.h"

class TxRegistraUsuari
{
public:
	TxRegistraUsuari(std::string nomU, std::string snU, std::string conU, std::string ceU, std::string dnU);
	void executar();

private:
	std::string _nomU;
	std::string _sobrenomU;
	std::string _contrasenyaU;
	std::string _correuElectronicU;
	std::string _dataNaixementU;
};