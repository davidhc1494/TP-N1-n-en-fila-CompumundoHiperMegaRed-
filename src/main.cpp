/*
 * main.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */
#include <string>
#include <iostream>

using namespace std;

#include "Ficha.h"
#include "Casillero.h"
#include "Tablero.h"

int main(){


	Tablero *t = new Tablero();

	t->inicializarTablero(4,4,4);

	t->verTablero();

	return 0;
}
