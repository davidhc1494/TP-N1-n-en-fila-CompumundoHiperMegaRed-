/*
 * Casillero.cpp
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */
#include "Casillero.h"

Casillero::Casillero(){

	this->ficha = new Ficha(0);

}

Ficha* Casillero::verFicha(){
	return this->ficha;
}



