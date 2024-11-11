#pragma once
#include "CercadoraElementCompra.h"
#include "CercadoraPaquet.h"

struct infoPs
{
	std::string nom;
	std::string descripcio;
	double preu = 0;
	double preuTJ = 0;
};

class TxConsultaPaquets
{
public:
	TxConsultaPaquets() {}
	void executar();
	std::vector<infoPs> obteResultat();
private:
	std::vector<infoPs> _resultat;

};

