/*
 * Ficha.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */



#include "Ficha.h"

Ficha::Ficha(int numeroDeJugador, char tipoDeFicha){
	this->numeroDeJugador = numeroDeJugador;
	this->tipoDeFicha = tipoDeFicha;
}


int Ficha::verNumeroDeJugador(){
	return this->numeroDeJugador;
}

char Ficha::verTipoDeFicha(){
	return this->tipoDeFicha;
}

void Ficha::cambiarNumeroDeFicha(int nuevoNumeroDeJugador, char tipoDeFicha){
	this->numeroDeJugador = nuevoNumeroDeJugador;
	this->tipoDeFicha = tipoDeFicha;
}

Ficha::~Ficha(){
}
