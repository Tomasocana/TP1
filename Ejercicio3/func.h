#pragma once

#include "Ejercicio2/factory.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void inicializaciónPJs();

void batalla(shared_ptr<personajes> pj1, shared_ptr<personajes> pj2);