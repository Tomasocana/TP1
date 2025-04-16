#include "armas.h"
#include "personajes.h"

int main(){
    cout << "Creo dos personajes: Un Bárbaro y un Brujo." << endl;
    barbaro barb;
    brujo bruj;

    cout << "El barbaro tiene " << barb.getHP() << " puntos de vida." << endl;
    cout << "El brujo tiene " << bruj.getHP() << " puntos de vida." << endl;

    cout << "Creo 4 armas, un hacha giratoria y un amuleto, los cuales serán para el brujo, y una varita y una poción que serán para el bárbaro." << endl;
    shared_ptr<Hacha_giratoria> hacha = make_shared<Hacha_giratoria>();
    shared_ptr<AmuletoDeVida> amuleto = make_shared<AmuletoDeVida>();
    shared_ptr<varita> var = make_shared<varita>();
    shared_ptr<PocionDeVida> pocion = make_shared<PocionDeVida>();
    cout << endl;

    cout << "Asigno las armas correspondientes" << endl;
    vector<shared_ptr<armas>> armasBarbaro;
    armasBarbaro.push_back(var);
    armasBarbaro.push_back(pocion);
    barb.setArma(armasBarbaro);
    vector<shared_ptr<armas>> armasbrujo;
    armasbrujo.push_back(hacha);
    armasbrujo.push_back(amuleto);
    bruj.setArma(armasbrujo);
    cout << endl;

    cout << "El arma primaria del bárbaro es: " << barb.getPrimaryWP()->getName() << "\nY el arma secundaria es: " << barb.getSecondaryWP()->getName() << endl;
    cout << "El arma primaria del brujo es: " << bruj.getPrimaryWP()->getName() << "\nY el arma secundaria es: " << bruj.getSecondaryWP()->getName() << endl;
    cout << endl;

    cout << "Como el brujo tiene un amuleto, eso significa que adquiere las estadisticas puestas del amuleto, la cual es: vida extra" << endl;
    bruj.asignarAmuleto();
    cout << "Entonces el brujo tiene " << bruj.getHP() << " puntos de vida iniciales." << endl;
    cout << endl;

    cout << "El brujo ataca 3 veces al bárbaro con su hacha: " << endl;
    for(int i = 0; i < 3; i++){
        cout << "   El brujo realiza el ataque " << hacha->golpeFuerte() << "(golpe fuerte) con su hacha y le inflije 10 de daño al bárbaro." << endl;
        barb.decreaseHP();
    }
    cout << "Ahora el bárbaro tiene " << barb.getHP() << " puntos de vida, por eso se va a tomar la poción para recuperar vida." << endl;
    barb.consumePotion();
    cout << "Ahora el bárbaro tiene " << barb.getHP() << " puntos de vida." << endl;

}