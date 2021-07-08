/*
 * Casillero.h
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "Ficha.h"
#include "Lista.h"
#include "Casillero.h"
#include <string>

class CasilleroAdyacente;

class Casillero{

private:

	Ficha *ficha;
	Lista<CasilleroAdyacente*>* listaDeCasilleroAdyacentes;

public:

	//PRE:-
	//POS: se crea un nuevo casillero con el numero de identificacion del jugador dueño de la ficha como 0
	Casillero();

	//PRE:tiene que haber creado un casillero
	//POS:devuelve un puntero a la ficha que esta en el casillero
	Ficha* verFicha();

	Lista<CasilleroAdyacente*>* getListaDeCasilleroAdyacentes();

	void agregarCasilleroAdyacente(Casillero* casillero, std::string coordenada);

	void verCasilleroAdyacentes();
	
	//PRE:-
	//POST: Destruye el casillero, liberando la memoria dinámica utilizada.-
	~Casillero();

};


/*----------------------------------------------------------------*/

class CasilleroAdyacente{
private:

	std::string coordenada;
	Casillero* casilleroAdyacente;

public:

CasilleroAdyacente(std::string coordenada, Casillero* casillero);

std::string getCoordenada();

void setCoordenada(std::string coordenada);

Casillero* getCasillero();

void setCasilleroAdyacente(Casillero* casillero);

//PRE: -
//POST: -
~CasilleroAdyacente();

};


#endif /* CASILLERO_H_ */
