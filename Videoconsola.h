#pragma once
#include <iostream>
#include "PassarellaUsuari.h"

class Videoconsola
{
private:
    // Atributos
    PassarellaUsuari _usuari;

    // Constructor privat per prevenir la creaci� d'inst�ncies, la inst�ncia es crea a la operaci� getInstance()
    Videoconsola() {

    }

public:
    // M�tode per obtenir la �nica inst�ncia d'aquesta classe (ha de ser static i estar a .h)
    static Videoconsola& getInstance() {
        static Videoconsola instance;
        return instance;
    }

    // M�todes per obtenir i modificar els atributs (getters/setters)
    PassarellaUsuari& obteUsuari();
    void iniciar_sessio(PassarellaUsuari u);
    void tanca_sessio();
};
