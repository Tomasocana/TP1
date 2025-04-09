#include "factory.h"
#include <stdlib.h>

int main(){
    vector<shared_ptr<personajes>> PJToFight;

    int cantMages = (rand() / RAND_MAX) * (7 - 3) + 3;
    int cantWarrios = (rand() / RAND_MAX) * (7 - 3) + 3;

    for(int i = 0; i < cantMages; i++){
        PersonajeFactory factory;
        int cantWP = (rand() / RAND_MAX) * (2 - 0) + 0;
        PJToFight.push_back(factory.armedPJCreation("mago", cantWP));
    }

    for(int i = 0; i < cantWarrios; i++){
        PersonajeFactory factory;
        int cantWP = (rand() / RAND_MAX) * (2 - 0) + 0;
        PJToFight.push_back(factory.armedPJCreation("guerrero", cantWP));
    }

    int opt;
    cout << "<<<<<<<<<<<<<<<<<<<<<< PELEA DE ROL >>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "1. Iniciar batalla" << endl;
    cout << "2. Salir" << endl;
    cout << "Respuesta:";
    cin >> opt;
    switch(opt){
        case 1:{
            bool cond = true;
            while(cond){
                int option;
                cout << "¿Que tipo de personaje quiere? " << endl;
                cout << "1. mago" << endl;
                cout << "2. guerrero" << endl;
                cin >> option;
                string PJ;
                switch(option){
                    case 1:{
                        bool cond2 = true;
                        do{
                            string mageOptions[] = {"Hechicero", "conjurador", "brujo", "nigromante"};
                            cout << "Elija uno entre estos magos: ";
                            for(auto i : mageOptions){
                                cout << i << " ";
                            }
                            cin >> PJ;
                            for(int i = 0; i < 3; i++){
                                if(PJ == mageOptions[i]){
                                    cond2 = false;
                                    cond = false;
                                    break;
                                }
                            }
                        }while(cond2);
                        break;
                    }
                    case 2:{
                        bool cond2 = true;
                        do{
                            string warriorOptions[] = {"barbaro", "paladin", "caballero", "mercenario", "gladiador"};
                            cout << "Elija uno entre estos guerreros: ";
                            for(auto i : warriorOptions){
                                cout << i << " ";
                            }
                            cin >> PJ;
                            for(int i = 0; i < 4; i++){
                                if(PJ == warriorOptions[i]){
                                    cond2 = false;
                                    cond = false;
                                    break;
                                }
                            }
                        }while(cond2);
                        break;
                    }
                    default:{
                        cout << "Opción no contemplada " << endl;
                    }
                }
                int portador;
                cout << "¿Cuantas armas quiere portar?" << endl;
                cout << "0. 0" << endl;
                cout << "1. 1" << endl;
                cout << "2. 2" << endl;
                cout << "Respuesta: ";
                cin >> portador;
                PersonajeFactory* personaje;
                switch(portador){
                    case 0:{
                        personaje->pjCreation(PJ);
                        break;
                    }
                    case 1:{
                        bool cond1 = true;
                        while(cond1){
                            string WPoptions[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
                            for(auto i : WPoptions) cout << i << " ";
                            cout << "Elija un arma entre las opciones: ";
                            string WP;
                            cin >> WP;
                            personaje->armedPJCreation(PJ, WP);
                            cond1 = false;
                        }
                        break;
                    }
                    case 2:{
                        bool cond1 = true;
                        while(cond1){
                            string WPoptions[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
                            for(auto i : WPoptions) cout << i << " ";
                            string WP1;
                            string WP2;
                            cout << "Elija las armas que desee entre las opciones: ";
                            cout << "Arma 1: ";
                            cin >> WP1;
                            cout << endl;
                            cout << "Arma 2: ";
                            cin >> WP2;
                            cout << endl;
                            personaje->armedPJCreation(PJ, WP1);
                            personaje->

                        }
                    }
                }
            }   
        }
    }
}