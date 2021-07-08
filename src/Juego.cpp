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
	this->mazo->inicializarMazo();

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

Mazo* Juego::getMazo(){
	return this->mazo;
}

void Juego::iniciarManoDeJuGadores(){

	this->listaDeJugadores->iniciarCursor();

	while(this->listaDeJugadores->avanzarCursor()){

		for(int i=1;i<=3;i++){
			this->listaDeJugadores->obtenerCursor()->obtenerCartas()->agregar(this->mazo->sacarCarta());
		}

	}

}

void Juego::tomarCarta(Jugador* jugador){
	if(jugador->obtenerCartas()->contarElementos()>3){
		jugador->obtenerCartas()->agregar(this->mazo->sacarCarta());
	}
}

void mostrarCartasDeJugador(Jugador* jugador){
	int contadorDeCartas = 1;
	jugador->obtenerCartas()->iniciarCursor();

	while(jugador->obtenerCartas()->avanzarCursor()){
		std::cout<<contadorDeCartas<<" - "<<jugador->obtenerCartas()->obtenerCursor()->getNombreDeTipoDeCarta()<<std::endl;
		contadorDeCartas++;
	}
}

Juego::~Juego(){
	delete this->tablero;
	delete this->mazo;
	delete this->listaDeJugadores;
}


