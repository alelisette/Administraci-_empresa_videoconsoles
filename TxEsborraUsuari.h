#include "PassarellaUsuari.h"
#include "Videoconsola.h"

class TxEsborraUsuari
{
public:

	TxEsborraUsuari(std::string contraU); //creadora
	void executar();

private:
	std::string _contraU;
};
