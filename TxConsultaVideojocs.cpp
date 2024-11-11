#include "TxConsultaVideojocs.h"


void TxConsultaVideojocs::executar() {
	CercadoraVideojoc aux;
	try {
		std::vector<PassarellaVideojoc> v = aux.cercaVideojocs();
		for (int i = 0; i < v.size(); i++) {
			infoVids a;
			a.nom = v[i].obteNom();
			a.genere = v[i].obteGenere();
			a.qualificacio_edat = v[i].obteQualificacioEdat();
			a.data_llansament = v[i].obteDataLLansament();
			a.mins_estimats = v[i].obteMinsEstimats();
			CercadoraElemCompra aux2;
			PassarellaElemCompra elem = aux2.cercaElement(a.nom);
			a.descripcio = elem.obteDescripcio();
			a.preu = elem.obtePreu();
			CercadoraConte aux3;
			std::vector<PassarellaConte> vC = aux3.cercaConte(a.nom);
			for (int j = 0; j < vC.size(); j++) {
					//std::cout << vC[i].obtePaquet() << std::endl;
					a.nom_paquets.push_back(vC[j].obtePaquet());
			}
			_resultat.push_back(a);
		}
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error cerca Videojoc");
	}

}

std::vector<infoVids> TxConsultaVideojocs::obteResultat() {
	return _resultat;
}