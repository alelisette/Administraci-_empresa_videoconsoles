#include "CapaDePresentacio.h"

void CapaDePresentacio::iniciSessio() {
	std::cout << "** Inici sessio **" << std::endl;
	std::string sU, cU;
	std::cout << "Sobrenom: ";
	std::cin >> sU;
	std::cout << "Contrasenya: ";
	std::cin >> cU;
	TxIniciSessio txIS(sU, cU);
	try {
		txIS.executar();
		std::cout << "Sessio iniciada correctament!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Hi ha hagut un error amb el sobrenom o la contrasenya" << std::endl;
	}
}

void CapaDePresentacio::registrarUsuari() {
	std::string nU, sU, cU, ceU, dnU;
	std::cout << "** Registra usuari **" << std::endl;
	std::cout << "Omplir la informacio que es demana ..." << std::endl;
	std::cout << "Nom complet: ";
	std::cin >> nU;
	std::cout << "Sobrenom: ";
	std::cin >> sU;
	std::cout << "Contrasenya: ";
	std::cin >> cU;
	std::cout << "Correu electronic:" << std::endl;
	std::cin >> ceU;
	std::cout << "Data naixement (AAAA/MM/DD):" << std::endl;
	std::cin >> dnU;
	TxRegistraUsuari txRU(nU, sU, cU, ceU, dnU);
	try {
		txRU.executar();
		std::cout << "Nou usuari registrat correctament!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Hi ha hagut un error amb el registre" << std::endl;
	}
}

void CapaDePresentacio::tancaSessio() {
	std::cout << "** Tancar Sessio **" << std::endl;
	std::cout << "Vols tancar la sessio? (S/N):" << std::endl;
	char tanca;
	std::cin >> tanca;
	if (tanca == 'S') {
		TxTancaSessio TxTS;
		TxTS.executar();
		std::cout << "Sessio tancada correctament!" << std::endl;
	}
}

void CapaDePresentacio::consultaUsuari() {
	std::cout << "** Consulta usuari **" << std::endl;
	TxConsultaUsuari txCU;
	try {
		txCU.executar();
		infoUsu auxU = txCU.obteResultat();
		TxInfoCompres txIC;
		txIC.executar();
		infoCom auxC = txIC.obteResultat();
		std::cout << "Nom complet: " << auxU.nom << std::endl;
		std::cout << "Sobrenom: " << auxU.sobrenom << std::endl;
		std::cout << "Correu electronic: " << auxU.correu << std::endl;
		std::cout << "Data naixement  (DD/MM/AAAA): " << auxU.dataN << std::endl;
		std::cout << std::endl;
		std::cout << auxC.totalVideojocs << " videojocs comprats" << std::endl;
		std::cout << auxC.totalPaquets << " paquets de videojocs comprats" << std::endl;
		std::cout << auxC.totalEuros << " euros gastats en total" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Hi ha hagut un error amb la consulta" << std::endl;
	}
}

