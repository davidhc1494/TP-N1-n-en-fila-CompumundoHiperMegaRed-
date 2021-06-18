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

	t->inicializarTablero(3,3,3);

	t->verTablero();

	t->jugarFicha(1, 2, 1);
	t->jugarFicha(1, 2, 1);
	t->jugarFicha(1, 2, 1);
	t->jugarFicha(1, 3, 1);
	t->jugarFicha(2, 2, 1);
	t->jugarFicha(3, 2, 1);

	t->verTablero();

	return 0;

}
