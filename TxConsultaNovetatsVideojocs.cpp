#include "TxConsultaNovetatsVideojocs.h"


TxConsultarNovetatsVideojocs::TxConsultarNovetatsVideojocs(std::string data_llansament) {
	_data_llansament = data_llansament;
}

void TxConsultarNovetatsVideojocs::executar() {
	CercadoraVideojoc aux;
	try {
		std::vector<PassarellaVideojoc> v = aux.cercaNovetatsVideojocs(_data_llansament);
		infoVidN vid;
		for (int i = 0; i < v.size(); ++i) {
			_resultat.push_back(vid); ///
			_resultat[i].nom = v[i].obteNom();
			_resultat[i].genere = v[i].obteGenere();
			_resultat[i].qualificacio_edat = v[i].obteQualificacioEdat();
			_resultat[i].data_llansament = v[i].obteDataLLansament();
			_resultat[i].mins_estimats = v[i].obteMinsEstimats(); //Vigilar aixo pot ser null
			//std::cout << _resultat[i].nom << "  " << _resultat[i].genere << "  " << _resultat[i].qualificacio_edat << "  " << _resultat[i].data_llansament << "  " << _resultat[i].mins_estimats << std::endl;
			CercadoraElemCompra aux2;
			//std::cout << "Cerca element" << std::endl;
			PassarellaElemCompra elem = aux2.cercaElement(_resultat[i].nom);
			_resultat[i].descripcio = elem.obteDescripcio();
			_resultat[i].preu = elem.obtePreu();
			//std::cout << _resultat[i].descripcio << " " << _resultat[i].preu << std::endl;
			CercadoraConte aux3;
			try {
				//std::cout << "Cercadora conte" << std::endl;
				std::vector<PassarellaConte> vC = aux3.cercaConte(_resultat[i].nom);
				for (int j = 0; j < vC.size(); j++) {
					//std::cout << vC[i].obtePaquet() << std::endl;
					_resultat[i].nom_paquets.push_back(vC[j].obtePaquet());
				}
			}
			catch (const pqxx::sql_error& e) {
				std::cout << "No hi ha cap paquet que contingui aquest videojoc." << std::endl;
			}
		}
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error cerca Videojoc");
	}

}

std::vector<infoVidN> TxConsultarNovetatsVideojocs::obteResultat() {
	return _resultat;
}

