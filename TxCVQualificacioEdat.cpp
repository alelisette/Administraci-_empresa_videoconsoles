#include "TxCVQualificacioEdat.h"

TxCVQualificacioEdat::TxCVQualificacioEdat(std::string edat) {
	_edat = edat;
}

void TxCVQualificacioEdat::executar() {
	CercadoraVideojoc aux;
	try {
		std::vector<PassarellaVideojoc> v = aux.cercaVQualificacioEdat(_edat);
		infoVidE vid;
		for (int i = 0; i < v.size(); ++i) {
			_resultat.push_back(vid);
			_resultat[i].nom = v[i].obteNom();
			_resultat[i].genere = v[i].obteGenere();
			_resultat[i].qualificacio_edat = v[i].obteQualificacioEdat();
			_resultat[i].data_llansament = v[i].obteDataLLansament();
			_resultat[i].mins_estimats = v[i].obteMinsEstimats(); //Vigilar aixo pot ser null
			CercadoraElemCompra aux2;
			PassarellaElemCompra elem = aux2.cercaElement(_resultat[i].nom);
			_resultat[i].descripcio = elem.obteDescripcio();
			_resultat[i].preu = elem.obtePreu();
			CercadoraConte aux3;
			try {
				std::vector<PassarellaConte> vC = aux3.cercaConte(_resultat[i].nom);
				for (int j = 0; j < vC.size(); j++) {
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

std::vector<infoVidE> TxCVQualificacioEdat::obteResultat() {
	return _resultat;
}