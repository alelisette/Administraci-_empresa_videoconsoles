#pragma once
#include "CercadoraVideojoc.h"
#include "CercadoraElementCompra.h"
#include "CercadoraConte.h"

struct infoVidN
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

class TxConsultarNovetatsVideojocs
{
public:
	TxConsultarNovetatsVideojocs(std::string data_llansament);
	void executar();
	std::vector<infoVidN> obteResultat();
private:
	std::string _data_llansament;
	std::vector<infoVidN> _resultat;
};

