/*
 * Menu.cpp
 *
 *  Created on: 7 jul. 2021
 *      Author: David
 */
#include "Menu.h"


Menu::Menu(){
	this->juego = new Juego();
}

void Menu::Jugar(){
/*	int tamanio = 0;
	int numeroDeNuevoJugador = 0;
	int numeroDePlano;
	int numeroDeColumna;
	bool hayGanador = false;

	std::cout<<"Ingrese el tamanio del tablero: ";
	std::cin>>tamanio;
	if(tamanio<=0){
		std::cout<<"TAMANIO INGRESADO MENOR O IGUAL A 0(cero)"<<std::endl;
	}
*/

	int tamanio = 0;
	int numeroDeNuevoJugador = 0;
	int numeroDePlano;
	int numeroDeColumna;
	bool hayGanador = false;

	do{
		std::cout<<"Ingrese el tamanio del tablero: ";
		std::cin>>tamanio;
		if(tamanio<=0){
			std::cout<<"TAMANIO INGRESADO MENOR O IGUAL A 0(cero)"<<std::endl;
		}
	}while(tamanio<=0);
	juego->getTablero()->setTamanio(tamanio);
	juego->getTablero()->inicializarTablero(tamanio, tamanio, tamanio);

	do{
		std::cout<<"Ingrese la cantidad de jugadore que van a jugar : ";
		std::cin>>numeroDeNuevoJugador;
	}while(numeroDeNuevoJugador<=0);

	for(int i = 1;i<=numeroDeNuevoJugador;i++){
		this->juego->agregarJugador(i);
	}
	std::cout<<""<<std::endl;
	std::cout<<"      INICIA EL JUEGO      "<<std::endl;
	std::cout<<""<<std::endl;

	this->juego->getListaDeJugadores()->iniciarCursor();

	while(hayGanador ==false){
		while(this->juego->getListaDeJugadores()->avanzarCursor() && hayGanador == false){
			std::cout<<"TURNO DEL JUGADOR N°: "<<this->juego->getListaDeJugadores()->obtenerCursor()->getFicha()->verNumeroDeJugador()<<std::endl;
			std::cout<<"Ingrese numero de plano: "<<std::endl;
			std::cin>>numeroDePlano;
			std::cout<<"Ingrese numero de columna: "<<std::endl;
			std::cin>>numeroDeColumna;

			hayGanador = this->juego->getTablero()->jugarFicha(numeroDePlano, numeroDeColumna, this->juego->getListaDeJugadores()->obtenerCursor()->getFicha()->verNumeroDeJugador());
			this->juego->getTablero()->verTablero();
		}
		this->juego->getListaDeJugadores()->iniciarCursor();
	}

}

