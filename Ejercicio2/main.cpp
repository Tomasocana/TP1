#include "factory.h"

int main() {
    cout << "Creo una cantidad aleatoria de magos y guerreros:" << endl;
    
    // Entre 3 y 7 personajes
    int cantidadMagos = rand() % 5 + 3; 
    int cantidadGuerreros = rand() % 5 + 3; 

    cout << "   Cantidad de Magos: " << cantidadMagos << endl;
    cout << "   Cantidad de Guerreros: " << cantidadGuerreros << endl;

    // Opciones de personajes y armas
    string magos[] = {"Hechicero", "conjurador", "brujo", "nigromante"};
    string guerreros[] = {"barbaro", "paladin", "caballero", "mercenario", "gladiador"};
    string armas[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};

    // Crear Magos
    cout << "\nGenerando Magos..." << endl;
    for (int i = 0; i < cantidadMagos; i++) {
        // Mago aleatorio
        string tipoMago = magos[rand() % 4];

        // Cantidad de armas aleatorias para el mago
        int cantidadArmas = rand() % 3;

        // 
        vector<string> armasSeleccionadas;
        for (int j = 0; j < cantidadArmas; j++) {
            armasSeleccionadas.push_back(armas[rand() % 8]);
        }

        // Crear el Mago armado
        shared_ptr<personajes> mago;
        if(cantidadArmas == 0) mago = PersonajeFactory::armedPJCreation(tipoMago, "", 0, ""); // ACA ME QUEDE
        auto mago = PersonajeFactory::armedPJCreation(tipoMago, cantidadArmas > 0 ? armasSeleccionadas[0] : "", cantidadArmas, cantidadArmas > 1 ? armasSeleccionadas[1] : "");

        // Mostrar información del Mago
        cout << "Mago creado: " << tipoMago << " con " << cantidadArmas << " arma(s)." << endl;
        if (cantidadArmas > 0) {
            cout << "  Arma primaria: " << mago->getPrimaryWP()->getName() << endl;
            if (cantidadArmas > 1) {
                cout << "  Arma secundaria: " << mago->getSecondaryWP()->getName() << endl;
            }
        }
    }

    // Crear Guerreros
    cout << "\nGenerando Guerreros..." << endl;
    for (int i = 0; i < cantidadGuerreros; i++) {
        // Seleccionar un tipo de Guerrero aleatorio
        string tipoGuerrero = guerreros[rand() % 5];

        // Generar cantidad de armas aleatoria (0-2)
        int cantidadArmas = rand() % 3;

        // Seleccionar armas aleatorias
        vector<string> armasSeleccionadas;
        for (int j = 0; j < cantidadArmas; j++) {
            armasSeleccionadas.push_back(armas[rand() % 8]);
        }

        // Crear el Guerrero armado
        auto guerrero = PersonajeFactory::armedPJCreation(tipoGuerrero, cantidadArmas > 0 ? armasSeleccionadas[0] : "", cantidadArmas, cantidadArmas > 1 ? armasSeleccionadas[1] : "");

        // Mostrar información del Guerrero
        cout << "Guerrero creado: " << tipoGuerrero << " con " << cantidadArmas << " arma(s)." << endl;
        if (cantidadArmas > 0) {
            cout << "  Arma primaria: " << guerrero->getPrimaryWP()->getName() << endl;
            if (cantidadArmas > 1) {
                cout << "  Arma secundaria: " << guerrero->getSecondaryWP()->getName() << endl;
            }
        }
    }

    return 0;
}