void CapaDePresentacio::modificaUsuari() {
	std::cout << "** Modifica Usuari **" << std::endl;
	CtrModificaUsuari ctrMU;
	try {
		infoUsu auxU = ctrMU.consultaUsuari();
		std::cout << "Nom complet: " << auxU.nom << std::endl;
		std::cout << "Sobrenom: " << auxU.sobrenom << std::endl;
		std::cout << "Correu electronic: " << auxU.correu << std::endl;
		std::cout << "Data naixement  (DD/MM/AAAA): " << auxU.dataN << std::endl;
		std::cout << std::endl;
		std::cin.get();
		std::cout << "Omplir la informacio que es vol modificar ..." << std::endl;
		std::cout << "Nom complet: ";
		std::string nom;
		std::getline(std::cin, nom);
		std::cout << "Contrasenya: ";
		std::string contrasenya;
		std::getline(std::cin, contrasenya);
		std::cout << "Correu electronic: ";
		std::string correu;
		std::getline(std::cin, correu);
		std::cout << "Data naixement (DD/MM/AAAA): ";
		std::string data;
		std::getline(std::cin, data);
		std::cin.get();
		try {
			ctrMU.modificaUsuari(nom, contrasenya, correu, data);
			infoUsu auxM = ctrMU.consultaUsuari();
			std::cout << "** Dades usuari modificades **" << std::endl;
			std::cout << "Nom complet: " << auxM.nom << std::endl;
			std::cout << "Sobrenom: " << auxM.sobrenom << std::endl;
			std::cout << "Correu electronic: " << auxM.correu << std::endl;
			std::cout << "Data naixement  (DD/MM/AAAA): " << auxM.dataN << std::endl;
			std::cout << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "El correu electrònic ja existeix" << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cout << "Hi ha hagut un error amb el modifica" << std::endl;
	}
}

void CapaDePresentacio::esborraUsuari() {
	std::cout << "** Esborrar usuari **" << std::endl;
	std::cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya..." << std::endl;
	std::cout << "Contrasenya: ";
	std::string cont;
	std::cin >> cont;
	try {
		TxEsborraUsuari txEU(cont);
		txEU.executar();
		std::cout << "Usuari esborrat correctament!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "La contrasenya no és correcta " << std::endl;
	}
}

std::string obtenerFechaHoraActual() {
	// Obtener el tiempo actual
	std::time_t tiempoActual = std::time(0);

	std::tm tiempoLocal = {};
	if (localtime_s(&tiempoLocal, &tiempoActual) != 0) {
		throw std::runtime_error("Error al obtener la fecha y hora local");
	}

	// Obtener el día, mes y año actual
	int diaActual = tiempoLocal.tm_mday;
	int mesActual = tiempoLocal.tm_mon + 1;  
	int anioActual = tiempoLocal.tm_year + 1900; 

	// Obtener la hora y los minutos actuales
	int horaActual = tiempoLocal.tm_hour;
	int minutoActual = tiempoLocal.tm_min;

	// Crear un string con el formato "dd/mm/yyyy hh:mm"
	std::string strFechaHoraActual = std::to_string(diaActual) + "/" + std::to_string(mesActual) + "/" + std::to_string(anioActual) +
		" " + std::to_string(horaActual) + ":" + std::to_string(minutoActual);

	return strFechaHoraActual;
}

void CapaDePresentacio::comprarVideojoc() {
	std::cout << "** Comprar videojoc **" << std::endl;
	std::cout << "Nom videojoc: " << std::endl;
	std::string nomV;
	std::cin >> nomV;
	CtrCompraVideojoc ctrCV;
	try {
		infoVid res = ctrCV.consultarVideojoc(nomV);
		std::cout << "Informacio videojoc..." << std::endl;
		std::cout << "Nom videojoc: " << res.nom << std::endl;
		std::cout << "Descripcio: " << res.descripcio << std::endl;
		std::cout << "Qualificacio edat: " << res.qualificacio_edat << std::endl;
		std::cout << "Genere: " << res.genere << std::endl;
		std::cout << "Data Llansament: " << res.data_llansament << std::endl;
		if (res.mins_estimats != 0) std::cout << "Temps estimat: " << res.mins_estimats << std::endl; //FALTA VEURE QUE PASSA QUAN NO TE
		std::cout << "Preu: " << res.preu << std::endl;
		std::cout << "Vols continuar amb la compra (S/N):";
		std::string aux;
		std::cin >> aux;
		if (aux == "S") {
			try {
				ctrCV.comprarVideojoc();
				std::string fechaHoraActual = obtenerFechaHoraActual();
				std::cout << "Compra registrada: " << fechaHoraActual << std::endl;
				std::cout << "Jocs relacionats:" << std::endl;
				vector<infoElem> ie = ctrCV.videojocsRelacionats();
				for (int i = 0; i < ie.size(); i++) {
					std::cout << "- " << ie[i].nom << "; " << ie[i].descripcio << "; " << ie[i].preu << std::endl;
				}
			}
			catch (const std::exception& e) {
				std::cout << "El videojoc ja l'has comprat" << std::endl;
			}

		}
	}
	catch (const std::exception& e) {
		std::cout << "El videojoc no existeix" << std::endl;
	}
}

void CapaDePresentacio::comprarPaquet() {
	std::cout << "** Comprar paquet **" << std::endl;
	std::string nomP;
	cin >> nomP;
	CtrCompraPaquet ctrCV;
	try {
		infoP res = ctrCV.consultarPaquet(nomP);
		std::cout << "Informacio paquet ..." << std::endl;
		std::cout << "Nom paquet: " << res.nom << std::endl;
		std::cout << "Descripcio: " << res.descripcio << std::endl;
		std::cout << "Preu: " << res.preu << "(estalvi de " << res.preuTJ - res.preu << " euros)" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < res.videojoc.size(); i++) {
			std::cout << "- " << res.videojoc[i].nom << "; " << res.videojoc[i].descripcio << "; " << res.videojoc[i].preu << std::endl;
		}
		std::cout << "Vols continuar amb la compra (S/N):";
		std::string aux;
		std::cin >> aux;
		if (aux == "S") {
			try {
				ctrCV.comprarPaquet();
				std::string fechaHoraActual = obtenerFechaHoraActual();
				std::cout << "Compra registrada: " << fechaHoraActual << std::endl;
			}
			catch (const std::exception& e) {
				std::cout << "El paquet ja l'has comprat" << std::endl;
			}
		}
	}
	catch (const std::exception& e) {
		std::cout << "El Paquet no existeix" << std::endl;
	}
}


