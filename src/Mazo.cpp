/*
 * Mazo.cpp
 *
 *  Created on: 5 jul. 2021
 *      Author: claudio
 */

#include "Mazo.h"

Mazo::Mazo(){
	this->cantidadDeCartas = 40;
	this->cartas = new Cola<Carta*>;
}

Mazo::Mazo(int cantidadDeCartas){
	this->cantidadDeCartas = cantidadDeCartas;
	this->cartas = new Cola<Carta*>;
}

int Mazo::obtenerCantidadDeCartas(){
	return this->cantidadDeCartas;
}

void Mazo::agregarCartas(Carta* carta){
	this->cartas->acolar(carta);
}

Carta* Mazo::obtenerFrente(){
	return this->cartas->obtenerFrente();
}

Carta* Mazo::sacarCarta(){
	return this->cartas->desacolar();
}
