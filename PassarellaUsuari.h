#pragma once
#include "Conexio.h"

class PassarellaUsuari
{
public:

	PassarellaUsuari(); //creadora
	PassarellaUsuari(std::string nomU, std::string sobrenomU, std::string contrasenyaU, std::string correuElectronicU, std::string dataNaixementU);
	PassarellaUsuari& operator=(const PassarellaUsuari& other);
	//getters i setters per si de cas menys el de SOBRENOM ja q no es pot modificar? o el possem per si de cas? hauria de fer una excep qui la crida en cas q fos el mateix
	std::string obteNom();
	std::string obteSobrenom();
	std::string obteContrasenya();
	std::string obtecorreuElectronic();
	std::string obtedataNaixement();

	void posaNom(std::string nom);
	void posaContrasenya(std::string contrasenya);
	void posaCorreuElectronic(std::string correuElectronic);
	void posaDataNaixement(std::string dataNaixement);

	//Altres mes elaborades i especials
	void insereix(); //exc:UsuariExisteix or CorreuExisteix
	void modifica(); //exc: UsuariNoExisteix
	void esborra();  //exc:UsuariNoExisteix


private:
	std::string _nom;
	std::string _sobrenom;
	std::string _contrasenya;
	std::string _correuElectronic;
	std::string _dataNaixement;

};

