#pragma once

#include <iostream>

using namespace std;

//"Nombres de ultis:"
//    "Ejecución perfecta"
//    "Pulverización"
//    "Oleada del vacío"
//    "Final sangriento"
//    "Frenesí sanguinario"
//    "Espiral de la muerte"
//    "Cataclismo"
//    "Abajo del telón"
//    "Llamada del destino"
//    "Loto mortal"
//    "Veredicto divino"
//    "Chispa final"
//
//"Ascenso divino"

// Interfaz de personajes
class personajes{
    public:
        virtual bool isDead() = 0;
        virtual int getHP() = 0;
        virtual void weaponInHand() = 0;
};

// Clase de magos
class Magos : public personajes{
    public:
        Magos();
        bool isDead() override;
        int getHP() override;
        void weaponInHand() override;
    protected:
        int HP = 100;
        int MANA = 100;
};

// Clase de guerreros
class Guerreros : public personajes{
    public:
        bool isDead() override;
        int getHP() override;
        void weaponInHand() override;
    protected:
        int HP;
        int STAMINA;
};

// Empiezo con 5 magos

// i
class Hechicero : public Magos{
    public:
        Hechicero() : Magos() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();

};