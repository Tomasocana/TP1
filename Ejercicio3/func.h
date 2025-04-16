#pragma once

#include "Ejercicio2/factory.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Función para inicializar los personajes
void inicializaciónPJs();

// Función para inicializar la batalla
void batalla(shared_ptr<personajes> pj1, shared_ptr<personajes> pj2);