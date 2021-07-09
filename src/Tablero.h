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
	int valorDeNEnFila;

public:

	//PRE:-
	//POS:se crea un tablero
	Tablero();

	//PRE:tiene que existir el tablero
	//POS: cambia el valos de N en fila
	void setValorDeNEnFila(int nuevoValor);

	//PRE: tiene que existir el tablero
	//POS: devuelve el valos de N en fila
	int getValorDeNEnFila();

	//PRE:tiene que existir el tablero
	//POS:se inicializa un tablero con todos los casillero en caon fichas con numero de jucador igual a 0(cero)
	void inicializarTablero(int x,int y,int z);

	//PRE:tiene que existir el tablero
	//POS: devuelve el tamanio del tablero
	int getTamanio();

	//PRE: tiene que existir el tablero
	//POS: cambia el tamaño del tablero
	void setTamanio(int tamanio);

	//PRE:tiene que existir un jugador
	//POS:mustra el tablero por consola. Se muestra por planos
	void verTablero();

	//PRE:tiene que existir el tablero
	//POS: se juega una ficha y dependiendos si gana se devuelde un bool
	bool jugarFicha(int numeroDePlano,int numeroDeColumna,int numeroDeJugador, char tipoDeFicha);

	//PRE:tiene que existir el tablero
	//POS: devuelde el tablero
	Lista<Lista<Lista<Casillero*>*>*>* getTableo();

	//PRE:tiene que existir el tablero
	//POS: agrega todos los casillero adyacentes a la lista de cada casillero
	void vincularConCasilleroAdyacentes();

	//PRE:tiene que existir el tablero
	//POS: define si la ficha jugada gano en columna
	bool revisarEnZ(Casillero* casillero);

	//PRE:tiene que existir el tablero
	//POS: define si la ficha jugada gano
	bool revisarLinea(Casillero* casillero,std::string coordenada1,std::string coordenada2);
	
	/*
	 * PRE: -
	 * POST: Destruye el tablero, liberando la memoria utilizada.-
	 */
	~Tablero();


};


#endif /* TAABLERO_CPP_ */
