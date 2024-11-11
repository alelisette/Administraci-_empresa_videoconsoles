#pragma once
#include "CercadoraUsuari.h"
#include "Videoconsola.h"

class TxIniciSessio
{
public:
    TxIniciSessio(std::string snU, std::string conU); //creadora de la classe, es crear
    void executar(); //operacio concreta de la subclase heredada de la superclase Transaccio 

private:
    std::string _sobrenomU;
    std::string _contrasenyaU;
};

