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
	bool tomarCarta = true;
	bool descartarMano = false;

	this->ingresarValorNEnFila();
	this->ingresarTamanioDeTablero();
	this->ingresarCantidadDeJugadoresAJugar();

	std::cout<<""<<std::endl;
	std::cout<<"      INICIA EL JUEGO      "<<std::endl;
	std::cout<<""<<std::endl;
	this->juego->getTablero()->verTablero();

	this->juego->getListaDeJugadores()->iniciarCursor();

	while(hayGanador ==false){
		while(this->juego->getListaDeJugadores()->avanzarCursor() && hayGanador == false){

			std::cout<<"TURNO DEL JUGADOR N°: "<<this->juego->getListaDeJugadores()->obtenerCursor()->getFicha()->verNumeroDeJugador()<<std::endl;
			if(descartarMano == true){
				std::cout<<"SE DESCARTO TODA TU MANO, TOMAS UNA CARTA"<<std::endl;
				this->juego->descartarManoDeJugador(this->juego->getListaDeJugadores()->obtenerCursor());
				descartarMano = false;
			}

			if(tomarCarta == true){
				this->juego->tomarCarta(this->juego->getListaDeJugadores()->obtenerCursor());
			}else{
				std::cout<<"NO PUEDE LEVANTAR CARTAS ESTE TURNO"<<std::endl;
				tomarCarta = true;
			}

			this->juego->mostrarCartasDeJugador(this->juego->getListaDeJugadores()->obtenerCursor());

			int numeroDeCarta = 0;

			if(this->elegirSiJugarUnaCarta() == true){
				std::cout<<"Ingrese el numero de carta : ";
				std::cin>>numeroDeCarta;
				if(this->juego->getListaDeJugadores()->obtenerCursor()->obtenerCartas()->obtener(numeroDeCarta)->obtenerTipoDeCarta() == CartaJugadaDoble){
					this->juego->getListaDeJugadores()->obtenerCursor()->obtenerCartas()->remover(numeroDeCarta);
					hayGanador = this->ingresarPlanoYColumna(this->juego->getListaDeJugadores()->obtenerCursor());
					std::cout<<"JUEGA DE NUEVO LE JUGADOR N°:  "<<this->juego->getListaDeJugadores()->obtenerCursor()->getFicha()->verNumeroDeJugador()<<std::endl;
					hayGanador = this->ingresarPlanoYColumna(this->juego->getListaDeJugadores()->obtenerCursor());

				}else if(this->juego->getListaDeJugadores()->obtenerCursor()->obtenerCartas()->obtener(numeroDeCarta)->obtenerTipoDeCarta() == CartaBloquearTurno){
					this->juego->getListaDeJugadores()->obtenerCursor()->obtenerCartas()->remover(numeroDeCarta);
					std::cout<<"EL SIGUIENTE JUGADOR PIERDE SU TURNO, CONTINUA SU JUEGO EL JUGADOR NUMERO: "<<this->juego->getListaDeJugadores()->obtenerCursor()->getFicha()->verNumeroDeJugador()<<std::endl;
					hayGanador = this->ingresarPlanoYColumna(this->juego->getListaDeJugadores()->obtenerCursor());
					this->juego->getListaDeJugadores()->avanzarCursor();
					this->juego->getListaDeJugadores()->avanzarCursor();

				}else if(this->juego->getListaDeJugadores()->obtenerCursor()->obtenerCartas()->obtener(numeroDeCarta)->obtenerTipoDeCarta() == CartaNoLevantaCarta){
					this->juego->getListaDeJugadores()->obtenerCursor()->obtenerCartas()->remover(numeroDeCarta);
					std::cout<<"EL SIGUIENTE JUGADOR NO PUEDE LEVANTAR CARTA DEL MAZO, CONTINUA SU JUEGO EL JUGADOR NUMERO: "<<this->juego->getListaDeJugadores()->obtenerCursor()->getFicha()->verNumeroDeJugador()<<std::endl;
					hayGanador = this->ingresarPlanoYColumna(this->juego->getListaDeJugadores()->obtenerCursor());
					tomarCarta = false;
				}else if(this->juego->getListaDeJugadores()->obtenerCursor()->obtenerCartas()->obtener(numeroDeCarta)->obtenerTipoDeCarta() == CartaDescartarTodaLaMano){

					std::cout<<"EL SIGUIENTE JUGADOR DESCARTA TODA SU MANO Y TOMA LA CARTA CORRESPONDIENTE A SU TURNO, CONTINUA SU JUEGO EL JUGADOR NUMERO: "<<this->juego->getListaDeJugadores()->obtenerCursor()->getFicha()->verNumeroDeJugador()<<std::endl;
					hayGanador = this->ingresarPlanoYColumna(this->juego->getListaDeJugadores()->obtenerCursor());
					descartarMano = true;
				}

			}else{
				hayGanador = this->ingresarPlanoYColumna(this->juego->getListaDeJugadores()->obtenerCursor());
			}

		}
		this->juego->getListaDeJugadores()->iniciarCursor();
	}

}

void Menu::ingresarTamanioDeTablero(){
	int tamanio = 0;

	do{
		std::cout<<"Ingrese el tamanio del tablero(tiene que ser mayor al valor N en linea): ";
		std::cin>>tamanio;
		if(tamanio<=0){
			std::cout<<"TAMANIO INGRESADO MENOR O IGUAL A 0(cero)"<<std::endl;
		}
	}while(tamanio<this->juego->getTablero()->getValorDeNEnFila());
	juego->getTablero()->setTamanio(tamanio);
	juego->getTablero()->inicializarTablero(tamanio, tamanio, tamanio);
}

void Menu::ingresarCantidadDeJugadoresAJugar(){
	int numeroDeNuevoJugador = 0;

	do{
		std::cout<<"Ingrese la cantidad de jugadores que van a jugar(minimo 2 jugadores): ";
		std::cin>>numeroDeNuevoJugador;
	}while(numeroDeNuevoJugador < 2);

	for(int i = 1;i<=numeroDeNuevoJugador;i++){
		this->juego->agregarJugador(i);
	}
	//this->juego->iniciarManoDeJuGadores();
}

bool Menu::ingresarPlanoYColumna(Jugador* jugador){

	int numeroDePlano;
	int numeroDeColumna;
	bool hayGanador = false;

	do{
		//std::cout<<"TURNO DEL JUGADOR N°: "<<jugador->getFicha()->verNumeroDeJugador()<<std::endl;
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

bool Menu::elegirSiJugarUnaCarta(){

	bool jugarCarta= false;
	std::string opcion = "";
	do{

		std::cout<<" ¿Quiere jugar una carta? "<<std::endl;
		std::cout<<"1 - Si"<<std::endl;
		std::cout<<"2 - No"<<std::endl;
		std::cin>>opcion;
	}while(opcion != "1" && opcion != "2");

	if(opcion == "1"){
		jugarCarta = true;
	}

	return jugarCarta;
}

void Menu::ingresarValorNEnFila(){

	int valorNEnFila = 0;

	do{
		std::cout<<"Ingrese el valor de N en fila(tiene que ser mayor o igual a 3): "<<std::endl;
		std::cin>>valorNEnFila;
	}while(valorNEnFila < 3);

	this->juego->getTablero()->setValorDeNEnFila(valorNEnFila);
}

Menu::~Menu(){
	delete this->juego;
}

