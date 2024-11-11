#include <iostream>
#include "Conexio.h"
#include "Videoconsola.h"
#include "CapaDePresentacio.h"

void gestionar_usuari() {
	// Menú de gestionar usuari
	std::cout << "------------------" << std::endl;
	std::cout << "  Gestionar usuari" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "1. Consultar usuari" << std::endl;
	std::cout << "2. Modificar usuari" << std::endl;
	std::cout << "3. Esborrar usuari" << std::endl;
	std::cout << "4. Tornar" << std::endl;
	std::cout << "Opcio: ";
	int op;
	std::cin >> op;
	std::cout << std::endl;
	while (op > 4 or op < 1) {
		std::cin >> op;
		std::cout << std::endl;
	}

	CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
	switch (op) {
	case 1:
		presentacio.consultaUsuari();
		break;
	case 2:
		presentacio.modificaUsuari();
		break;
	case 3:
		presentacio.esborraUsuari();
		break;
	}

}

void gestionar_compres() {
	// Menú de gestionar compres
	std::cout << "------------------" << std::endl;
	std::cout << "  Gestionar compres" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "1. Comprar videojoc" << std::endl;
	std::cout << "2. Comprar paquet videojocs" << std::endl;
	std::cout << "3. Consultar compres" << std::endl;
	std::cout << "4. Tornar" << std::endl;
	std::cout << "Opcio: ";
	int op;
	std::cin >> op;
	std::cout << std::endl;
	while (op > 4 or op < 1) {
		std::cin >> op;
		std::cout << std::endl;
	}

	CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
	switch (op) {
	case 1:
		presentacio.comprarVideojoc();
		break;
	case 2:
		presentacio.comprarPaquet();
		break;
	case 3:
		presentacio.consultaCompres();
		break;
	}

}

void consultar() {
	// Menú de consultes videojocs
	std::cout << "-----------------------" << std::endl;
	std::cout << "  Consultes videojocs" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "1. Consultar videjoc" << std::endl;
	std::cout << "2. Consultar videojocs" << std::endl;
	std::cout << "3. Consultar videojocs per edat" << std::endl;
	std::cout << "4. Consultar novetats videojocs" << std::endl;
	std::cout << "5. Consultar paquet videojocs" << std::endl;
	std::cout << "6. Consultar paquets videojocs" << std::endl;
	std::cout << "7. Tornar" << std::endl;
	std::cout << "Opcio: ";
	int op;
	std::cin >> op;
	std::cout << std::endl;
	while (op > 7 or op < 1) {
		std::cin >> op;
		std::cout << std::endl;
	}

	CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
	switch (op) {
	case 1:
		presentacio.consultaVideojoc();
		break;
	case 2:
		presentacio.consultaVideojocs();
		break;
	case 3:
		presentacio.consultaVQualificacioEdat();
		break;
	case 4:
		presentacio.consultaNovetatsVideojocs();
		break;
	case 5:
		presentacio.consultaPaquet();
		break;
	case 6:
		presentacio.consultaPaquets();
		break;
	}
}



int main() {
	// Generar la connexio demanant les dades
	// ----------------------------------------------------------
	std::string d, u, pa, h, p;
	std::cout << "Dades necessaries per generar la connexio amb la base de dades: " << std::endl;
	std::cout << "dbname= ";
	std::cin >> d;
	std::cout << "user= ";
	std::cin >> u;
	std::cout << "password= ";
	std::cin >> pa;
	std::cout << "hostaddr= ";
	std::cin >> h;
	std::cout << "port= ";
	std::cin >> p;
	Conexio& con = Conexio::getInstance();
	con.inicialitzar_atributs(d, u, pa, h, p);
	// ------------------------------------------------------------
	CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
	bool sortir = false;
	while (not sortir) {
		Videoconsola& videoconsola = Videoconsola::getInstance();
		if ((videoconsola.obteUsuari()).obteSobrenom() == "") {
			std::cout << "******************" << std::endl;
			std::cout << "  Menu Principal" << std::endl;
			std::cout << "******************" << std::endl;
			std::cout << "1. Iniciar sessio" << std::endl;
			std::cout << "2. Registrar usuari" << std::endl;
			std::cout << "3. Sortir" << std::endl;
			std::cout << "Opcio: ";
			int op;
			std::cin >> op;
			switch (op) {
			case 1:
				presentacio.iniciSessio();
				break;
			case 2:
				presentacio.registrarUsuari();
				break;
			case 3:
				sortir = true;
				break;
			default:
				std::cout << "Opcio incorrecta" << std::endl;
			}
		}
		else {
			std::cout << "******************" << std::endl;
			std::cout << "  Menu Principal" << std::endl;
			std::cout << "******************" << std::endl;
			std::cout << "1. Gestionar usuari" << std::endl;
			std::cout << "2. Gestionar compres" << std::endl;
			std::cout << "3. Consultar" << std::endl;
			std::cout << "4. Tancar sessio" << std::endl;
			std::cout << "5. Sortir" << std::endl;
			std::cout << "Opcio: ";
			int op;
			std::cin >> op;
			switch (op) {
			case 1:
				gestionar_usuari();
				break;
			case 2:
				gestionar_compres();
				break;
			case 3:
				consultar();
				break;
			case 4:
				presentacio.tancaSessio();
				break;
			case 5:
				sortir = true;
				break;
			default:
				std::cout << "Opcio incorrecta" << std::endl;
			}

		}

	}
}