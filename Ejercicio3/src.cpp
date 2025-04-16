#include "func.h"

void inicializaciónPJs(){
    // Solicito el personaje 
    int option;
    cout << "¿Que tipo de personaje quiere? " << endl;
    cout << "1. mago" << endl;
    cout << "2. guerrero" << endl;
    cout << "Respuesta: ";
    cin >> option;
    string PJ; // Defino PJ para guardarme el personaje deseado 
    int opt;
    switch(option){
        case 1:{
            string mageOptions[] = {"Hechicero", "conjurador", "brujo", "nigromante"};
            cout << "Elija uno entre estos magos: ";
            // Imprimo las opciones posibles
            for(int i = 0; i < 4; i++){
                cout << "(" << i+1 << ")"<< mageOptions[i] << " ";
            }
            cout << "\nRespuesta: ";
            cin >> opt;
            PJ = mageOptions[opt-1]; // Lo pongo -1 ya que las opciones mostradas en pantalla empiezan desde el 1
            break;
        }
        case 2:{
            string warriorOptions[] = {"barbaro", "paladin", "caballero", "mercenario", "gladiador"};
            cout << "Elija uno entre estos guerreros: ";
            for(int i = 0; i < 5; i++){
                cout << "(" << i+1 << ")"<< warriorOptions[i] << " ";
            }
            cout << "\nRespuesta: ";
            cin >> opt;
            PJ = warriorOptions[opt-1];
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
    PersonajeFactory personaje; // Defino personaje como factory para crear el objeto
    shared_ptr<personajes> pj; // Defino el personaje que será enviado a la batalla
    switch(portador){
        case 0:{
            pj = personaje.armedPJCreation(PJ, "", 0);
            break;
        }
        case 1:{
            string WPoptions[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
            cout << "Elija un arma entre las opciones: ";
            // Imprimo todas las armas posibles, sin restricciones en si es mago o guerrero, un mago puede llevar 
            // armas de melee, y un guerrero puede llevar armas mágicas y funcionar de la misma manera
            for(int i = 0; i < 8; i++){
                cout << "(" << i+1 << ")" << WPoptions[i] << " ";
            }
            cout << "\nRespuesta: ";
            int opt;
            cin >> opt;
            string WP = WPoptions[opt-1];
            pj = personaje.armedPJCreation(PJ, WP, 1);
            break;
        }
        case 2:{
            string WPoptions[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
            cout << "Elija las armas que desee entre las opciones: ";
            for(int i = 0; i < 8; i++){
                cout << "(" << i+1 << ")" << WPoptions[i] << " ";
            }
            int opt1;
            int opt2;
            cout << "\nArma 1: ";
            cin >> opt1;
            string WP1 = WPoptions[opt1-1];
            cout << "Arma 2: ";
            cin >> opt2;
            string WP2 = WPoptions[opt2-1];
            cout << endl;
            pj = personaje.armedPJCreation(PJ, WP1, 2, WP2);
            break;
        }
        default:{
            throw invalid_argument("Opción no contemplada");
            break;
        }
    }

    // Creación de un personaje aleatorio con armas aleatorias el cual va a ser el contrincante del usuario durante la 
    // batalla
    string pjOptions[] = {"barbaro", "paladin", "caballero", "mercenario", "gladiador", "Hechicero", "conjurador", "brujo", "nigromante"};
    string WPOptions[] = {"varita", "LibroHechizos", "PocionDeVida", "Hacha_giratoria", "Hoja_de_viento", "Aguja_sombria", "Espada_de_los_oscuros", "Tridente_colosal"};
    PersonajeFactory personaje2;
    shared_ptr<personajes> cpu;
    int weapons = rand() % 3;
    string randomPJ = pjOptions[rand() % 9];
    string randomWP = WPOptions[rand() % 9];
    if(weapons == 0) {cpu = personaje2.armedPJCreation(randomPJ, "", 0);}
    else if(weapons == 1) {cpu = personaje2.armedPJCreation(randomPJ, randomWP, 1);}
    else{
        string randomWP2 = WPOptions[rand() % 8];
        cpu = personaje2.armedPJCreation(randomPJ, randomWP, 2, randomWP2);
    }

    // Y automaticamente inicio la batalla
    batalla(pj, cpu);
}

void batalla(shared_ptr<personajes> pj1, shared_ptr<personajes> cpu){
    // Si no se encuentra ningun personaje no puede haber una batalla asi que tira error
    if(!pj1) throw runtime_error("Argumento Inválido");
    if(!cpu) throw runtime_error("Argumento Inválido");

    // Consigo las armas primarias y secundarias de ambos contrincantes en busca de poción o amuleto para seleccionar 
    // el arma con la que pelearán
    // La terminación _weapon, va a ser aquella arma con la que pelearán, la cual por defecto es el arma primaria
    shared_ptr<armas> pj1_weapon = pj1->getPrimaryWP();
    shared_ptr<armas> pj1_secWP = pj1->getSecondaryWP();
    shared_ptr<armas> cpu_weapon = cpu->getPrimaryWP();
    shared_ptr<armas> cpu_secWP = cpu->getSecondaryWP();

    // Condición que se utilizará para consumir la poción en caso de tener una 
    bool pj1_potion = false;
    bool cpu_potion = false;

    if(pj1_weapon != nullptr){
        // Si el arma primaria es una poción o amuleto, pone como arma para pelear, el arma primaria
        if(pj1_weapon->getName() == "Poción de Vida" || pj1_weapon->getName() == "Amuleto de Vida"){
            if(pj1_weapon->getName() == "Poción de Vida") pj1_potion = true; // Y si es una poción, lo pone en true
            pj1_weapon = pj1->getSecondaryWP();
            // Pero si nuevamente el arma secundaria es una poción o un amuleto, simplemente se asigna que no tiene
            // arma para pelear. Cuyo caso se aborda mas adelante
            if(pj1_weapon->getName() == "Poción de Vida" || pj1_weapon->getName() == "Amuleto de Vida"){
                pj1_weapon = nullptr;
            }
        }else if(pj1_secWP != nullptr && pj1_secWP->getName() == "Poción de Vida") pj1_potion = true;
    }
    // Misma situación para el contrincante del usuario
    if(cpu_weapon != nullptr){
        if(cpu_weapon->getName() == "Poción de Vida" || cpu_weapon->getName() == "Amuleto de Vida"){
            if(cpu_weapon->getName() == "Poción de Vida") cpu_potion = true;
            cpu_weapon = cpu->getSecondaryWP();
            if(cpu_weapon->getName() == "Poción de Vida" || cpu_weapon->getName() == "Amuleto de Vida"){
                cpu_weapon = nullptr;
            }
        }else if(cpu_secWP != nullptr && cpu_secWP->getName() == "Poción de Vida") cpu_potion = true;
    }

    // Establezco la condición en la que alguno ganó la batalla 
    bool player_winner = false;
    bool cpu_winner = false;

    cout << "Iniciando batalla..." << endl;
    cout << endl; 

    // Pongo el numero de rondas que se van realizando 
    int round = 1;

    // En caso de que ninguno de los contrincantes posea un arma, se decide un empate
    // Sino, el peleador sin arma es perdedor automaticamente
    if(pj1_weapon == nullptr && cpu_weapon == nullptr){
        cout << "Ningun peleador tiene un arma para combatir, por ende queda en un empate y se hacen amigos." << endl;
        return;
    }else if(pj1_weapon == nullptr){
        cout << "El " << pj1->getName() << " no tiene arma! Por ende recibe una aplastante derrota por parte del " << cpu->getName() << "." << endl;
        cpu_winner = true;
    }else if (cpu_weapon == nullptr){
        cout << "El " << cpu->getName() << " no tiene arma! Por ende recibe una aplastante derrota por parte del " << pj1->getName() << "." << endl;
        player_winner = true;
    }

    // Inicio de pelea
    while(!player_winner && !cpu_winner){
        cout << "Ronda " << round << endl;
        round++;
        // Lista de las posibles jugadas
        string plays[] = {"Golpe Fuerte", "Golpe Rápido", "Defensa y Golpe"};
        cout << "El jugador (" << pj1->getName() << ") tiene " << pj1->getHP() << " HP y la CPU (" << cpu->getName() << ") tiene " << cpu->getHP() << " HP." << endl;
        int option;
        cout << "Opciones: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe " << endl;
        cout << "Su opción: ";
        cin >> option;
        
        // Si se pasa un mal argumento, vuelve a pedir 
        if(option != 1 && option != 2 && option != 3){
            round -= 1; 
            cout << "Opción no contemplada" << endl;
            cout << endl;
            continue;
        }

        // Elijo la opción del contrincante aleatoriamente, y la opción del jugador se pone en -1 porque las opciones 
        // se muestran desde el 1
        string pj1_choice = plays[option - 1];
        string cpu_choice = plays[rand() % 3];
    
        // Si el usuario o el contrincante tienen una poción y están a menos de la mitad de la vida, la utilizan y 
        // no la pueden volver a utilizar mas
        if(pj1->getHP() < 50 && pj1_potion) {
            pj1->consumePotion();
            cout << "¡El " << pj1->getName() << " ha consumido una poción que tenía escondida y ha restaurado 20HP.!" << endl;
            pj1_potion = false;
        }
        if(cpu->getHP() < 50 && cpu_potion) {
            cpu->consumePotion(); 
            cout << "¡El " << cpu->getName() << " ha consumido una poción y ha restaurado 20HP.!" << endl;
            cpu_potion = false;
        }

        // Si ambos realizan el mismo ataque, no pasa nada y se pasa al siguiente round
        if(pj1_choice == cpu_choice) {
            cout << "Ambos peleadores realizan el mismo ataque, haciendo que los ataques choquen y ninguno reciba daño." << endl; 
        }

        // Sino, diferencio los casos en los que gana el jugador de acuerdo a los golpes que se realicen
        else if((pj1_choice == "Golpe Fuerte" && cpu_choice == "Golpe Rápido") || (pj1_choice == "Golpe Rápido" && cpu_choice == "Defensa y Golpe")){
            // Si el siguiente golpe mata al contrincante, utiliza la ultimate y gana la batalla
            if(cpu->getHP()-10 <= 0){
                cout << "El " << cpu->getName() << " cae derrotado al suelo, y el " << pj1->getName() << " utiliza su ultimo ataque: " << pj1->getUltimate() << ". Ejecutandolo y consagrandose con la victoria." << endl; 

                // Pero existe una probabilidad de 1 entre 10 que el derrotado pueda revivir con 10HP para dar un último golpe, o remontar la batalla
                if(rand() % 11 == 1){ 
                    cout << "Pero espera... la batalla no acabó. ¡" << cpu->getName() << " ha tenido un ascenso divino y ha vuelto de la muerte con 10 puntos de vida extra! ¡Que siga la batalla!" << endl;
                    cpu->increaseHP();
                } 
                
                else player_winner = true;
            }
            // En caso de que el siguiente golpe no lo mate, simplemente lanza el ataque correspondiente y le disminuye la vida
            else{
                cout << "El " << pj1->getName() << " ataca con su " << pj1_weapon->getName() << " lanzando un " << pj1_weapon->golpeFuerte() << " haciendo un " << pj1_choice << " contra el " << cpu->getName() << " que realizó un " << cpu_choice << ", infligiendole 10 puntos de daño " << endl;
                cpu->decreaseHP();
            }
        }
        
        // Hago una diferencia en los casos en los que tanto el usuario como el contrincante se defiendan exitosamente, solamente para mostrar
        // la habilidad defensiva de cada arma, y utiliza las mismas condiciones mencionadas arriba (ultimate y revivir)
        else if(pj1_choice == "Defensa y Golpe" && cpu_choice == "Golpe Fuerte"){
            if(cpu->getHP()-10 <= 0){
                cout << "El " << cpu->getName() << " cae derrotado al suelo, y el " << pj1->getName() << " utiliza su ultimo ataque: " << pj1->getUltimate() << ". Ejecutandolo y consagrandose con la victoria." << endl; 
                if(rand() % 11 == 1){ 
                    cout << "Pero espera... la batalla no acabó. ¡" << cpu->getName() << " ha tenido un ascenso divino y ha vuelto de la muerte con 10 puntos de vida extra! ¡Que siga la batalla!" << endl;
                    cpu->increaseHP();
                } else player_winner = true;
            }else{
                cout << "El " << pj1->getName() << " se defiende utilizando " << pj1_weapon->defender() << " desviando el ataque del " << cpu->getName() << " infligiendole daño." << endl;
                cpu->decreaseHP();
            }
        }else if(pj1_choice == "Golpe Fuerte" && cpu_choice == "Defensa y Golpe"){
            if(pj1->getHP()-10 <= 0){
                cout << "El " << pj1->getName() << " cae derrotado al suelo, y el " << cpu->getName() << " utiliza su ultimo ataque: " << cpu->getUltimate() << ". Ejecutandolo y consagrandose con la victoria." << endl; 
                if(rand() % 11 == 1){ 
                    cout << "Pero espera... la batalla no acabó. ¡" << pj1->getName() << " ha tenido un ascenso divino y ha vuelto de la muerte con 10 puntos de vida extra! ¡Que siga la batalla!" << endl;
                    pj1->increaseHP();
                } else cpu_winner = true;
            }else{
                cout << "El " << cpu->getName() << " se defiende utilizando " << cpu_weapon->defender() << " desviando el ataque del " << pj1->getName() << " infligiendole daño." << endl;
                pj1->decreaseHP();
            }
        }

        // Si el usuario no ganó el round, significa que lo hizo el contrincante, y se contemplan las mismas situaciones
        // que para el usuario (ultimate y revivir)
        else{
            if(pj1->getHP()-10 <= 0){
                cout << "El " << pj1->getName() << " cae derrotado al suelo, y el " << cpu->getName() << " utiliza su ultimo ataque: " << cpu->getUltimate() << ". Ejecutandolo y consagrandose con la victoria." << endl; 
                if(rand() % 11 == 1){ 
                    cout << "Pero espera... la batalla no acabó. ¡" << pj1->getName() << " ha tenido un ascenso divino y ha vuelto de la muerte con 10 puntos de vida extra! ¡Que siga la batalla!" << endl;
                    pj1->increaseHP();
                } else cpu_winner = true;
            }else{
                cout << "El " << cpu->getName() << " ataca con su " << cpu_weapon->getName() << " lanzando un " << cpu_weapon->golpeFuerte() << " haciendo un " << cpu_choice << " contra el " << pj1->getName() << " que realizó un " << pj1_choice << ", infligiendole 10 puntos de daño " << endl;
                pj1->decreaseHP();
            }
        }
        cout << endl;
    }

    // Cuando termina, se fija cual es el ganador, o si es un empate
    cout << endl;
    if(player_winner) cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡El jugador es el ganador!!!!!!!!!!!!!!!!" << endl;
    else if(cpu_winner) cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡La CPU es el ganador!!!!!!!!!!!!!!!!" << endl;
    else cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Es un empate!!!!!!!!!!!!!!!!" << endl;
}
