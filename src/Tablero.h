/*
 * Taablero.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */

#ifndef TAABLERO_H_
#define TAABLERO_H_

#include "Lista.h"
#include "Casillero.h"
#include "Ficha.h"
#include <iostream>

class Tablero{
private:

	Lista<Lista<Lista<Casillero*>*>*>* tablero;
	int tamanio;

public:

	//PRE:-
	//POS:se crea un tablero
	Tablero();

	//PRE:tiene que existir el tablero
	//POS:se inicializa un tablero con todos los casillero en caon fichas con numero de jucador igual a 0(cero)
	void inicializarTablero(int x,int y,int z);

	int getTamanio();

	void setTamanio(int tamanio);

	//PRE:tiene que existir un jugador
	//POS:mustra el tablero por consola. Se muestra por planos
	void verTablero();

	bool jugarFicha(int numeroDePlano,int numeroDeColumna,int numeroDeJugador);

	Lista<Lista<Lista<Casillero*>*>*>* getTableo();

	void vincularConCasilleroAdyacentes();

	bool revisarEnZ(Casillero* casillero);

	bool revisarLinea(Casillero* casillero,std::string coordenada1,std::string coordenada2);


};


#endif /* TAABLERO_CPP_ */
