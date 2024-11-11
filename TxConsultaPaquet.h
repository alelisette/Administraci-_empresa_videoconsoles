#pragma once

#include <iostream>
#include <vector>
#include "TxJocsRelacionats.h"

struct infoP
{
	std::string nom;
	std::string descripcio;
	double preu;
	double preuTJ;
	std::vector<infoElem> videojoc;
};

class TxConsultaPaquet
{
public:
	TxConsultaPaquet(std::string nom);
	TxConsultaPaquet() {};
	void executar();
	infoP obteResultat();
	std::string obteNom();
	PassarellaElemCompra obteElementP();
private:
	std::string _nom;
	PassarellaElemCompra _elem_compra;
	infoP _resultat;
};
