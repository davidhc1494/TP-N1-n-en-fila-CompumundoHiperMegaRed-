/*
 * Juego.cpp
 *
 *  Created on: 7 jul. 2021
 *      Author: David
 */
#include "Juego.h"

Juego::Juego(){

	this->tablero = new Tablero();
	this->tablero->setTamanio(1);
	//this->tablero->inicializarTablero(tamanioDeTablero, tamanioDeTablero, tamanioDeTablero);
	this->mazo = new Mazo();
	this->listaDeJugadores = new Lista<Jugador*>();

}

Tablero* Juego::getTablero(){
	return this->tablero;
}

Lista<Jugador*>* Juego::getListaDeJugadores(){
	return this->listaDeJugadores;
}

void Juego::agregarJugador(int numeroDeNuevoJugador){

	Jugador* nuevoJugador = new Jugador(numeroDeNuevoJugador);

	this->listaDeJugadores->agregar(nuevoJugador);

}





