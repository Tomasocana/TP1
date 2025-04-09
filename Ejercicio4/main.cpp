#include "factory.h"
#include <stdlib.h>

int main(){
    string mageOptions[] = {"Hechicero", "conjurador", "brujo", "nigromante"};
    string warriorOptions[] = {"barbaro", "paladin", "caballero", "mercenario", "gladiador"};
    string MagicWp[] = {"varita", "LibroHechizos", "PocionDeVida", "AmuletoDeVida"};
    string meleeWp[] = {"Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
    vector<shared_ptr<personajes>> PJToFight;

    int cantMages = (rand() / RAND_MAX) * (7 - 3) + 3;
    int cantWarrios = (rand() / RAND_MAX) * (7 - 3) + 3;

    for(int i = 0; i < cantMages; i++){
        int randomMage = (rand() / RAND_MAX) * (3 - 0) + 0;
        int cantWP = (rand() / RAND_MAX) * (2 - 0) + 0;
    }
}