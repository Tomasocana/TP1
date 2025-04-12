#include "personajes.h"

// Implementación de los métodos de los magos

void Magos::decreaseHP() {HP -= 10;}
void Magos::increaseHP() {HP += 10;}
void Magos::asignarAmuleto() {HP += 20;}
void Magos::consumePotion() {HP += 20;}

void Magos::setArma(vector<shared_ptr<armas>> arma) {
    if(arma.empty()) return;
    auto i = arma[0];
    primaryWP = i;
    if(primaryWP->getName() == "Amuleto de Vida"){
        asignarAmuleto();
    }
    if(arma.size() == 2){
        auto j = arma[1];
        secondaryWP = j;
        if(secondaryWP->getName() == "Amuleto de Vida"){
            asignarAmuleto();
        }
    }
}

bool Magos::isDead() {
    if(HP <= 0) return true;
    return false;
}

int Magos::getHP() {return HP;}
int Magos::getMana() {return MANA;}
string Magos::getName() {return name;}
string Magos::ataqueFuerte() {return primaryWP->golpeFuerte();}
string Magos::ataqueRapido() {return primaryWP->golpeRapido();}
string Magos::defenderse() {return primaryWP->defender();}

shared_ptr<armas> Magos::getPrimaryWP() {return primaryWP;}
shared_ptr<armas> Magos::getSecondaryWP() {return secondaryWP;}


// Implementación de los métodos de los guerreros

void Guerreros::decreaseHP() {HP -= 10;}
void Guerreros::increaseHP() {HP += 10;}
void Guerreros::asignarAmuleto() {HP += 20;}
void Guerreros::consumePotion() {HP += 20;}

void Guerreros::setArma(vector<shared_ptr<armas>> arma) {
    if(arma.empty()) return;
    auto i = arma[0];
    primaryWP = i;
    if(primaryWP->getName() == "Amuleto de Vida"){
        asignarAmuleto();
    }
    if(arma.size() == 2){
        auto j = arma[1];
        secondaryWP = j;
        if(secondaryWP->getName() == "Amuleto de Vida"){
            asignarAmuleto();
        }
    }
}

int Guerreros::getStamina() {return STAMINA;}
int Guerreros::getHP() {return HP;}
string Guerreros::ataqueFuerte() {return primaryWP->golpeFuerte();}
string Guerreros::ataqueRapido() {return primaryWP->golpeRapido();}
string Guerreros::defenderse() {return primaryWP->defender();}
string Guerreros::getName() {return name;}
shared_ptr<armas> Guerreros::getPrimaryWP() {return primaryWP;}
shared_ptr<armas> Guerreros::getSecondaryWP() {return secondaryWP;}

bool Guerreros::isDead() {
    if(HP <= 0) return true;
    return false;
}



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