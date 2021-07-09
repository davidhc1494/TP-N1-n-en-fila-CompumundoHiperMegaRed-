/*
 * Carta.h
 *
 *  Created on: 4 jul. 2021
 *      Author: claudio
 */

#ifndef CARTA_H_
#define CARTA_H_
#include <string>
enum TipoDeCarta{
	CartaBloquearTurno,
	CartaJugadaDoble,
	CartaNoLevantaCarta,
	CartaDescartarTodaLaMano
};

class Carta {
private:
	TipoDeCarta tipoDeCarta;
	std::string nombreDeTipoDeCarta;

public:



	/*
	 * Post: crea una instancia de carta segun el tipo de carta que se le pasa.
	 */
	Carta(TipoDeCarta tipoDeCarta);

	//PRE: tiene que existir carta
	//POS: devuelve el nombre de la carta
	std::string getNombreDeTipoDeCarta();

	/*
	 * Post: devuelve el tipo de carta.
	 */
	TipoDeCarta obtenerTipoDeCarta();
};



#endif /* CARTA_H_ */
