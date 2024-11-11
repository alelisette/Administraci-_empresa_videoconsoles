#pragma once
#include <iostream>
#include "PassarellaUsuari.h"

class Videoconsola
{
private:
    // Atributos
    PassarellaUsuari _usuari;

    // Constructor privat per prevenir la creació d'instàncies, la instància es crea a la operació getInstance()
    Videoconsola() {

    }

public:
    // Mètode per obtenir la única instància d'aquesta classe (ha de ser static i estar a .h)
    static Videoconsola& getInstance() {
        static Videoconsola instance;
        return instance;
    }

    // Mètodes per obtenir i modificar els atributs (getters/setters)
    PassarellaUsuari& obteUsuari();
    void iniciar_sessio(PassarellaUsuari u);
    void tanca_sessio();
};
