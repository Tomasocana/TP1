#include "func.h"

void batalla(shared_ptr<personajes> pj1, shared_ptr<personajes> cpu){
    bool player_winner = false;
    bool cpu_winner = false;
    while(!player_winner && !cpu_winner){
            string plays[] = {"Golpe Fuerte", "Golpe Rápido", "Defensa y Golpe"};
            static int round = 1;

            cout << "El jugador (" << pj1->getName() << ") tiene " << pj1->getHP() << " HP y la CPU (" << cpu->getName() << ") tiene " << cpu->getHP() << " HP." << endl;
            int option;
            cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";
            cin >> option;
            cout << endl;

            string pj1_choice = plays[option - 1];
            string cpu_choice = plays[(rand() / RAND_MAX) * (2 - 0) + 0];

            shared_ptr<armas> pj1_primary = pj1->getPrimaryWP();
            shared_ptr<armas> cpu_primary = cpu->getPrimaryWP();
        
            if(pj1_choice == cpu_choice) continue;
            else if((pj1_choice == "Golpe Fuerte" && cpu_choice == "Golpe Rápido") || (pj1_choice == "Golpe Rápido" && cpu_choice == "Defensa y Golpe") || (pj1_choice == "Defensa y Golpe" && cpu_choice == "Golpe Fuerte")){
                if(cpu->getHP()-10 < 0){
                    cout << "El " << cpu->getName() << " cae derrotado al suelo, y el " << pj1->getName() << " utiliza su ultimo ataque: " << pj1->getUltimate() << ". Ejecutandolo y consagrandose con la victoria." << endl; 
                    if(((rand() / RAND_MAX) * (10 - 0) + 0) == 1){ 
                        cout << "Pero espera... la batalla no acabó. ¡" << cpu->getName() << " ha tenido un ascenso divino y ha vuelto de la muerte con 10 puntos de vida extra! ¡Que siga la batalla!" << endl;
                        cpu->increaseHP();
                    } else player_winner = true;
                }else{
                    cout << "El " << pj1->getName() << " ataca con su " << pj1_primary->getName() << " lanzando un " << pj1_primary->golpeFuerte() << " contra el " << cpu->getName() << " infligiendole 10 puntos de daño " << endl;
                    cpu->decreaseHP();
                }

            }else{
                if(pj1->getHP()-10 < 0){
                    cout << "El " << pj1->getName() << " cae derrotado al suelo, y el " << cpu->getName() << " utiliza su ultimo ataque: " << cpu->getUltimate() << ". Ejecutandolo y consagrandose con la victoria." << endl; 
                    if(((rand() / RAND_MAX) * (10 - 0) + 0) == 1){ 
                        cout << "Pero espera... la batalla no acabó. ¡" << pj1->getName() << " ha tenido un ascenso divino y ha vuelto de la muerte con 10 puntos de vida extra! ¡Que siga la batalla!" << endl;
                        pj1->increaseHP();
                    } else cpu_winner = true;
                }else{
                    cout << "El " << cpu->getName() << " ataca con su " << cpu_primary->getName() << " lanzando un " << cpu_primary->golpeFuerte() << " contra el " << pj1->getName() << " infligiendole 10 puntos de daño " << endl;
                    pj1->decreaseHP();
                }
            }
        }
    cout << endl;
    if(player_winner) cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡El jugador es el ganador!!!!!!!!!!!!!!!!" << endl;
    else cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡La CPU es el ganador!!!!!!!!!!!!!!!!" << endl;
}

void inicializaciónPJs(){
    int option;
    cout << "¿Que tipo de personaje quiere? " << endl;
    cout << "1. mago" << endl;
    cout << "2. guerrero" << endl;
    cin >> option;
    string PJ;
    switch(option){
        case 1:{
            string mageOptions[] = {"Hechicero", "conjurador", "brujo", "nigromante"};
            cout << "Elija uno entre estos magos: ";
            for(auto i : mageOptions){
                cout << i << " ";
            }
            cin >> PJ;
            break;
        }
        case 2:{
            string warriorOptions[] = {"barbaro", "paladin", "caballero", "mercenario", "gladiador"};
            cout << "Elija uno entre estos guerreros: ";
            for(auto i : warriorOptions){
                cout << i << " ";
            }
            cin >> PJ;
            break;
        }
        default:{
            throw invalid_argument("Opción no contemplada");
        }
    }
    int portador;
    cout << "¿Cuantas armas quiere portar?" << endl;
    cout << "0. 0" << endl;
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "Respuesta: ";
    cin >> portador;
    PersonajeFactory personaje;
    shared_ptr<personajes> pj;
    switch(portador){
        case 0:{
            shared_ptr<personajes> pj = personaje.armedPJCreation(PJ, "", 0);
            break;
        }
        case 1:{
            string WPoptions[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
            for(auto i : WPoptions) cout << i << " ";
            cout << "Elija un arma entre las opciones: ";
            string WP;
            cin >> WP;
            shared_ptr<personajes> pj = personaje.armedPJCreation(PJ, WP, 1);
            break;
        }
        case 2:{
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
            shared_ptr<personajes> pj = personaje.armedPJCreation(PJ, WP1, 0, WP2);
            break;
        }
        default:{
            throw invalid_argument("Opción no contemplada");
        }
    }

    string pjOptions[] = {"barbaro", "paladin", "caballero", "mercenario", "gladiador", "Hechicero", "conjurador", "brujo", "nigromante"};
    string WPOptions[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
    PersonajeFactory personaje2;
    shared_ptr<personajes> cpu;
    int weapons = (rand() / RAND_MAX) * (2 - 0) + 0;
    string randomPJ = pjOptions[(rand() / RAND_MAX) * (8 - 0) + 0];
    string randomWP = WPOptions[(rand() / RAND_MAX) * (8 - 0) + 0];
    if(weapons == 0) cpu = personaje2.armedPJCreation(randomPJ, "", 0);
    else if(weapons == 1) cpu = personaje2.armedPJCreation(randomPJ, randomWP, 1);
    else{
        string randomWP2 = WPOptions[(rand() / RAND_MAX) * (8 - 0) + 0];
        cpu = personaje2.armedPJCreation(randomPJ, randomWP, 2, randomWP2);
    }
    batalla(pj, cpu);
}