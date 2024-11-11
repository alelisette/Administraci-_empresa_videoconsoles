#pragma once

#include "CercadoraVideojoc.h"
#include "CercadoraElementCompra.h"
#include "CercadoraConte.h"

struct infoVids
{
	std::string nom;
	std::string descripcio;
	int qualificacio_edat;
	std::string genere;
	std::string data_llansament;
	int mins_estimats;
	double preu;
	std::vector<std::string> nom_paquets;
};

class TxConsultaVideojocs
{
public:
	TxConsultaVideojocs(){}
	void executar();
	std::vector<infoVids> obteResultat();
private:
	std::vector<infoVids> _resultat;
};

