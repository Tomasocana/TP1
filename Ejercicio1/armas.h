#pragma once

#include <iostream>
#include <vector>

using namespace std;

// Interfaz de armas
class armas{
    public:
        virtual string golpeFuerte() = 0;
        virtual string golpeRapido() = 0;
        virtual int getDamage() = 0;
        virtual string getType() = 0;
        virtual bool usesMana() = 0;
        virtual string getName() = 0;
};

// Clase de items magicos
class ItemsMagicos : public armas{
    public:
        ItemsMagicos(string name) : name(name) {}
        string getName() override;
        virtual string golpeFuerte() override;
        virtual string golpeRapido() override;
        int getDamage() override;
        string getType() override;
        bool usesMana() override;
    protected:
        string name;
};

// Clase de armas de combate 
class ArmasDeCombate : public armas{
    public:
        ArmasDeCombate(string name) : name(name) {}   
        string getName() override;
        virtual string golpeFuerte() override;
        virtual string golpeRapido() override;
        int getDamage() override;
        string getType() override;
        bool usesMana() override;
    protected:
        string name;
};

// Items mágicos

// i
class varita : public ItemsMagicos{
    public:
        varita() : ItemsMagicos("Varita") {}
        string golpeFuerte() override;
        string golpeRapido() override;
        int getManaCost();
        int getCriticalChance();
        int defender();
    private:
        vector<string> golpesFuertes = {"Ofuscador Solar", "Cadenas Etéreas", "Fuego Devastador"};
        vector<string> golpesRapidos = {"Rafaga Radiante", "Pulso de fuerza", "Destello Helado"};
        string defensa = "Escudo Espiritual";
        int manaCost;
        int criticalChance;
};

// ii
class LibroHechizos : public ItemsMagicos{
    public:
        LibroHechizos() : ItemsMagicos("Libro de Hechizos") {}
        string golpeFuerte() override;
        string golpeRapido() override;
        int defender();
        int getManaCost();
        int getCriticalChance();
    private:
        vector<string> golpesFuertes = {"Lluvia de meteoros", "Rayo místico", "Tormenta helada"};
        vector<string> golepsRapidos = {"Bola de fuego", "Toque electrico", "Espinas Gélidas"};
        string defensa = "Velo arcano";
        int manaCost;
        int criticalChance;
};

// iii
class PocionDeVida : public ItemsMagicos{
    public:
        PocionDeVida() : ItemsMagicos("Poción de Vida"), restore(20) {}
        void consumePotion();

    private:
        int restore;

};

// iv
class AmuletoDeVida : public ItemsMagicos{
    public:
        AmuletoDeVida() : ItemsMagicos("Amuleto de Vida"), stat(20) {}
        void asignarAmuleto();
    private:
        int stat;

};


// Armas Cuerpo a Cuerpo

// i
class Hacha_giratoria : public ArmasDeCombate{
    public:
        Hacha_giratoria() : ArmasDeCombate("Hacha Giratoria"), costoEstamina(15), criticalChance(20) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        int defender();
        int getCostoEstamina();
        int getCriticalChance();
    private:
        vector<string> golpesFuertes = {"Guillotina", "Azote desgarrador", "Golpe dragón"};
        vector<string> golepsRapidos = {"Golpe Incapacitante", "Golpe decisivo", "Espinas Gélidas"};
        string defensa = "Furia de batalla";
        int costoEstamina;
        int criticalChance;
};

// ii
class Hoja_de_viento : public ArmasDeCombate{
    public:
        Hoja_de_viento() : ArmasDeCombate("Hoja de Viento"), costoEstamina(15), criticalChance(20) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        int defender();
        int getCostoEstamina();
        int getCriticalChance();
    private:
        vector<string> golpesFuertes = {"Asalto implacable", "Mil cortes", "Ragnarok"};
        vector<string> golepsRapidos = {"Cuchillada giratoria", "Golpe alfa" , "Golpe doble" };
        string defensa = "Subidón de adrenalina";
        int costoEstamina;
        int criticalChance;
};

// iii
class Aguja_sombria : public ArmasDeCombate{
    public:
        Aguja_sombria() : ArmasDeCombate("Aguja Sombría"), costoEstamina(15), criticalChance(20) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        int defender();
        int getCostoEstamina();
        int getCriticalChance();
    private:
        vector<string> golpesFuertes = {"Costura letal", "Corte segador", "Bordado"};
        vector<string> golepsRapidos = {"Rafaga de agujas", "Ataque sanguinario" , "Punto punzante" };
        string defensa = "Voluntad férrea";
        int costoEstamina;
        int criticalChance;
};

// iv
class Espada_de_los_oscuros : public ArmasDeCombate{
    public:
        Espada_de_los_oscuros() : ArmasDeCombate("Espada de los Oscuros"), costoEstamina(15), criticalChance(20) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        int defender();
        int getCostoEstamina();
        int getCriticalChance();
    private:
        vector<string> golpesFuertes = {"Filo purificador", "Ataque sombrío", "Pincho del vacío"};
        vector<string> golepsRapidos = {"Embate de espada", "Rafaga oscura" , "Golpe de hoja" };
        string defensa = "Furia inmortal";
        int costoEstamina;
        int criticalChance;
};

// v
class Tridente_colosal : public ArmasDeCombate{
    public:
        Tridente_colosal() : ArmasDeCombate("Tridente Colosal"), costoEstamina(15), criticalChance(20) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        int defender();
        int getCostoEstamina();
        int getCriticalChance();
    private:
        vector<string> golpesFuertes = {"Juicio del Tridente", "Desgarro Colosal", "Carga del Leviatán"};
        vector<string> golepsRapidos = {"Perforación triple", "Golpe de las profundiades" , "Embate de los mares" };
        string defensa = "Grito burlon";
        int costoEstamina;
        int criticalChance;
};

