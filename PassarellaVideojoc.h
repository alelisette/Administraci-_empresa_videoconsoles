#pragma once
#include<iostream>

class PassarellaVideojoc
{
public:
	PassarellaVideojoc() {}; //constructora
	PassarellaVideojoc(std::string nom, std::string genere, int qualificacio_edat, std::string data_llansament, int mins_estimats);
	PassarellaVideojoc& operator=(const PassarellaVideojoc& other);

	std::string obteNom();
	std::string obteGenere();
	int obteQualificacioEdat();
	std::string obteDataLLansament();
	int obteMinsEstimats();

private:
	std::string _nom;
	std::string _genere;
	int _qualificacio_edat;
	std::string _data_llansament;
	int _mins_estimat;
};
