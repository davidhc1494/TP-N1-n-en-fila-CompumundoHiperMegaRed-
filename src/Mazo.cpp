/*
 * Mazo.cpp
 *
 *  Created on: 5 jul. 2021
 *      Author: claudio
 */

#include "Mazo.h"
#include <iostream>

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

void Mazo::inicializarMazo(){

	for(int i = 1;i <= this->cantidadDeCartas;i++){
		Carta* nuevaCarta1 = new Carta(CartaJugadaDoble);
		this->agregarCartas(nuevaCarta1);
		Carta* nuevaCarta2 = new Carta(CartaBloquearTurno);
		this->agregarCartas(nuevaCarta2);
		i++;
		Carta* nuevaCarta3 = new Carta(CartaNoLevantaCarta);
		this->agregarCartas(nuevaCarta3);
		i++;
	}
}
