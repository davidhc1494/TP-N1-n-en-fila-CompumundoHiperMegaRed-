/*
 * Mazo.h
 *
 *  Created on: 5 jul. 2021
 *      Author: claudio
 */

#ifndef MAZO_H_
#define MAZO_H_
#include "Carta.h"
#include "Cola.h"

class Mazo {
private:
	Cola<Carta*>* cartas;
	int cantidadDeCartas;

public:
	/*
	 * Pre:
	 * Post: crea un mazo de cartas con una cantidad de cartas por defecto(40).
	 */
	Mazo();

	/*
	 * Pre:
	 * Post: crea el mazo con una cantidad de cartas que se pasan por parametro.
	 */

	void inicializarMazo();

	Mazo(int cantidadDeCartas);

	/*
	 * Pre:
	 * Post: devulve la cantidad de cartas del mazo.
	 */
	int obtenerCantidadDeCartas();

	/*
	 * Post: agrega una carta al mazo.
	 */
	void agregarCartas(Carta* carta);

	/*
	 * Post: devuelve el tope del mazo.
	 */
	Carta* obtenerFrente();

	/*
	 * Post: saca una carta del tope del mazo.
	 */
	Carta* sacarCarta();
	
	~Mazo();


};


#endif /* MAZO_H_ */
