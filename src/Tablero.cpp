/*
 * Tablero.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */
#include"Tablero.h"

Tablero::Tablero(){

	this->tablero = new Lista<Lista<Lista<Casillero*>*>*>();
	this->tamanio = 0;

}

int Tablero::getTamanio(){
	return this->tamanio;
}

void Tablero::setTamanio(int tamanio){
	this->tamanio = tamanio;
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
	this->vincularConCasilleroAdyacentes();

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

bool Tablero::jugarFicha(int numeroDePlano,int numeroDeColumna,int numeroDeJugador){

	bool fichaJugada = false;
	bool gano = false;
	int contadorDeFilas = this->getTamanio();


	while(contadorDeFilas>0 && fichaJugada == false && gano == false){

		if(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna)->verFicha()->verNumeroDeJugador() == 0 ){

			this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna)->verFicha()->cambiarNumeroDeFicha(numeroDeJugador);

			//std::cout<<""<<std::endl;
			if(this->revisarEnZ(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna))){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "x+", "x-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "y+", "y-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "a+", "a-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "b+", "b-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "c+", "c-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "e+", "e-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "f+", "f-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "g+", "g-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "h+", "h-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "i+", "i-")){
				gano = true;
			}else if(this->revisarLinea(this->tablero->obtener(numeroDePlano)->obtener(contadorDeFilas)->obtener(numeroDeColumna), "j+", "j-")){
				gano = true;
			}

			fichaJugada = true;
		}

		contadorDeFilas--;

	}
	return gano;
}

bool Tablero::revisarEnZ(Casillero* casillero){
	int valorDeN = 3;
	int contadorDeFichasIguales = 1;
	bool gano = false;
	Casillero* nuevoCasillero = casillero;
	//nuevoCasillero->verCasilleroAdyacentes();


	nuevoCasillero->getListaDeCasilleroAdyacentes()->iniciarCursor();
	while(nuevoCasillero->getListaDeCasilleroAdyacentes()->avanzarCursor() && (contadorDeFichasIguales <= valorDeN)){
		if(nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCoordenada()=="z" &&
				nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCasillero()->verFicha()->verNumeroDeJugador() == casillero->verFicha()->verNumeroDeJugador()){
			//std::cout<<"existe"<<std::endl;
			contadorDeFichasIguales = contadorDeFichasIguales+1;
			nuevoCasillero = nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCasillero();
			nuevoCasillero->getListaDeCasilleroAdyacentes()->iniciarCursor();
		}
	}

	if(contadorDeFichasIguales == valorDeN){
		gano = true;
		std::cout<<"Gano el jugador Numero: "<<casillero->verFicha()->verNumeroDeJugador()<<" contador: "<<contadorDeFichasIguales<<std::endl;
	}
	return gano;
}

bool Tablero::revisarLinea(Casillero* casillero,std::string coordenada1,std::string coordenada2){
	int valorDeN = 3;
	int contadorDeFichasIguales = 1;
	bool gano = false;
	Casillero* nuevoCasillero = casillero;

	//nuevoCasillero->verCasilleroAdyacentes();

	nuevoCasillero->getListaDeCasilleroAdyacentes()->iniciarCursor();
	while(nuevoCasillero->getListaDeCasilleroAdyacentes()->avanzarCursor() && (contadorDeFichasIguales <= valorDeN)){
		if(nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCoordenada() == coordenada2 &&
				nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCasillero()->verFicha()->verNumeroDeJugador() == casillero->verFicha()->verNumeroDeJugador()){
			//std::cout<<"existe"<<std::endl;
			contadorDeFichasIguales = contadorDeFichasIguales+1;
			nuevoCasillero = nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCasillero();
			nuevoCasillero->getListaDeCasilleroAdyacentes()->iniciarCursor();
		}
	}

	while(nuevoCasillero->getListaDeCasilleroAdyacentes()->avanzarCursor() && (contadorDeFichasIguales <= valorDeN)){
		if(nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCoordenada()==coordenada2 &&
				nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCasillero()->verFicha()->verNumeroDeJugador() == casillero->verFicha()->verNumeroDeJugador()){
			//std::cout<<"existe"<<std::endl;
			contadorDeFichasIguales = contadorDeFichasIguales+1;
			nuevoCasillero = nuevoCasillero->getListaDeCasilleroAdyacentes()->obtenerCursor()->getCasillero();
			nuevoCasillero->getListaDeCasilleroAdyacentes()->iniciarCursor();
		}
	}

	if(contadorDeFichasIguales == valorDeN){
		gano = true;
		std::cout<<"Gano el jugador Numero: "<<casillero->verFicha()->verNumeroDeJugador()<<" contador: "<<contadorDeFichasIguales<<std::endl;
	}

	return gano;
}

Lista<Lista<Lista<Casillero*>*>*>* Tablero::getTableo(){
		return this->tablero;
}

void Tablero::vincularConCasilleroAdyacentes(){

	int largoDeListaDeCasilleros= this->tablero->obtener(1)->obtener(1)->contarElementos();
	int numeroDePlano;
	int	numeroDeColumna;
	int numeroDeCasillero;

	for(numeroDePlano = 1;numeroDePlano <= largoDeListaDeCasilleros;numeroDePlano++){
		for(numeroDeColumna = 1;numeroDeColumna <= largoDeListaDeCasilleros;numeroDeColumna++){
			for(numeroDeCasillero = 1;numeroDeCasillero <= largoDeListaDeCasilleros;numeroDeCasillero++){

				this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero+1), "y+");
				this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero-1), "y-");

				this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero), "z");// como le sumo 1 va a la fila de abajo
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna)->obtener(numeroDeCasillero), "x+");
				}
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna)->obtener(numeroDeCasillero), "x-");
				}

				//diagonal A
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero-1), "a+");
				}
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero+1), "a-");
				}

				//diagonal B
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero), "b+");
				}
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero), "b-");
				}

				//diagonal C
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero+1), "c+");
				}
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero-1), "c-");
				}

				//diagonal D
				this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero-1), "d+");
				this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero+1), "d-");

				//diagonal E
				this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero+1), "e+");
				this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero-1), "e-");

				//diagonal F
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero-1), "f+");
				}
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero+1), "f-");
				}

				//diagonal G
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero), "g+");
				}
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero), "g-");
				}

				//diagonal H
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna-1)->obtener(numeroDeCasillero+1), "h+");
				}
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna+1)->obtener(numeroDeCasillero-1), "h-");
				}

				//diagonal I
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna)->obtener(numeroDeCasillero-1), "i+");
				}
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna)->obtener(numeroDeCasillero+1), "i-");
				}

				//diagonal J
				if(numeroDePlano-1 != 0){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano-1)->obtener(numeroDeColumna)->obtener(numeroDeCasillero+1), "j+");
				}
				if(numeroDePlano+1 < largoDeListaDeCasilleros){
					this->tablero->obtener(numeroDePlano)->obtener(numeroDeColumna)->obtener(numeroDeCasillero)->agregarCasilleroAdyacente(this->tablero->obtener(numeroDePlano+1)->obtener(numeroDeColumna)->obtener(numeroDeCasillero-1), "j-");
				}

			}

		}

	}
	//primitiva para ver lista de adyacancia
	//this->tablero->obtener(3)->obtener(1)->obtener(1)->verCasilleroAdyacentes();
}

Tablero::~Tablero(){
	delete this->tablero;
}








