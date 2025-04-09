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

vector<shared_ptr<armas>> PersonajeFactory::wpCreation(const string& tipoWP1, const int cant_armas, const string& tipoWP2 = "") {
    vector<shared_ptr<armas>> armas_list;
    if(cant_armas == 0) return armas_list;
    if(cant_armas == 1){
        if (tipoWP1 == "varita") {
            armas_list.push_back(make_shared<varita>());
        } else if (tipoWP1 == "LibroHechizos") {
            armas_list.push_back(make_shared<LibroHechizos>());
        } else if (tipoWP1 == "PocionDeVida") {
            armas_list.push_back(make_shared<PocionDeVida>());
        } else if (tipoWP1 == "AmuletoDeVida") {
            armas_list.push_back(make_shared<AmuletoDeVida>());
        } else if (tipoWP1 == "Hacha_giratoria") {
            armas_list.push_back(make_shared<Hacha_giratoria>());
        } else if (tipoWP1 == "Hoja_de_viento") {
            armas_list.push_back(make_shared<Hoja_de_viento>());
        } else if (tipoWP1 == "Aguja_sombria") {
            armas_list.push_back(make_shared<Aguja_sombria>());
        } else if (tipoWP1 == "Espada_de_los_oscuros") {
            armas_list.push_back(make_shared<Espada_de_los_oscuros>());
        } else if (tipoWP1 == "Tridente_colosal"){
            armas_list.push_back(make_shared<Tridente_colosal>());
        } else{
            throw invalid_argument("Argumento Invalido.");
        }
    } else if(cant_armas == 2){
        if(tipoWP1 == tipoWP2){
            if (tipoWP1 == "varita") {
                armas_list.push_back(make_shared<varita>());
                armas_list.push_back(make_shared<varita>());
            } else if (tipoWP1 == "LibroHechizos") {
                armas_list.push_back(make_shared<LibroHechizos>());
                armas_list.push_back(make_shared<LibroHechizos>());
            } else if (tipoWP1 == "PocionDeVida") {
                armas_list.push_back(make_shared<PocionDeVida>());
                armas_list.push_back(make_shared<PocionDeVida>());
            } else if (tipoWP1 == "AmuletoDeVida") {
                armas_list.push_back(make_shared<AmuletoDeVida>());
                armas_list.push_back(make_shared<AmuletoDeVida>());
            } else if (tipoWP1 == "Hacha_giratoria") {
                armas_list.push_back(make_shared<Hacha_giratoria>());
                armas_list.push_back(make_shared<Hacha_giratoria>());
            } else if (tipoWP1 == "Hoja_de_viento") {
                armas_list.push_back(make_shared<Hoja_de_viento>());
                armas_list.push_back(make_shared<Hoja_de_viento>());
            } else if (tipoWP1 == "Aguja_sombria") {
                armas_list.push_back(make_shared<Aguja_sombria>());
                armas_list.push_back(make_shared<Aguja_sombria>());
            } else if (tipoWP1 == "Espada_de_los_oscuros") {
                armas_list.push_back(make_shared<Espada_de_los_oscuros>());
                armas_list.push_back(make_shared<Espada_de_los_oscuros>());
            } else if (tipoWP1 == "Tridente_colosal"){
                armas_list.push_back(make_shared<Tridente_colosal>());
            } else{
                throw invalid_argument("Argumento Invalido.");
            }
        } else{
            if (tipoWP1 == "varita" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<varita>());
            } else if (tipoWP1 == "LibroHechizos" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<LibroHechizos>());
            } else if (tipoWP1 == "PocionDeVida" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<PocionDeVida>());
            } else if (tipoWP1 == "AmuletoDeVida" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<AmuletoDeVida>());
            } else if (tipoWP1 == "Hacha_giratoria" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<Hacha_giratoria>());
            } else if (tipoWP1 == "Hoja_de_viento" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<Hoja_de_viento>());
            } else if (tipoWP1 == "Aguja_sombria" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<Aguja_sombria>());
            } else if (tipoWP1 == "Espada_de_los_oscuros" || tipoWP2 == "varita") {
                armas_list.push_back(make_shared<Espada_de_los_oscuros>());
            } else if (tipoWP1 == "Tridente_colosal" || tipoWP2 == "varita"){
                armas_list.push_back(make_shared<Tridente_colosal>());
            } else{
                throw invalid_argument("Argumento Invalido.");
            }
        }
    }
    return armas_list;
}

shared_ptr<personajes> PersonajeFactory::armedPJCreation(const string& tipoPJ, const string& tipoWP, const int cant_armas, const string& tipoWP2 = "") {
    auto personaje = pjCreation(tipoPJ); // Crear personaje
    auto armas = wpCreation(tipoWP, cant_armas, tipoWP2); // Crear arma
    personaje->setArma(armas);  
    return personaje;
}