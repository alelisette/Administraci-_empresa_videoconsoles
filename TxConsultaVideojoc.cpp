#include "TxConsultaVideojoc.h"

TxConsultaVideojoc::TxConsultaVideojoc(std::string nom) {
	_nom = nom;
}

void TxConsultaVideojoc::executar() {
	CercadoraVideojoc aux;
	try {
		PassarellaVideojoc v = aux.cercaVideojoc(_nom);
		_resultat.nom = v.obteNom();
		_resultat.genere = v.obteGenere();
		_resultat.qualificacio_edat = v.obteQualificacioEdat();
		_resultat.data_llansament = v.obteDataLLansament();
		_resultat.mins_estimats = v.obteMinsEstimats();
		CercadoraElemCompra aux2;
		PassarellaElemCompra elem = aux2.cercaElement(_nom);
		_elem_compra = elem;
		_resultat.descripcio = elem.obteDescripcio();
		_resultat.preu = elem.obtePreu();
		CercadoraConte aux3;
		std::vector<PassarellaConte> vC = aux3.cercaConte(_nom);
		for (int i = 0; i < vC.size(); i++) {
			//std::cout << vC[i].obtePaquet() << std::endl;
			_resultat.nom_paquets.push_back(vC[i].obtePaquet());
		}
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error cerca Videojoc");
	}

}

infoVid TxConsultaVideojoc::obteResultat() {
	return _resultat;
}

PassarellaElemCompra TxConsultaVideojoc::obteElement() {
	return _elem_compra;
}