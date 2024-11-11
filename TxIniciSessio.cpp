#include "TxIniciSessio.h"

//creadora
TxIniciSessio::TxIniciSessio(std::string snU, std::string conU) {
	_sobrenomU = snU;
	_contrasenyaU = conU;
}
void TxIniciSessio::executar() {	//fa el que digui el diagrama
	CercadoraUsuari aux;
	std::string con = (aux.cercaUsuari(_sobrenomU)).obteContrasenya();
	Videoconsola& v = Videoconsola::getInstance();
	if (_contrasenyaU != con) throw std::runtime_error("Error: Contrasenya incorrecta.");
	else {
		v.iniciar_sessio((aux.cercaUsuari(_sobrenomU)));
	}
}