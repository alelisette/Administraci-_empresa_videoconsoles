#pragma once
#include "CercadoraCompres.h"
#include "CercadoraElementCompra.h"
#include "Videoconsola.h"
#include "CercadoraConte.h"

struct infoC
{
	std::string nom;
	std::string data;
	std::string descripcio;
	double preu;
	std::vector<infoC> videojoc;
};

class TxConsultaCompres
{
public:
	TxConsultaCompres() {};
	void executar();
	std::vector<infoC> obteResultat();
private:
	std::vector<infoC> _resultat;
};

