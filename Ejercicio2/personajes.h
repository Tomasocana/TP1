#pragma once

#include <iostream>
#include <armas.h>
#include <memory>

using namespace std;

//"Ascenso divino"

// Interfaz de personajes
class personajes{
    public:
        virtual bool isDead() = 0;
        virtual int getHP() = 0;
        virtual void setArma(shared_ptr<armas> arma) = 0;
};

// Clase de magos
class Magos : public personajes{
    public:
        Magos();
        bool isDead() override;
        int getHP() override;
        void setArma(shared_ptr<armas> arma) override;
    protected:
        int HP = 100;
        int MANA = 100;
};

// Clase de guerreros
class Guerreros : public personajes{
    public:
        Guerreros();
        bool isDead() override;
        int getHP() override;
        void setArma(shared_ptr<armas> arma) override;
    protected:
        int HP;
        int STAMINA;
};

// Magos

// i
class Hechicero : public Magos{
    public:
        Hechicero() : Magos() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getMana();
    private:
        string ultimate = "Oleada del vacío";
        string elemento = "Fuego";
        int resistenciaMagica = 50;
        int afinidadMagica = 70;
        int manaAdicional = 50;
};

// ii
class conjurador : public Magos{
    public:
        conjurador() : Magos() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getMana();
    private:
        string ultimate = "Chispa final";
        string elemento = "Oscuridad";
        int resistenciaMagica = 15;
        int afinidadMagica = 90;
        int manaAdicional = 10;
};

// iii
class brujo : public Magos{
    public:
        brujo() : Magos() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getMana();
    private:
        string ultimate = "Veredicto divino";
        string elemento = "Luz";
        int resistenciaMagica = 0;
        int afinidadMagica = 100;
        int manaAdicional = 0;    
};

// iv
class nigromante : public Magos{
    public:
        nigromante() : Magos() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getMana();
    private:
        string ultimate = "Cataclismo";
        string elemento = "Veneno";
        int resistenciaMagica = 10;
        int afinidadMagica = 40;
        int manaAdicional = 40;      
};


// Guerreros

// i
class barbaro : public Guerreros{
    public:
        barbaro() : Guerreros() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getStamina();
    private:
        string ultimate = "Ejecución perfecta";
        int agilidad = 15;
        int velocidad = 22;
        int fuerza = 70;
        int resistencia = 80;        
};

// ii
class paladin : public Guerreros{
    public:
        paladin() : Guerreros() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getStamina();
    private:
        string ultimate = "Espiral de la muerte";
        int agilidad = 15;
        int velocidad = 30;
        int fuerza = 50;
        int resistencia = 90;      
};

// iii
class caballero : public Guerreros{
    public:
        caballero() : Guerreros() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getStamina();
    private:
        string ultimate = "Abajo del telón";
        int agilidad = 40;
        int velocidad = 45;
        int fuerza = 50;
        int resistencia = 80;    
};

// iv
class mercenario : public Guerreros{
    public:
        mercenario() : Guerreros() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getStamina();
    private:
        string ultimate = "Llamada del destino";
        int agilidad = 80;
        int velocidad = 90;
        int fuerza = 30;
        int resistencia = 20;        
};

// v
class gladiador : public Guerreros{
    public:
        gladiador() : Guerreros() {}
        void ataqueFuerte();
        void ataqueRapido();
        void defenderse();
        vector<armas> waponInHand();
        void getStamina();
    private:
        string ultimate = "Frenesí sanguinario";
        int agilidad = 70;
        int velocidad = 80;
        int fuerza = 60;
        int resistencia = 30;          
};

