#pragma once
#include "Videoconsola.h"
#include "CercadoraCompres.h"
#include "CercadoraElementCompra.h"
#include "PassarellaCompra.h"
#include "PassarellaELemCompra.h"
#include<vector>

struct infoCom	//infoUsu=resultat dins del diagrama de classes
{
	int totalPaquets=0;
	int totalVideojocs=0;
	double totalEuros=0;
};


class TxInfoCompres
{
private:
	infoCom resultat;
public:
	TxInfoCompres();
	void executar();
	infoCom obteResultat();
};
