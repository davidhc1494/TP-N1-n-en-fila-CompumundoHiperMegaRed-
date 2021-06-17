/*
 * Casillero.h
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "Ficha.h"

class Casillero{

private:

	Ficha *ficha;

public:

	//PRE:-
	//POS: se crea un nuevo casillero con el numero de identificacion del jugador dueño de la ficha como 0
	Casillero();

	//PRE:tiene que haber creado un casillero
	//POS:devuelve un puntero a la ficha que esta en el casillero
	Ficha* verFicha();

};




#endif /* CASILLERO_H_ */
