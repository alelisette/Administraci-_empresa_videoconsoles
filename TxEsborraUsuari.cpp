#include "TxEsborraUsuari.h"

TxEsborraUsuari::TxEsborraUsuari(std::string contraU) { //creadora
	_contraU = contraU;
}

void TxEsborraUsuari::executar() {
	PassarellaUsuari u;
	Videoconsola& v = Videoconsola::getInstance();
	u = v.obteUsuari();
	std::string c = u.obteContrasenya();
	if (c != _contraU)
		throw std::runtime_error("Error: Contrasenya incorrecta.");
	else {
		u.esborra();
		v.tanca_sessio();
	}
}