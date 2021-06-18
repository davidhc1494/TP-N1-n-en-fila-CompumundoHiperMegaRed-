/*
 * Tablero.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */
#include"Tablero.h"

Tablero::Tablero(){

	this->tablero = new Lista<Lista<Lista<Casillero*>*>*>();

}

void Tablero::inicializarTablero(int x,int y,int z){

	for(int i=0;i<z;i++){
		Lista<Lista<Casillero*>*> *nivel1 = new Lista<Lista<Casillero*>*>();

		for(int j=0;j<y;j++){

			Lista<Casillero*> *nivel2 = new Lista<Casillero*>();

			for(int k=0;k<x;k++){

				Casillero *nuevoCasillero = new Casillero();

				nivel2->agregar(nuevoCasillero);

			}

			nivel1->agregar(nivel2);

		}

		this->tablero->agregar(nivel1);

	}

}

void Tablero::verTablero(){
	int numeroDePlano = 1;

	this->tablero->iniciarCursor();

	while(this->tablero->avanzarCursor()){

		std::cout<<"Plano N°: "<<numeroDePlano<<std::endl;
		this->tablero->obtenerCursor()->iniciarCursor();

		while(this->tablero->obtenerCursor()->avanzarCursor()){

			this->tablero->obtenerCursor()->obtenerCursor()->iniciarCursor();

			while(this->tablero->obtenerCursor()->obtenerCursor()->avanzarCursor()){

				std::cout<<this->tablero->obtenerCursor()->obtenerCursor()->obtenerCursor()->verFicha()->verNumeroDeJugador()<<" ";

			}
			std::cout<<""<<std::endl;
		}

		std::cout<<""<<std::endl;
		numeroDePlano++;
	}





}

void Tablero::jugarFicha(int numeroDePlano,int numeroDeColumna,int numeroDeJugador){

	bool fichaJugada = false;
	int contadorDeFilas = this->tablero->obtener(1)->obtener(1)->contarElementos();


	while(contadorDeFilas>0 && fichaJugada == false){

		if(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna)->verFicha()->verNumeroDeJugador() == 0 ){

			this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna)->verFicha()->cambiarNumeroDeFicha(numeroDeJugador);
			fichaJugada = true;
		}

		contadorDeFilas--;

	}

}



