#include "CtrModificaUsuari.h"

infoUsu CtrModificaUsuari::consultaUsuari() {
	TxConsultaUsuari aux;
	aux.executar();
	infoUsu sol = aux.obteResultat();
	_usuari = aux.obteUsuari();
	return sol;
}

void CtrModificaUsuari::modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU) {
	if (nomU != "") {
		_usuari.posaNom(nomU);
	}
	if (contraU != "") {
		_usuari.posaContrasenya(contraU);
	}
	if (correuU != "") {
		_usuari.posaCorreuElectronic(correuU);
	}
	if (neixU != "") {
		_usuari.posaDataNaixement(neixU);
	}
	if (nomU != "" or contraU != "" or correuU != "" or neixU != "") {
		try {
			_usuari.modifica();
			Videoconsola& videoconsola = Videoconsola::getInstance();
			videoconsola.iniciar_sessio(_usuari);
		}
		catch (const pqxx::sql_error& e) {
			throw std::runtime_error("Error al cercar elementCompra en la base de dades: " + std::string(e.what()));
		}
	}
}