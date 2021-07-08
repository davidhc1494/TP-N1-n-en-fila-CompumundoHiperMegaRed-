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

	bool hayGanador = false;

	this->ingresarTamanioDeTablero();
	this->ingresarCantidadDeJugadoresAJugar();

	std::cout<<""<<std::endl;
	std::cout<<"      INICIA EL JUEGO      "<<std::endl;
	std::cout<<""<<std::endl;

	this->juego->getListaDeJugadores()->iniciarCursor();

	while(hayGanador ==false){
		while(this->juego->getListaDeJugadores()->avanzarCursor() && hayGanador == false){

			std::cout<<" ¿Quiere jugar una carta? "<<std::endl;


			hayGanador = this->ingresarPlanoYColumna(this->juego->getListaDeJugadores()->obtenerCursor());

		}
		this->juego->getListaDeJugadores()->iniciarCursor();
	}

}

void Menu::ingresarTamanioDeTablero(){
	int tamanio = 0;

	do{
		std::cout<<"Ingrese el tamanio del tablero: ";
		std::cin>>tamanio;
		if(tamanio<=0){
			std::cout<<"TAMANIO INGRESADO MENOR O IGUAL A 0(cero)"<<std::endl;
		}
	}while(tamanio<=0);
	juego->getTablero()->setTamanio(tamanio);
	juego->getTablero()->inicializarTablero(tamanio, tamanio, tamanio);
}

void Menu::ingresarCantidadDeJugadoresAJugar(){
	int numeroDeNuevoJugador = 0;

	do{
		std::cout<<"Ingrese la cantidad de jugadores que van a jugar : ";
		std::cin>>numeroDeNuevoJugador;
	}while(numeroDeNuevoJugador<=0);

	for(int i = 1;i<=numeroDeNuevoJugador;i++){
		this->juego->agregarJugador(i);
	}
	this->juego->iniciarManoDeJuGadores();
}

bool Menu::ingresarPlanoYColumna(Jugador* jugador){

	int numeroDePlano;
	int numeroDeColumna;
	bool hayGanador = false;

	do{
		std::cout<<"TURNO DEL JUGADOR N°: "<<jugador->getFicha()->verNumeroDeJugador()<<std::endl;
		//this->juego->mostrarCartasDeJugador(jugador);
		std::cout<<"Ingrese numero de plano: "<<std::endl;
		std::cin>>numeroDePlano;
		std::cout<<"Ingrese numero de columna: "<<std::endl;
		std::cin>>numeroDeColumna;
	}while(this->juego->getTablero()->getTableo()->obtener(numeroDePlano)->obtener(1)->obtener(numeroDeColumna)->verFicha()->verNumeroDeJugador()!=0);

	hayGanador = this->juego->getTablero()->jugarFicha(numeroDePlano, numeroDeColumna, jugador->getFicha()->verNumeroDeJugador());
	this->juego->getTablero()->verTablero();

	return hayGanador;
}

Menu::~Menu(){
	delete this->juego;
}
