/*
 * Jugador.cpp
 *
 *  Created on: 5 jul. 2021
 *      Author: claudio
 */

#include "Jugador.h"

Jugador::Jugador(int numeroDeJugador){
	if (numeroDeJugador < 0) {
		throw("el numero de Jugador es menor a cero.");
	}
	this->cartas = new Lista<Carta*>;
	this->fichas = new Lista<Ficha*>;
	this->numeroDeJugador = numeroDeJugador;
}

void Jugador::guardarCarta(Carta* carta){
	this->cartas->agregar(carta);
}

Lista<Carta*>* Jugador::obtenerCartas(){
	return this->cartas;
}

Carta* Jugador::canjearCarta(int numeroDeCarta){
	Carta* carta = new Carta(this->cartas->obtener(numeroDeCarta)->obtenerTipoDeCarta());
	this->cartas->remover(numeroDeCarta);
	return carta;
}

