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
	Menu* m = new Menu();
	m->Jugar();
	return 0;
}
