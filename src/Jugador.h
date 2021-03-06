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
	Ficha* fichas;
	Lista<Carta*>* cartas;

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

	Ficha* getFicha();

	void setFicha(int nuevoNumeroDeFicha);

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
	
	/*
	 * PRE: -
	 * POST: Destruye el jugador, liberando la memoria utilizada.-
	 */
	~Jugador();

};


#endif /* JUGADOR_H_ */
