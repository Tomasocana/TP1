#include "personajes.h"

// Implementación de los métodos de los magos

shared_ptr<armas> Magos::getPrimaryWP() {return primaryWP;}
string Magos::getName() {return name;}

bool Magos::isDead() {
    if(HP <= 0) return true;
    return false;
}

int Magos::getHP() {return HP;}
void Magos::decreaseHP() {HP -= 10;}
void Magos::increaseHP() {HP += 10;}

void Magos::setArma(vector<shared_ptr<armas>> arma) {
    if(arma.empty()) return;
    auto i = arma[0];
    primaryWP = i;
    if(arma.size() == 2){
        auto j = arma[1];
        secondaryWP = j;
    }
}

string Magos::ataqueFuerte() {return primaryWP->golpeFuerte();}
string Magos::ataqueRapido() {return primaryWP->golpeRapido();}
string Magos::defenderse() {}
int Magos::getMana() {return MANA;}


// Implementación de los métodos de los guerreros

shared_ptr<armas> Guerreros::getPrimaryWP() {return primaryWP;}
string Guerreros::getName() {return name;}
void Guerreros::decreaseHP() {HP -= 10;}
void Guerreros::increaseHP() {HP += 10;}

bool Guerreros::isDead() {
    if(HP <= 0) return true;
    return false;
}

int Guerreros::getHP() {return HP;}

void Guerreros::setArma(vector<shared_ptr<armas>> arma) {
    if(arma.empty()) return;
    auto i = arma[0];
    primaryWP = i;
    if(arma.size() == 2){
        auto j = arma[1];
        secondaryWP = j;
    }
}

string Guerreros::ataqueFuerte() {return primaryWP->golpeFuerte();}
string Guerreros::ataqueRapido() {return primaryWP->golpeRapido();}
string Guerreros::defenderse() {}
int Guerreros::getStamina() {return STAMINA;}


// Implementación del método getUltimate() para todas las clases derivadas

string Hechicero::getUltimate() {return ultimate;}
string conjurador::getUltimate() {return ultimate;}
string brujo::getUltimate() {return ultimate;}
string nigromante::getUltimate() {return ultimate;}
string barbaro::getUltimate() {return ultimate;}
string paladin::getUltimate() {return ultimate;}
string caballero::getUltimate() {return ultimate;}
string mercenario::getUltimate() {return ultimate;}
string gladiador::getUltimate() {return ultimate;}