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
#include "Juego.h"
#include "Menu.h"
int main(){

/*
	Tablero *t = new Tablero();

	t->inicializarTablero(4,4,4);

	//t->verTablero();

	t->jugarFicha(1, 2, 1);
	t->jugarFicha(1, 2, 1);
	t->jugarFicha(1, 2, 1);
	//t->jugarFicha(1, 3, 1);
	//t->jugarFicha(2, 2, 1);
	//t->jugarFicha(3, 2, 1);
	t->jugarFicha(1, 4, 1);
	t->verTablero();
	t->jugarFicha(1, 2, 1);

	t->jugarFicha(1, 1, 1);
	t->jugarFicha(1, 2, 2);
	t->jugarFicha(1, 3, 3);

	t->jugarFicha(1, 1, 4);
	t->jugarFicha(1, 2, 5);
	t->jugarFicha(1, 3, 6);

	t->jugarFicha(1, 1, 7);
	t->jugarFicha(1, 2, 8);
	t->jugarFicha(1, 3, 9);
	//
	t->jugarFicha(2, 1, 10);
	t->jugarFicha(2, 2, 11);
	t->jugarFicha(2, 3, 12);

	t->jugarFicha(2, 1, 13);
	t->jugarFicha(2, 2, 14);
	t->jugarFicha(2, 3, 15);

	t->jugarFicha(2, 1, 16);
	t->jugarFicha(2, 2, 17);
	t->jugarFicha(2, 3, 18);
	//
	t->jugarFicha(3, 1, 19);
	t->jugarFicha(3, 2, 20);
	t->jugarFicha(3, 3, 21);

	t->jugarFicha(3, 1, 22);
	t->jugarFicha(3, 2, 23);
	t->jugarFicha(3, 3, 24);

	t->jugarFicha(3, 1, 25);
	t->jugarFicha(3, 2, 26);
	t->jugarFicha(3, 3, 27);


	t->jugarFicha(1, 1, 1);
	t->verTablero();
	t->jugarFicha(2, 2, 2);
	t->jugarFicha(2, 2, 1);
	t->verTablero();
	t->jugarFicha(3, 3, 2);
	t->jugarFicha(3, 3, 2);
	t->jugarFicha(3, 3, 1);
	t->verTablero();


	//t->vincularConCasilleroAdyacentes();
*/

	Menu* m = new Menu();

	m->Jugar();
	m->~Menu();
	delete m;

	return 0;

}
