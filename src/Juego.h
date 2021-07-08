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

	Mazo* getMazo();

	void agregarJugador(int numeroDeNuevoJugador);

	void iniciarManoDeJuGadores();

	void tomarCarta(Jugador* jugador);

	void mostrarCartasDeJugador(Jugador* jugador);
	
	//PRE: -
	//POST: Destruye el juego, liberando la memoria reservada.-
	~Juego();

};



#endif /* JUEGO_H_ */
