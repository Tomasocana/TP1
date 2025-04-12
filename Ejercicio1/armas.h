#pragma once

#include <iostream>
#include <vector>

using namespace std;

class personajes;

// Interfaz de armas
class armas{
    public:
        virtual bool usesMana() = 0;
        virtual string getName() = 0;
        virtual string golpeFuerte() = 0;
        virtual string golpeRapido() = 0;
        virtual string defender() = 0;
};

// Clase de items magicos
class ItemsMagicos : public armas{
    public:
        ItemsMagicos(string name) : name(name) {}
        virtual string golpeFuerte() = 0;
        virtual string golpeRapido() = 0;
        virtual string defender() = 0;
        string getName() override;
        bool usesMana() override;
    protected:
        string name;
};

// Clase de armas de combate 
class ArmasDeCombate : public armas{
    public:
        ArmasDeCombate(string name, int costoEstamina, int criticalChance) : name(name), costoEstamina(costoEstamina), criticalChance(criticalChance) {}  
        virtual string golpeFuerte() = 0;
        virtual string golpeRapido() = 0;
        virtual string defender() = 0;
        string getName() override;
        bool usesMana() override;
        int getCriticalChance();
        int getCostoEstamina();
    protected:
        string name;
        int costoEstamina;
        int criticalChance;
};

// Items mágicos

// i
class varita : public ItemsMagicos{
    public:
        varita() : ItemsMagicos("Varita") {}
        string golpeFuerte();
        string golpeRapido();
        string defender();
        int getCriticalChance();
        int getManaCost();
    private:
        vector<string> golpesFuertes = {"Ofuscador Solar", "Cadenas Etéreas", "Fuego Devastador"};
        vector<string> golpesRapidos = {"Rafaga Radiante", "Pulso de fuerza", "Destello Helado"};
        string defensa = "Escudo Espiritual";
        int manaCost = 10;
        int criticalChance = 20;
};

// ii
class LibroHechizos : public ItemsMagicos{
    public:
        LibroHechizos() : ItemsMagicos("Libro de Hechizos") {}
        string golpeFuerte();
        string golpeRapido();
        string defender();
        int getCriticalChance();
        int getManaCost();
    private:
        vector<string> golpesFuertes = {"Lluvia de meteoros", "Rayo místico", "Tormenta helada"};
        vector<string> golpesRapidos = {"Bola de fuego", "Toque electrico", "Espinas Gélidas"};
        string defensa = "Velo arcano";
        int manaCost = 15;
        int criticalChance = 30;
};

// iii
class PocionDeVida : public ItemsMagicos{
    public:
        PocionDeVida() : ItemsMagicos("Poción de Vida") {}
        string golpeFuerte() override;
        string golpeRapido() override;
        string defender() override;
};

// iv
class AmuletoDeVida : public ItemsMagicos{
    public:
        AmuletoDeVida() : ItemsMagicos("Amuleto de Vida") {}
        string golpeFuerte() override;
        string golpeRapido() override;
        string defender() override;
};


// Armas de combate

// i
class Hacha_giratoria : public ArmasDeCombate{
    public:
        Hacha_giratoria() : ArmasDeCombate("Hacha Giratoria", 30, 40) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        string defender() override;
    private:
        vector<string> golpesFuertes = {"Guillotina", "Azote desgarrador", "Golpe dragón"};
        vector<string> golpesRapidos = {"Golpe Incapacitante", "Golpe decisivo", "Espinas Gélidas"};
        string defensa = "Furia de batalla";
};

// ii
class Hoja_de_viento : public ArmasDeCombate{
    public:
        Hoja_de_viento() : ArmasDeCombate("Hoja de Viento", 40, 69) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        string defender() override;
    private:
        vector<string> golpesFuertes = {"Asalto implacable", "Mil cortes", "Ragnarok"};
        vector<string> golpesRapidos = {"Cuchillada giratoria", "Golpe alfa" , "Golpe doble" };
        string defensa = "Subidón de adrenalina";
};

// iii
class Aguja_sombria : public ArmasDeCombate{
    public:
        Aguja_sombria() : ArmasDeCombate("Aguja Sombría", 30, 80) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        string defender() override;
    private:
        vector<string> golpesFuertes = {"Costura letal", "Corte segador", "Bordado"};
        vector<string> golpesRapidos = {"Rafaga de agujas", "Ataque sanguinario" , "Punto punzante" };
        string defensa = "Voluntad férrea";
};

// iv
class Espada_de_los_oscuros : public ArmasDeCombate{
    public:
        Espada_de_los_oscuros() : ArmasDeCombate("Espada de los Oscuros", 40, 90) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        string defender() override;
    private:
        vector<string> golpesFuertes = {"Filo purificador", "Ataque sombrío", "Pincho del vacío"};
        vector<string> golpesRapidos = {"Embate de espada", "Rafaga oscura" , "Golpe de hoja" };
        string defensa = "Furia inmortal";
};

// v
class Tridente_colosal : public ArmasDeCombate{
    public:
        Tridente_colosal() : ArmasDeCombate("Tridente Colosal", 100, 100) {}
        string golpeFuerte() override;
        string golpeRapido() override;
        string defender() override;
    private:
        vector<string> golpesFuertes = {"Juicio del Tridente", "Desgarro Colosal", "Carga del Leviatán"};
        vector<string> golpesRapidos = {"Perforación triple", "Golpe de las profundiades" , "Embate de los mares" };
        string defensa = "Grito burlon";
};

