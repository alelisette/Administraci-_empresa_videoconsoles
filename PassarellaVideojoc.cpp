#include "PassarellaVideojoc.h"


PassarellaVideojoc::PassarellaVideojoc(std::string nom, std::string genere, int qualificacio_edat, std::string data_llansament, int mins_estimats) {
    _nom = nom;
    _genere = genere;
    _qualificacio_edat = qualificacio_edat;
    _data_llansament = data_llansament;
    _mins_estimat = mins_estimats;
}
PassarellaVideojoc& PassarellaVideojoc::operator=(const PassarellaVideojoc& other) {
    _nom = other._nom;
    _genere = other._genere;
    _qualificacio_edat = other._qualificacio_edat;
    _data_llansament = other._data_llansament;
    _mins_estimat = other._mins_estimat;
    return *this;
}
std::string PassarellaVideojoc::obteNom() {
    return _nom;
}
std::string PassarellaVideojoc::obteGenere() {
    return _genere;
}
int PassarellaVideojoc::obteQualificacioEdat() {
    return _qualificacio_edat;
}
std::string PassarellaVideojoc::obteDataLLansament() {
    return _data_llansament;
}
int PassarellaVideojoc::obteMinsEstimats() {
    return _mins_estimat;
}