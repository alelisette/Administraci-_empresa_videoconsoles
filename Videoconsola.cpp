#include "Videoconsola.h"

PassarellaUsuari& Videoconsola::obteUsuari() {
	return _usuari;
}

void Videoconsola::iniciar_sessio(PassarellaUsuari u) {
	_usuari = u;
}

void Videoconsola::tanca_sessio() {
	PassarellaUsuari aux("", "", "", "", "");
	_usuari = aux;
}