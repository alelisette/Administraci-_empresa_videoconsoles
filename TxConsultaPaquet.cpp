#include "TxConsultaPaquet.h"

TxConsultaPaquet::TxConsultaPaquet(std::string nom) {
	_nom = nom;
}
void TxConsultaPaquet::executar() {
	CercadoraElemCompra aux;
	try {
		PassarellaElemCompra p = aux.cercaElement(_nom);
		_resultat.nom = p.obteNom();
		_resultat.descripcio = p.obteDescripcio();
		_resultat.preu = p.obtePreu();
		_resultat.preuTJ = 0;
		_elem_compra = p;
		if(p.obteTipus()!="paquet") throw std::runtime_error("Error cerca Paquet");
		CercadoraConte aux2;
		std::vector<PassarellaConte> elem = aux2.cercaConteP(_nom);
		for (int i = 0; i < elem.size(); i++) {
			PassarellaElemCompra pE = aux.cercaElement(elem[i].obteVideojoc());
			std::string nom = (elem[i].obteVideojoc());
			std::string des = pE.obteDescripcio();
			double preu = pE.obtePreu();
			infoElem e;
			e.nom = nom;
			e.descripcio = des;
			e.preu = preu;
			_resultat.preuTJ += preu;
			(_resultat.videojoc).push_back(e);
		}
	}
	catch (const pqxx::sql_error& e) {
		throw std::runtime_error("Error cerca Paquet");
	}
}

infoP TxConsultaPaquet::obteResultat() {
	return _resultat;
}
std::string TxConsultaPaquet::obteNom() {
	return _nom;
}

PassarellaElemCompra TxConsultaPaquet::obteElementP() {
	return _elem_compra;
}
