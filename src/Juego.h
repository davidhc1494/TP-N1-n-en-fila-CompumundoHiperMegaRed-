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

	//PRE:-
	//POS: crea un objeta juego
	Juego();

	//PRE: tiene que exsitir juego
	//POS: devuelve el tablero
	Tablero* getTablero();

	//PRE: tiene que exsitir juego
	//POS: devuelve la lista de jugadores
	Lista<Jugador*>* getListaDeJugadores();

	//PRE: tiene que exsitir juego
	//POS: devuelve el mazo de cartas
	Mazo* getMazo();

	//PRE: tiene que exsitir juego
	//POS: agregaa jugador con los parametros pasados
	void agregarJugador(int numeroDeNuevoJugador, char simboloFicha);

	//PRE: tiene que exsitir juego y la lista de jugadores no tiene que estar vacia
	//POS: inicia la mano de los jugadores con 3 cartas
	void iniciarManoDeJuGadores();

	//PRE: tiene que exsitir juego
	//POS: el jugador pasado comoparametro toma una carta y se agrega a su lista de cartas
	void tomarCarta(Jugador* jugador);

	//PRE: tiene que exsitir juego y el jugador ni tiene que tener su lista de cartas vacia
	//POS: muestra todas las cartas que tiene en su mano el jugador
	void mostrarCartasDeJugador(Jugador* jugador);

	//PRE: tiene que exsitir juego, y la lista no tiene que estar vacia
	//POS: elimina todas las cartas de la mano del jugador
	void descartarManoDeJugador(Jugador* jugador);
	
	//PRE: tiene que exsitir juego
	//POS: borra juego
	~Juego();

};



#endif /* JUEGO_H_ */
