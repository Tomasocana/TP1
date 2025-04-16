#include "armas.h"

//Implementación de los métodos de la clase Items mágicos

string ItemsMagicos::getName(){return name;}

// Si es una poción o un amuleto, no utiliza mana, sino si
bool ItemsMagicos::usesMana(){
    if (name == "Poción de Vida" || name == "Amuleto de Vida") return false;
    return true;
}


//Implementación de los métodos de la clase armas de combate

string ArmasDeCombate::getName(){return name;}
bool ArmasDeCombate::usesMana(){return false;}
int ArmasDeCombate::getCriticalChance(){return criticalChance;}
int ArmasDeCombate::getCostoEstamina(){return costoEstamina;}



//Implementación de los métodos de los Items mágicos
///Varita

// La implementación de los golpes, devuelve un ataque aleatorio entre la lista predeterminada de su clase
string varita::golpeFuerte(){
    string randomStrongAtack = golpesFuertes[rand() % 3];
    return randomStrongAtack;
}

string varita::golpeRapido(){
    string randomFastAtack = golpesRapidos[rand() % 3];
    return randomFastAtack;
}

string varita::defender(){return defensa;}
int varita::getCriticalChance(){return criticalChance;}
int varita::getManaCost(){return manaCost;}

///Libro De Hechizos

string LibroHechizos::golpeFuerte(){
    string randomStrongAtack = golpesFuertes[rand() % 3];
    return randomStrongAtack;
}

string LibroHechizos::golpeRapido(){
    string randomFastAtack = golpesRapidos[rand() % 3];
    return randomFastAtack;
}

string LibroHechizos::defender(){return defensa;}
int LibroHechizos::getCriticalChance(){return criticalChance;}
int LibroHechizos::getManaCost(){return manaCost;}

///Pocion De vida

string PocionDeVida::golpeFuerte() {return "";}
string PocionDeVida::golpeRapido() {return "";}
string PocionDeVida::defender() {return "";}

///Amuleto de vida

string AmuletoDeVida::golpeFuerte() {return "";}
string AmuletoDeVida::golpeRapido() {return "";}
string AmuletoDeVida::defender() {return "";}



// Implementación de los metodos de las armas de combate

/// Hacha Giratoria

string Hacha_giratoria::golpeFuerte(){
    string randomStrongAtack = golpesFuertes[rand() % 3];
    return randomStrongAtack;
}

string Hacha_giratoria::golpeRapido(){
    string randomFastAtack = golpesRapidos[rand() % 3];
    return randomFastAtack;
}

string Hacha_giratoria::defender(){return defensa;}

// Hoja de viento

string Hoja_de_viento::golpeFuerte(){
    string randomStrongAtack = golpesFuertes[rand() % 3];
    return randomStrongAtack;
}

string Hoja_de_viento::golpeRapido(){
    string randomFastAtack = golpesRapidos[rand() % 3];
    return randomFastAtack;
}

string Hoja_de_viento::defender(){return defensa;}

// Aguja sombria

string Aguja_sombria::golpeFuerte(){
    string randomStrongAtack = golpesFuertes[rand() % 3];
    return randomStrongAtack;
}

string Aguja_sombria::golpeRapido(){
    string randomFastAtack = golpesRapidos[rand() % 3];
    return randomFastAtack;
}

string Aguja_sombria::defender(){return defensa;}

// Espada de los oscuros

string Espada_de_los_oscuros::golpeFuerte(){
    string randomStrongAtack = golpesFuertes[rand() % 3];
    return randomStrongAtack;
}

string Espada_de_los_oscuros::golpeRapido(){
    string randomFastAtack = golpesRapidos[rand() % 3];
    return randomFastAtack;
}

string Espada_de_los_oscuros::defender(){return defensa;}

// Tridente Colosal

string Tridente_colosal::golpeFuerte(){
    string randomStrongAtack = golpesFuertes[rand() % 3];
    return randomStrongAtack;
}

string Tridente_colosal::golpeRapido(){
    string randomFastAtack = golpesRapidos[rand() % 3];
    return randomFastAtack;
}

string Tridente_colosal::defender(){return defensa;}