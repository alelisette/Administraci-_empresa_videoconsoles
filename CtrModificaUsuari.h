#pragma once
#include "TxConsultaUsuari.h"
class CtrModificaUsuari
{
public:
	CtrModificaUsuari() {}
	infoUsu consultaUsuari();
	void modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU);
private:
	PassarellaUsuari _usuari;
};

