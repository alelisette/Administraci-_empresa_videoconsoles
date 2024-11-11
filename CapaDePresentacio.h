#pragma once
#include <iostream>
#include "TxRegistraUsuari.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxConsultaUsuari.h"
#include "TxInfoCompres.h"
#include "TxEsborraUsuari.h"
#include "CtrModificaUsuari.h"
#include "CtrCompraVideojoc.h"
#include "CtrCompraPaquet.h"
#include "TxConsultaPaquet.h"
#include "TxConsultaVideojocs.h"
#include "TxConsultaPaquets.h"
#include "TxConsultaCompres.h"
#include "TxConsultaNovetatsVideojocs.h"
#include "TxCVQualificacioEdat.h"
#include <ctime>
#include <iomanip>


class CapaDePresentacio
{
public:
	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}
	void iniciSessio();
	void tancaSessio();
	void registrarUsuari();
	void consultaUsuari();
	void modificaUsuari();
	void esborraUsuari();
	void comprarVideojoc();
	void comprarPaquet();
	void consultaVideojoc();
	void consultaVideojocs();
	void consultaPaquet();
	void consultaPaquets();
	void consultaNovetatsVideojocs();
	void consultaCompres();
	void consultaVQualificacioEdat();
private:
	CapaDePresentacio() {}
};