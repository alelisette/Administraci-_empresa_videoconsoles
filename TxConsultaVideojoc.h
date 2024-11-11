#include "PassarellaVideojoc.h"
#include "CercadoraVideojoc.h"
#include "CercadoraElementCompra.h"
#include "CercadoraCompres.h"
#include "CercadoraConte.h"
#include <iostream>
#include <vector>

struct infoVid
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

class TxConsultaVideojoc
{
public:
	TxConsultaVideojoc(std::string nom);
	void executar();
	infoVid obteResultat();
	PassarellaElemCompra obteElement();
private:
	std::string _nom;
	PassarellaElemCompra _elem_compra;
	infoVid _resultat;
};