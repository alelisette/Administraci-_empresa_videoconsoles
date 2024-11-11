#pragma once
#include "TxConsultaVideojoc.h"
#include "TxNovaCompra.h"
#include "PassarellaElemCompra.h"
#include "TxJocsRelacionats.h"

class CtrCompraVideojoc
{
public:
	CtrCompraVideojoc() {}
	infoVid consultarVideojoc(std::string nomV);
	void comprarVideojoc();
	std::vector<infoElem> videojocsRelacionats();
private:
	PassarellaElemCompra _elem;
};
