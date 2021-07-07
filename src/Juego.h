/*
 * Juego.h
 *
 *  Created on: 7 jul. 2021
 *      Author: David
 */

#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"

class Juego{
private:

	Tablero* tablero;
	Lista<Jugador*>* listaDeJugadores;
	Mazo* mazo;


public:

	Juego();

	Tablero* getTablero();

	Lista<Jugador*>* getListaDeJugadores();


	void agregarJugador(int numeroDeNuevoJugador);

};



#endif /* JUEGO_H_ */
