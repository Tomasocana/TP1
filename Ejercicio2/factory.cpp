#include "factory.h"

// Recibe como parámetro el tipo de personaje que se desea crear
// Se fija que tipo de personaje se desea crear, lo crea y lo devuelve
// Si se da un elemento inválido tira error
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

// Firma:
//  Recibe como parámetro los tipos de arma que se desea obtener, y la cantidad, la cual tendrá que coincidir con 
//  las armas proporcionadas, sino tira error.
// Funcionamiento:
//  Crea un vector que va a contener las armas que va a portar el personaje, el cual se va a rellenar de acuerdo
//  a la cantidad de armas que se deseen tener, especificadas en los parámetros de la función
vector<shared_ptr<armas>> PersonajeFactory::wpCreation(const string& tipoWP1, const int cant_armas, const string& tipoWP2) {
    vector<shared_ptr<armas>> armas_list;
    if(cant_armas == 0) return armas_list;
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
    if(cant_armas == 2){
        if (tipoWP2 == "varita") {
            armas_list.push_back(make_shared<varita>());
        } else if (tipoWP2 == "LibroHechizos") {
            armas_list.push_back(make_shared<LibroHechizos>());
        } else if (tipoWP2 == "PocionDeVida") {
            armas_list.push_back(make_shared<PocionDeVida>());
        } else if (tipoWP2 == "AmuletoDeVida") {
            armas_list.push_back(make_shared<AmuletoDeVida>());
        } else if (tipoWP2 == "Hacha_giratoria") {
            armas_list.push_back(make_shared<Hacha_giratoria>());
        } else if (tipoWP2 == "Hoja_de_viento") {
            armas_list.push_back(make_shared<Hoja_de_viento>());
        } else if (tipoWP2 == "Aguja_sombria") {
            armas_list.push_back(make_shared<Aguja_sombria>());
        } else if (tipoWP2 == "Espada_de_los_oscuros") {
            armas_list.push_back(make_shared<Espada_de_los_oscuros>());
        } else if (tipoWP2 == "Tridente_colosal"){
            armas_list.push_back(make_shared<Tridente_colosal>());
        } else{
            throw invalid_argument("Argumento Invalido.");
        }
    }
    return armas_list;
}

//Firma:
// Recibe como parámetro el tipo de personaje que se desea crear, los tipos de armas, y la cantidad de armas
shared_ptr<personajes> PersonajeFactory::armedPJCreation(const string& tipoPJ, const string& tipoWP, const int cant_armas, const string& tipoWP2) {
    auto personaje = pjCreation(tipoPJ); // Crear personaje
    auto armas = wpCreation(tipoWP, cant_armas, tipoWP2); // Crear arma
    personaje->setArma(armas); // Asgina el arma solicitada al personaje creado
    return personaje; // Devuelve el personaje con su arma ya asginada
}