void CapaDePresentacio::consultaVideojoc() {

	std::cout << "** Consulta videojoc **" << std::endl;
	std::cout << "Nom videojoc: " << std::endl;
	std::string nomV;
	std::cin >> nomV;
	TxConsultaVideojoc txCV(nomV);
	try {
		txCV.executar();
		infoVid res = txCV.obteResultat();
		std::cout << "Informacio videojoc..." << std::endl;
		std::cout << "Nom videojoc: " << res.nom << std::endl;
		std::cout << "Descripcio: " << res.descripcio << std::endl;
		std::cout << "Qualificacio edat: " << res.qualificacio_edat << std::endl;
		std::cout << "Genere: " << res.genere << std::endl;
		std::cout << "Data Llansament: " << res.data_llansament << std::endl;
		if (res.mins_estimats != 0) std::cout << "Temps estimat: " << res.mins_estimats << std::endl; //FALTA VEURE QUE PASSA QUAN NO TE
		std::cout << "Preu: " << res.preu << std::endl;
		std::cout << "Paquets on esta inclos:";
		for (int i = 0; i < res.nom_paquets.size(); i++) {
			std::cout << " " << res.nom_paquets[i];
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "El videojoc no existeix" << std::endl;
	}
}

void CapaDePresentacio::consultaVideojocs() {
	std::cout << "** Consulta videojocs **" << std::endl;
	TxConsultaVideojocs txCV;
	txCV.executar();
	vector<infoVids> res = txCV.obteResultat();
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i].nom << "; " << res[i].descripcio << "; " << res[i].preu << " euros; " << res[i].qualificacio_edat << " PEGI;" << res[i].genere << "; " << res[i].data_llansament << "; ";
		if (res[i].mins_estimats != 0) std::cout << res[i].mins_estimats << " mins; ";
		std::cout << "Paquets:";
		for (int j = 0; j < res[i].nom_paquets.size(); j++) {
			std::cout << " " << res[i].nom_paquets[j];
		}
		std::cout << std::endl;
	}
}


void CapaDePresentacio::consultaPaquet() {
	std::cout << "** Consulta paquet **" << std::endl;
	std::string nomP;
	cin >> nomP;
	TxConsultaPaquet txCP(nomP);
	try {
		txCP.executar();
		infoP res = txCP.obteResultat();
		std::cout << "Informacio paquet ..." << std::endl;
		std::cout << "Nom paquet: " << res.nom << std::endl;
		std::cout << "Descripcio: " << res.descripcio << std::endl;
		std::cout << "Preu: " << res.preu << "(estalvi de " << res.preuTJ - res.preu << " euros)" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < res.videojoc.size(); i++) {
			std::cout << "- " << res.videojoc[i].nom << "; " << res.videojoc[i].descripcio << "; " << res.videojoc[i].preu << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cout << "El Paquet no existeix" << std::endl;
	}
}

