#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari() {

}

void TxConsultaUsuari::executar() {
	Videoconsola& v = Videoconsola::getInstance();
	_usuari = v.obteUsuari();
	_resultat.nom = _usuari.obteNom();
	_resultat.sobrenom = _usuari.obteSobrenom();
	_resultat.correu = _usuari.obtecorreuElectronic();
	_resultat.dataN = _usuari.obtedataNaixement();
}

infoUsu TxConsultaUsuari::obteResultat() {
	return _resultat;
}

PassarellaUsuari TxConsultaUsuari::obteUsuari() {
	return _usuari;
}