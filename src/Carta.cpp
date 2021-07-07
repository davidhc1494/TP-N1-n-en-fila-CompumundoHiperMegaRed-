/*
 * Carta.cpp
 *
 *  Created on: 5 jul. 2021
 *      Author: claudio
 */

#include "Carta.h"

Carta::Carta(TipoDeCarta tipoDeCarta){
	this->tipoDeCarta = tipoDeCarta;
}

TipoDeCarta Carta::obtenerTipoDeCarta(){
	return this->tipoDeCarta;
}


