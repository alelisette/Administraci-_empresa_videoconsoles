#include "CtrCompraVideojoc.h"

infoVid CtrCompraVideojoc::consultarVideojoc(std::string nomV) {
	TxConsultaVideojoc txCV(nomV);
	try {
		txCV.executar();
		_elem = txCV.obteElement();
		return txCV.obteResultat();
	}
	catch (const std::exception& e) {
		throw std::runtime_error("Videojoc NO existeix");
	}
}

void CtrCompraVideojoc::comprarVideojoc() {

	TxNovaCompra txNC(_elem.obteNom(), _elem.obtePreu());
	try {
		txNC.executar();
	}
	catch (const std::exception& e) {
		throw std::runtime_error("Videojoc ja comprat");
	}
}

std::vector<infoElem> CtrCompraVideojoc::videojocsRelacionats() {
	TxJocsRelacionats txJR(_elem.obteNom());
	txJR.executar();
	return txJR.obteResultat();
}