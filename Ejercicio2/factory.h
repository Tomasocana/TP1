#pragma once

#include "Ejercicio1/armas.h"
#include "Ejercicio1/personajes.h"
#include <memory>

using namespace std;

class PersonajeFactory {
    public:
        // Crea un personaje dinámicamente según el tipo especificado
        static shared_ptr<personajes> pjCreation(const string& tipoPJ); 

        // Crea un arma dinámicamente según el tipo especificado
        static vector<shared_ptr<armas>> wpCreation(const string& tipoWP, const int cant_armas, const string& tipoWP2 = ""); 

        // Crea un personaje armado dinámicamente
        static shared_ptr<personajes> armedPJCreation(const string& tipoPJ, const string& tipoWP, const int cant_armas, const string& tipoWP2 = ""); 
    };