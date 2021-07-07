/*
 * Munu.h
 *
 *  Created on: 7 jul. 2021
 *      Author: David
 */

#ifndef MENU_H_
#define MENU_H_

#include "Juego.h"

class Menu{

private:

	Juego* juego;

public:

	Menu();

	void Jugar();

	void ingresarTamanioDeTablero();

	void ingresarCantidadDeJugadoresAJugar();

};



#endif /* MENU_H_ */
