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
	this->numeroDeJugador = numeroDeJugador;
	this->fichas = new Ficha(numeroDeJugador);
}

Ficha* Jugador::getFicha(){
	return this->fichas;
}

void Jugador::setFicha(int nuevoNumeroDeFicha){
	this->numeroDeJugador = nuevoNumeroDeFicha;
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

Jugador::~Jugador(){
	delete this->cartas;
	delete this->fichas;
}



