/*
 * Carta.cpp
 *
 *  Created on: 5 jul. 2021
 *      Author: claudio
 */

#include "Carta.h"

Carta::Carta(TipoDeCarta tipoDeCarta){
	this->tipoDeCarta = tipoDeCarta;

	if(tipoDeCarta == CartaBloquearTurno){
		this->nombreDeTipoDeCarta = "Bloquear turno";
	}else if(tipoDeCarta == CartaJugadaDoble){
		this->nombreDeTipoDeCarta = "Jugar doble";
	}else if(tipoDeCarta == CartaNoLevantaCarta){
		this->nombreDeTipoDeCarta = "No levantar carta";
	}else if(tipoDeCarta == CartaDescartarTodaLaMano){
		this->nombreDeTipoDeCarta = "El siguiente jugador descarta todas sus mano";
	}


}

TipoDeCarta Carta::obtenerTipoDeCarta(){
	return this->tipoDeCarta;
}

std::string Carta::getNombreDeTipoDeCarta(){
	return this->nombreDeTipoDeCarta;
}



