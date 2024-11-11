#include "TxConsultaPaquets.h"


void TxConsultaPaquets::executar() {
	CercadoraPaquet aux;
	std::vector<std::string> p = aux.cercaPaquets();
	for (int i = 0; i < p.size(); i++) {
		CercadoraElemCompra aux2;
		PassarellaElemCompra s = aux2.cercaElement(p[i]);
		infoPs a;
		a.nom = s.obteNom();
		a.descripcio = s.obteDescripcio();
		a.preu = s.obtePreu();
		a.preuTJ = aux2.cercaEstalvi(a.nom) - a.preu;
		_resultat.push_back(a);
	}
}

std::vector<infoPs> TxConsultaPaquets::obteResultat() {
	return _resultat;
}