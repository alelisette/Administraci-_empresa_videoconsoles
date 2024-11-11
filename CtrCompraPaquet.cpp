#include "CtrCompraPaquet.h"

infoP CtrCompraPaquet::consultarPaquet(std::string nomP) {
	TxConsultaPaquet txCP(nomP);
	try {
		txCP.executar();
		_elem = txCP.obteElementP();
		return txCP.obteResultat();
	}
	catch (const std::exception& e) {
		throw std::runtime_error("Paquet NO existeix");
	}
}

void CtrCompraPaquet::comprarPaquet() {
	TxNovaCompra txNC(_elem.obteNom(), _elem.obtePreu());
	try {
		txNC.executar();
	}
	catch (const std::exception& e) {
		throw std::runtime_error("Paquet ja comprat");
	}
}