void CapaDePresentacio::consultaPaquets() {
	std::cout << "** Consulta Paquets **" << std::endl;
	TxConsultaPaquets txCP;
	txCP.executar();
	std::vector<infoPs> res = txCP.obteResultat();
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i].nom << "; " << res[i].descripcio << "; " << res[i].preu << " euros (estalvi " << res[i].preuTJ <<" euros)"<< std::endl;
	}
}

void CapaDePresentacio::consultaNovetatsVideojocs() {
	std::cout << "** Consulta novetats **" << std::endl;
	std::cout << "Data (DD/MM/AAAA): " << std::endl;
	std::string data_llansamentV;
	std::cin.ignore();
	std::getline(std::cin, data_llansamentV);
	TxConsultarNovetatsVideojocs txCNV(data_llansamentV);
	try {
		txCNV.executar();
		std::vector<infoVidN> res = txCNV.obteResultat();
		for (int i = 0; i < res.size(); i++) {
			std::cout << res[i].nom << "; " << res[i].descripcio << "; " << res[i].preu << " euros; " << res[i].qualificacio_edat << " PEGI;" << res[i].genere << "; " << res[i].data_llansament << "; ";
			if (res[i].mins_estimats != 0) std::cout << res[i].mins_estimats << " mins; ";
			std::cout << "Paquets:";
			for (int j = 0; j < res[i].nom_paquets.size(); j++) {
				std::cout << " " << res[i].nom_paquets[j];
			}
			std::cout << std::endl;
		}
	}
	catch (const pqxx::sql_error& e) {
		std::cout << "No hi ha cap videojoc previst" << std::endl;
	}
}


void CapaDePresentacio::consultaCompres() {
	std::cout << "** Consulta compres **" << std::endl;
	double preuT = 0;
	TxConsultaCompres txCC;
	txCC.executar();
	vector<infoC> sol = txCC.obteResultat();
	for (int i = sol.size()-1; i >= 0; i--) {
		preuT += sol[i].preu;
		std::cout << sol[i].data << " :";
		if (sol[i].videojoc.size() == 0) {
			std::cout << " videojoc " << sol[i].nom << "; " << sol[i].descripcio << "; " << sol[i].preu << " euros" << std::endl;
		}
		else {
			std::cout << " paquet " << sol[i].nom << "; " << sol[i].descripcio << "; " << sol[i].preu << " euros" << std::endl;
			std::cout << "   Videojocs:" << std::endl;
			for (int j = 0; j < sol[i].videojoc.size(); j++) {
				std::cout << "      " << sol[i].videojoc[j].nom << "; " << sol[i].videojoc[j].descripcio << std::endl;
			}
		}
	}
	std::cout << "Total: " << preuT << std::endl;
}

void CapaDePresentacio::consultaVQualificacioEdat() {
	std::cout << "** Consulta videojocs per edat **" << std::endl;
	std::cout << "Edat maxima (anys): " << std::endl;
	int e;
	std::string edat;
	std::cin >> e;
	if (e <= 0) std::cout << "Edat incorrecta" << std::endl;
	else {
		edat = std::to_string(e);
		TxCVQualificacioEdat txCVQE(edat);
		std::cout << "** Consulta videojocs fins a: " << edat << " anys **" << std::endl;
		try {
			txCVQE.executar();
			std::vector<infoVidE> res = txCVQE.obteResultat();
			for (int i = 0; i < res.size(); ++i) {
				std::cout << res[i].nom << "; " << res[i].descripcio << "; " << res[i].preu << "; ";
				std::cout << res[i].qualificacio_edat << " PEGI; " << res[i].genere << "; " << res[i].data_llansament << "; ";
				if (res[i].mins_estimats != 0) std::cout << "estimacio temps joc: " << res[i].mins_estimats << " minuts " << "; "; //FALTA VEURE QUE PASSA QUAN NO TE
				std::cout << "Paquets:";
				for (int j = 0; j < res[i].nom_paquets.size(); j++) {
					std::cout << " " << res[i].nom_paquets[j];
				}
				std::cout << std::endl;
			}
		}
		catch (const pqxx::sql_error& e) {
			std::cout << "No hi ha cap videojoc previst" << std::endl;
		}
	}
}
