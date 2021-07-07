/*
 * Jugador.h
 *
 *  Created on: 4 jul. 2021
 *      Author: claudio
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include<iostream>
#include "Lista.h"
#include "Ficha.h"
#include "Carta.h"
#include "Mazo.h"

class Jugador {
private:
	int numeroDeJugador;
	Lista<Ficha*>* fichas;
	Lista<Carta*>* cartas;
	//Mazo* mazo;

public:
	/*
	 * Pre: numero de jugador debe ser mayor a cero.
	 * Post: crea una instacia de Jugador.
	 */
	Jugador(int numeroDeJugador);

	/*
	 * Pre:
	 * Post: saca una carta del maso de cartas y la agrega a la lista de cartas del jugador.
	 */
	Carta* sacarCarta();

	/*
	 * Pre:
	 * Post: muestra las cartas que tiene el jugador.
	 */
	Lista<Carta*>* obtenerCartas();

	/*
	 * Pre: se pasa el numero de carta a canjear.
	 * Post: devuelve la carta a canjear y la elimina de la lista de cartas del jugador.
	 */
	Carta* canjearCarta(int numeroDeCarta);

	/*
	 * Post: agrega una carta a la lista de cartas del jugador.
	 */

	void guardarCarta(Carta* carta);

};


#endif /* JUGADOR_H_ */
