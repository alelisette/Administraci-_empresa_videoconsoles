#include "PassarellaConte.h"

PassarellaConte::PassarellaConte(std::string nomP, std::string nomV) {
	_nomP = nomP;
	_nomV = nomV;
}
PassarellaConte& PassarellaConte::operator=(const PassarellaConte& other) {
	_nomP = other._nomP;
	_nomV = other._nomV;
	return *this;
}

std::string PassarellaConte::obtePaquet() {
	return _nomP;
}
std::string PassarellaConte::obteVideojoc() {
	return _nomV;
}