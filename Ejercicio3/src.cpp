#include "factory.h"

shared_ptr<personajes> PersonajeFactory::pjCreation(const string& tipoPJ){
    if (tipoPJ == "Hechicero") {
        return make_shared<Hechicero>();
    } else if (tipoPJ == "conjurador") {
        return make_shared<conjurador>();
    } else if (tipoPJ == "brujo") {
        return make_shared<brujo>();
    } else if (tipoPJ == "nigromante") {
        return make_shared<nigromante>();
    }else if (tipoPJ == "barbaro") {
        return make_shared<barbaro>();
    } else if (tipoPJ == "paladin") {
        return make_shared<paladin>();
    } else if (tipoPJ == "caballero") {
        return make_shared<caballero>();
    } else if (tipoPJ == "mercenario") {
        return make_shared<mercenario>();
    } else if (tipoPJ == "gladiador") {
        return make_shared<gladiador>();
    } else{
        throw invalid_argument("Argumento Inválido.");
    }
}

shared_ptr<armas> PersonajeFactory::wpCreation(const string& tipoWP, const int i) {
    
    if(i == 1){
        if (tipoWP == "varita") {
            return(make_shared<varita>());
        } else if (tipoWP == "LibroHechizos") {
            return(make_shared<LibroHechizos>());
        } else if (tipoWP == "PocionDeVida") {
            return(make_shared<PocionDeVida>());
        } else if (tipoWP == "AmuletoDeVida") {
            return(make_shared<AmuletoDeVida>());
        } else if (tipoWP == "Hacha_giratoria") {
            return(make_shared<Hacha_giratoria>());
        } else if (tipoWP == "Hoja_de_viento") {
            return(make_shared<Hoja_de_viento>());
        } else if (tipoWP == "Aguja_sombria") {
            return(make_shared<Aguja_sombria>());
        } else if (tipoWP == "Espada_de_los_oscuros") {
            return(make_shared<Espada_de_los_oscuros>());
        } else if (tipoWP == "Tridente_colosal"){
            return(make_shared<Tridente_colosal>());
        } else{
            throw invalid_argument("Argumento Invalido.");
        }
    }
}

shared_ptr<personajes> PersonajeFactory::armedPJCreation(const string& tipoPJ, const string& tipoWP, const int i) {
    auto personaje = pjCreation(tipoPJ); // Crear personaje
    auto arma = wpCreation(tipoWP, i); // Crear arma
    personaje->setArma(arma);  
    return personaje;
}