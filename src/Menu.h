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

	//PRE:-
	//POS: crea un menu
	Menu();

	//PRE: tiene que existir menu
	//POS: comienza el juego
	void Jugar();

	//PRE: tiene que existir menu
	//POS: se genera un tablero del tamaño pasado
	void ingresarTamanioDeTablero();

	//PRE: tiene que existir menu
	//POS: se define la cantidad de jugadores
	void ingresarCantidadDeJugadoresAJugar();

	//PRE: tiene que existir menu
	//POS: se defeine en que plano y columna se va a jugar la ficha
	//     y regresa un bool dependiendo si gano o continua el juego
	bool ingresarPlanoYColumna(Jugador* jugador);
	
	//PRE: tiene que existir menu
	//POS: se define si se juega o no una carta y dependiendo la opcion se devulve un bool
	bool elegirSiJugarUnaCarta();

	//PRE: tiene que existir menu
	//POS: se define el valor de la fila
	void ingresarValorNEnFila();

	//PRE: tiene que existir menu
	//POS: borra el menu
	~Menu();

};



#endif /* MENU_H_ */
