/*
 * Ficha.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */



#include "Ficha.h"

Ficha::Ficha(int numeroDeJugador){
	this->numeroDeJugador = numeroDeJugador;
}


int Ficha::verNumeroDeJugador(){
	return this->numeroDeJugador;
}

void Ficha::cambiarNumeroDeFicha(int nuevoNumeroDeJugador){
	this->numeroDeJugador = nuevoNumeroDeJugador;
}

Ficha::~Ficha(){
}
