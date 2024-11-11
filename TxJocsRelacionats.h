#pragma once
#include <vector>
#include "CercadoraConte.h"
#include "CercadoraElementCompra.h"
struct infoElem
{
	std::string nom;
	std::string descripcio;
	double preu;
};

class TxJocsRelacionats
{
public:
	TxJocsRelacionats(std::string nom);
	void executar();
	std::vector<infoElem> obteResultat();
private:
	std::string _nom;
	std::vector<infoElem> _resultat;

};

