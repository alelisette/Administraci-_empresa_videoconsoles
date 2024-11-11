#include "TxInfoCompres.h"

TxInfoCompres::TxInfoCompres() {}

void TxInfoCompres::executar() {
	Videoconsola& v = Videoconsola::getInstance();
	std::string sobrenomU = (v.obteUsuari()).obteSobrenom();
	CercadoraCompres aux;
	std::vector<PassarellaCompra> compresU = aux.cercaCompra(sobrenomU);
	for (int i = 0; i < compresU.size(); i++) {
		std::string elem = compresU[i].obteElementCompra();
		CercadoraElemCompra auxEC;
		PassarellaElemCompra eC = auxEC.cercaElement(elem); // Modificat obte preu de Passarella compra
		resultat.totalEuros += compresU[i].obtePreu();
		if (eC.obteTipus() == "paquet") {
			resultat.totalPaquets++;
		}
		else {
			resultat.totalVideojocs++;
		}
	}
}

infoCom TxInfoCompres::obteResultat() {
	return resultat;
}
