#include "TxJocsRelacionats.h"

TxJocsRelacionats::TxJocsRelacionats(std::string nom) {
	_nom = nom;
}

void TxJocsRelacionats::executar() {
	CercadoraConte aux;
	std::vector<PassarellaConte> vC = aux.cercaConte(_nom);
	for (int i = 0; i < vC.size(); i++) {
		std::vector<PassarellaConte> vC2 = aux.cercaConteP(vC[i].obtePaquet());
		for (int j = 0; j < vC2.size(); j++) {
			CercadoraElemCompra aux2;
			PassarellaElemCompra pE = aux2.cercaElement(vC2[j].obteVideojoc());
			std::string nom = (vC2[j].obteVideojoc());
			std::string des = pE.obteDescripcio();
			double preu = pE.obtePreu();
			infoElem e;
			e.nom = nom;
			e.descripcio = des;
			e.preu = preu;
			if(nom!=_nom) _resultat.push_back(e);
		}
	}
}

std::vector<infoElem> TxJocsRelacionats::obteResultat() {
	return _resultat;
}