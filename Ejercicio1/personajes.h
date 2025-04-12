#pragma once

#include <iostream>
#include "armas.h"
#include <memory>

using namespace std;

class armas;

// Interfaz de personajes
class personajes{
    public:
        virtual shared_ptr<armas> getPrimaryWP() = 0; 
        virtual shared_ptr<armas> getSecondaryWP() = 0; 
        virtual string getName() = 0;
        virtual string getUltimate() = 0;
        virtual void decreaseHP() = 0;
        virtual void increaseHP() = 0;
        virtual void asignarAmuleto() = 0;
        virtual void consumePotion() = 0;
        virtual void setArma(vector<shared_ptr<armas>> arma) = 0;
        virtual bool isDead() = 0;
        virtual int getHP() = 0;
};

// Clase de magos
class Magos : public personajes{
    public:
        Magos(string name, string ultimate) : name(name), ultimate(ultimate) {}
        virtual string getUltimate() = 0;
        void decreaseHP() override;
        void increaseHP() override;
        void asignarAmuleto() override;
        void consumePotion() override;
        void setArma(vector<shared_ptr<armas>> arma) override;
        bool isDead() override;
        int getHP() override;
        int getMana();
        string getName() override;
        string ataqueFuerte();
        string ataqueRapido();
        string defenderse();
        shared_ptr<armas> getPrimaryWP() override;
        shared_ptr<armas> getSecondaryWP() override; 
    protected:
        string name;
        string ultimate;
        shared_ptr<armas> primaryWP = nullptr;
        shared_ptr<armas> secondaryWP = nullptr;
        int HP = 100;
        int MANA = 100;
};

// Clase de guerreros
class Guerreros : public personajes{
    public:
        Guerreros(string name, string ultimate) : name(name), ultimate(ultimate) {}
        virtual string getUltimate() = 0;
        void decreaseHP() override;
        void increaseHP() override;
        void asignarAmuleto() override;
        void consumePotion() override;
        void setArma(vector<shared_ptr<armas>> arma) override;
        int getStamina();
        int getHP() override;
        string ataqueFuerte();
        string ataqueRapido();
        string defenderse();
        string getName() override;
        shared_ptr<armas> getPrimaryWP() override;
        shared_ptr<armas> getSecondaryWP() override; 
        bool isDead() override;
    protected:
        string name;
        string ultimate;
        shared_ptr<armas> primaryWP = nullptr;
        shared_ptr<armas> secondaryWP = nullptr;
        int HP = 100;
        int STAMINA = 100;
};

// Magos

// i
class Hechicero : public Magos{
    public:
        Hechicero() : Magos("Hechicero", "Oleada del vacío") {}
        string getUltimate();
    private:
        string elemento = "Fuego";
        int resistenciaMagica = 50;
        int afinidadMagica = 70;
        int manaAdicional = 50;
};

// ii
class conjurador : public Magos{
    public:
        conjurador() : Magos("Conjurador", "Chispa final") {}
        string getUltimate();
    private:
        string elemento = "Oscuridad";
        int resistenciaMagica = 15;
        int afinidadMagica = 90;
        int manaAdicional = 10;
};

// iii
class brujo : public Magos{
    public:
        brujo() : Magos("Brujo", "Veredicto divino") {}
        string getUltimate();
    private:
        string elemento = "Luz";
        int resistenciaMagica = 0;
        int afinidadMagica = 100;
        int manaAdicional = 0;    
};

// iv
class nigromante : public Magos{
    public:
        nigromante() : Magos("Nigromante", "Cataclismo") {}
        string getUltimate();
    private:
        string elemento = "Veneno";
        int resistenciaMagica = 10;
        int afinidadMagica = 40;
        int manaAdicional = 40;      
};


// Guerreros

// i
class barbaro : public Guerreros{
    public:
        barbaro() : Guerreros("Bárbaro", "Ejecución perfecta") {}
        string getUltimate();
    private:
        int agilidad = 15;
        int velocidad = 22;
        int fuerza = 70;
        int resistencia = 80;        
};

// ii
class paladin : public Guerreros{
    public:
        paladin() : Guerreros("Paladín", "Espiral de la muerte") {}
        string getUltimate();
    private:
        int agilidad = 15;
        int velocidad = 30;
        int fuerza = 50;
        int resistencia = 90;      
};

// iii
class caballero : public Guerreros{
    public:
        caballero() : Guerreros("Caballero", "Abajo del telón") {}
        string getUltimate();
    private:
        int agilidad = 40;
        int velocidad = 45;
        int fuerza = 50;
        int resistencia = 80;    
};

// iv
class mercenario : public Guerreros{
    public:
        mercenario() : Guerreros("Mercenario", "Llamada del destino") {}
        string getUltimate();
    private:
        int agilidad = 80;
        int velocidad = 90;
        int fuerza = 30;
        int resistencia = 20;        
};

// v
class gladiador : public Guerreros{
    public:
        gladiador() : Guerreros("Gladiador", "Frenesí sanguinario") {}
        string getUltimate();
    private:
        int agilidad = 70;
        int velocidad = 80;
        int fuerza = 60;
        int resistencia = 30;          
};

