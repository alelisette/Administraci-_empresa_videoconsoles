#pragma once
#include "PassarellaUsuari.h"
#include "Videoconsola.h"

struct infoUsu	//infoUsu=resultat dins del diagrama de classes
{
	std::string nom;
	std::string sobrenom;
	std::string correu;
	std::string dataN;
};


class TxConsultaUsuari
{
public:
	// creadora i detructora
	TxConsultaUsuari();

	void executar();

	infoUsu obteResultat();

	PassarellaUsuari obteUsuari();

	//getters i setters no se si fa falta xd ja que son especials i ja els hem posat abans

private:
	infoUsu _resultat;
	PassarellaUsuari _usuari;
};