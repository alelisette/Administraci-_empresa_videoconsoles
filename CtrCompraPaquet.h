#pragma once
#include "TxNovaCompra.h"
#include "TxConsultaPaquet.h"

class CtrCompraPaquet
{
public:
	CtrCompraPaquet() {}
	infoP consultarPaquet(std::string nomP);
	void comprarPaquet();

private:
	PassarellaElemCompra _elem;
};

