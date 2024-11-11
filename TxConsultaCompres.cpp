#include "TxConsultaCompres.h"

void TxConsultaCompres::executar() {
	Videoconsola& v = Videoconsola::getInstance();
	std::string sobrenomU = (v.obteUsuari()).obteSobrenom();
	CercadoraCompres aux;
	std::vector<PassarellaCompra> compresU = aux.cercaCompra(sobrenomU);
	for (int i = 0; i < compresU.size(); i++) {
		infoC a;
		a.preu = compresU[i].obtePreu();
		a.data = compresU[i].obteData();
		std::string elem = compresU[i].obteElementCompra();
		CercadoraElemCompra auxEC;
		PassarellaElemCompra eC = auxEC.cercaElement(elem);
		a.nom = eC.obteNom();
		a.descripcio = eC.obteDescripcio();
		if (eC.obteTipus() == "paquet") {
			CercadoraConte aux2;
			std::vector<PassarellaConte> elem = aux2.cercaConteP(a.nom);
			for (int j = 0; j < elem.size(); j++) {
				PassarellaElemCompra pE = auxEC.cercaElement(elem[j].obteVideojoc());
				infoC b;
				b.nom = pE.obteNom();
				b.descripcio = pE.obteDescripcio();
				a.videojoc.push_back(b);
			}
		}
		_resultat.push_back(a);
	}
}
std::vector<infoC> TxConsultaCompres::obteResultat() {
	return _resultat;
}