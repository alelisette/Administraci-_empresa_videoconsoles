#pragma once
#include "PassarellaUsuari.h"

class CercadoraUsuari
{
public:
	CercadoraUsuari() {};
	PassarellaUsuari cercaUsuari(std::string sobrenomU); //excepcio:UsuariNoExisteix
};