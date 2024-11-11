#pragma once
#include "CercadoraVideojoc.h"
#include "CercadoraConte.h"
#include "CercadoraElementCompra.h"

struct infoVidE
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

class TxCVQualificacioEdat
{
public:
	TxCVQualificacioEdat(std::string edat);
	void executar();
	std::vector<infoVidE> obteResultat();
private:
	std::string _edat;
	std::vector<infoVidE> _resultat;
};

