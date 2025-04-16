#pragma once

#include <iostream>
#include "armas.h"
#include <memory>

using namespace std;

class armas;

// Interfaz de personajes
class personajes{
    public:
        virtual shared_ptr<armas> getPrimaryWP() = 0; // Método para obtener el arma primaria del personaje
        virtual shared_ptr<armas> getSecondaryWP() = 0; // Método para obtener el arma secundaria del personaje
        virtual string getName() = 0; // Método para obtener el nombre del personaje (Barbaro, brujo, etc...)
        virtual string getUltimate() = 0; // Método para obtener la ultimate del personaje
        virtual void decreaseHP() = 0; // Método para disminuir el HP
        virtual void increaseHP() = 0; // Método para incrementar el HP 
        virtual void asignarAmuleto() = 0; // Método para asignar los stats propios del amuleto asignado (Aumenta la vida máxima)
        virtual void consumePotion() = 0; // Método para consumir la poción (en caso de tener una)
        virtual void setArma(vector<shared_ptr<armas>> arma) = 0; // Método para asignar las armas proporcionadas
        virtual bool isDead() = 0; // Método para saber si el personaje está muerto o no
        virtual int getHP() = 0; // Método para obtener los HP
};

// Tanto el mago como el guerrero se diferencian por el gasto de "energia", ya que los magos gastan maná al realizar
// ataques, mientras que los guerreros gastan stamina. Dichas caractertisticas no influyen a la hora de ralizar una 
// batalla.

// Clase de magos
class Magos : public personajes{
    public:
        Magos(string name, string ultimate, string elemento,int MR, int afM, int extraMana) : name(name), ultimate(ultimate), elemento(elemento) ,resistenciaMagica(MR), afinidadMagica(afM), manaAdicional(extraMana) {}
        virtual string getUltimate() = 0; // Derivo este método para que cada personaje implemente su propia ultimate
        void decreaseHP() override;
        void increaseHP() override;
        void asignarAmuleto() override;
        void consumePotion() override;
        void setArma(vector<shared_ptr<armas>> arma) override;
        bool isDead() override;
        int getHP() override;
        int getMana();
        string getName() override;
        // Y defino las acciones de atacar fuerte, atacar rapido y defenderse
        string ataqueFuerte(); 
        string ataqueRapido();
        string defenderse();
        shared_ptr<armas> getPrimaryWP() override;
        shared_ptr<armas> getSecondaryWP() override; 
    protected:
        string name;
        string ultimate;
        string elemento;
        shared_ptr<armas> primaryWP = nullptr;
        shared_ptr<armas> secondaryWP = nullptr;
        int HP = 100;
        int MANA = 100;
        // Estos 3 atributos inicializan el 0 para posteriormente establecer los valores deseados
        // nuevamente estos 3 atributos extras no influyen a la hora de ralizar una batalla.
        int resistenciaMagica = 0; 
        int afinidadMagica = 0;
        int manaAdicional = 0;
};

// Clase de guerreros
class Guerreros : public personajes{
    public:
        Guerreros(string name, string ultimate, int agilidad, int velocidad, int fuerza, int resistencia) : name(name), ultimate(ultimate), agilidad(agilidad), velocidad(velocidad), fuerza(fuerza), resistencia(resistencia) {}
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
        int agilidad = 0;
        int velocidad = 0;
        int fuerza = 0;
        int resistencia = 0; 
};

// Magos

// i
class Hechicero : public Magos{
    public:
        Hechicero() : Magos("Hechicero", "Oleada del vacío", "Fuego" ,50, 70, 50) {}
        string getUltimate();
};

// ii
class conjurador : public Magos{
    public:
        conjurador() : Magos("Conjurador", "Chispa final", "Oscuridad", 15, 90, 10) {}
        string getUltimate();
};

// iii
class brujo : public Magos{
    public:
        brujo() : Magos("Brujo", "Veredicto divino", "Luz", 0, 100, 0) {}
        string getUltimate();
};

// iv
class nigromante : public Magos{
    public:
        nigromante() : Magos("Nigromante", "Cataclismo", "Veneno", 10, 40, 40) {}
        string getUltimate();  
};


// Guerreros

// i
class barbaro : public Guerreros{
    public:
        barbaro() : Guerreros("Bárbaro", "Ejecución perfecta", 15, 22, 70, 80) {}
        string getUltimate();   
};

// ii
class paladin : public Guerreros{
    public:
        paladin() : Guerreros("Paladín", "Espiral de la muerte", 15, 30, 50, 90) {}
        string getUltimate();
};

// iii
class caballero : public Guerreros{
    public:
        caballero() : Guerreros("Caballero", "Abajo del telón", 40, 45, 50, 80) {}
        string getUltimate(); 
};

// iv
class mercenario : public Guerreros{
    public:
        mercenario() : Guerreros("Mercenario", "Llamada del destino", 80, 90, 30, 20) {}
        string getUltimate();   
};

// v
class gladiador : public Guerreros{
    public:
        gladiador() : Guerreros("Gladiador", "Frenesí sanguinario", 70, 80, 60, 30) {}
        string getUltimate();    
};

