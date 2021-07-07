/*
 * Carta.h
 *
 *  Created on: 4 jul. 2021
 *      Author: claudio
 */

#ifndef CARTA_H_
#define CARTA_H_

enum TipoDeCarta{
	CartaBloquearTurno,
	CartaJugadaDoble
};

class Carta {
private:
	TipoDeCarta tipoDeCarta;

public:



	/*
	 * Post: crea una instancia de carta segun el tipo de carta que se le pasa.
	 */
	Carta(TipoDeCarta tipoDeCarta);

	/*
	 * Post: devuelve el tipo de carta.
	 */
	TipoDeCarta obtenerTipoDeCarta();
};



#endif /* CARTA_H_ */
