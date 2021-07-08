/*
 * Casillero.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */
#include "Casillero.h"
#include<iostream>

Casillero::Casillero(){

	this->ficha = new Ficha(0);
	this->listaDeCasilleroAdyacentes = new Lista<CasilleroAdyacente*>;

}

Ficha* Casillero::verFicha(){
	return this->ficha;
}

Lista<CasilleroAdyacente*>* Casillero::getListaDeCasilleroAdyacentes(){
	return this->listaDeCasilleroAdyacentes;
}

void Casillero::agregarCasilleroAdyacente(Casillero* casillero, std::string coordenada){

		CasilleroAdyacente* nuevoCasilleroAdyacente = new  CasilleroAdyacente(coordenada, casillero);

		this->listaDeCasilleroAdyacentes->agregar(nuevoCasilleroAdyacente);
}

void Casillero::verCasilleroAdyacentes(){
	this->listaDeCasilleroAdyacentes->iniciarCursor();

	while(this->listaDeCasilleroAdyacentes->avanzarCursor()){
		std::cout<<"N° jugador: "<<this->listaDeCasilleroAdyacentes->obtenerCursor()->getCasillero()->verFicha()->verNumeroDeJugador()<<"  ||  Coordenada: "<<this->listaDeCasilleroAdyacentes->obtenerCursor()->getCoordenada()<<std::endl;
	}
}

Casillero::~Casillero(){
	this->ficha->~Ficha();
	delete this->ficha;
	this->listaDeCasilleroAdyacentes->~Lista();
	delete this->listaDeCasilleroAdyacentes;
}

/*-------------------------------------------------------------------------------------*/


CasilleroAdyacente::CasilleroAdyacente(std::string coordenada, Casillero* casillero){
	this->casilleroAdyacente = casillero;
	this->coordenada = coordenada;
}

std::string CasilleroAdyacente::getCoordenada(){
	return this->coordenada;
}

void CasilleroAdyacente::setCoordenada(std::string coordenada){
	this->coordenada = coordenada;
}

Casillero* CasilleroAdyacente::getCasillero(){
	return this->casilleroAdyacente;
}

void CasilleroAdyacente::setCasilleroAdyacente(Casillero* casillero){
	this->casilleroAdyacente = casillero;
}

CasilleroAdyacente::~CasilleroAdyacente(){
}



