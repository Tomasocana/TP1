#include "factory.h"

shared_ptr<personajes> PersonajeFactory::pjCreation(const string& tipo){
    if (tipo == "Hechicero") {
        return make_shared<Hechicero>();
    } else if (tipo == "conjurador") {
        return make_shared<conjurador>();
    } else if (tipo == "brujo") {
        return make_shared<brujo>();
    } else if (tipo == "nigromante") {
        return make_shared<nigromante>();
    } else if (tipo == "barbaro") {
        return make_shared<barbaro>();
    } else if (tipo == "paladin") {
        return make_shared<paladin>();
    } else if (tipo == "caballero") {
        return make_shared<caballero>();
    } else if (tipo == "mercenario") {
        return make_shared<mercenario>();
    } else if (tipo == "gladiador") {
        return make_shared<gladiador>();
    } else {
        throw invalid_argument("Tipo de personaje no reconocido.");
    }
}

shared_ptr<armas> PersonajeFactory::wpCreation(const string& tipoPersonaje, const int j) {
    string MagicWp[] = {"varita", "LibroHechizos", "PocionDeVida", "AmuletoDeVida"};
    string meleeWp[] = {"Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
    for(int i = 0; i < j; i++){
        int randomWp = (rand() / RAND_MAX) * (7 - 3) + 3;
        string tipo = MagicWp[randomWp];
        if (tipo == "varita") {
            return make_shared<varita>();
        } else if (tipo == "LibroHechizos") {
            return make_shared<LibroHechizos>();
        } else if (tipo == "PocionDeVida") {
            return make_shared<PocionDeVida>();
        } else if (tipo == "AmuletoDeVida") {
            return make_shared<AmuletoDeVida>();
        } else {
            throw invalid_argument("Tipo de arma no reconocido.");
        }
    }
}

shared_ptr<personajes> PersonajeFactory::armedPJCreation(const string& tipoPersonaje, const int i) {
    auto personaje = pjCreation(tipoPersonaje); // Crear personaje
    auto arma = wpCreation(tipoPersonaje, i); // Crear arma
    personaje->setArma(arma);  
    return personaje;
}