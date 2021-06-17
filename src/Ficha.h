/*
 * Ficha.h
 *
 *  Created on: 17 jun. 2021
 *      Author: David
 */

#ifndef FICHA_H_
#define FICHA_H_

class Ficha{

private:

	int numeroDeJugador;

public:

	//PRE: recibe el numnero que identifica al jugador como parametro
	//POS: se crea una ficha con el numero que identifica al jugador
	Ficha(int numeroDeJugador);

	//PRE:tiene que haber un objeto ficha creado
	//POS:muestra el numero del jugadro al que le pertenece la ficha
	int verNumeroDeJugador();

	//PRE:tiene que haber un objeto ficha creado, y se recibe por parametro el nuevo numero de identificacion
	//POS:cambia el numero de identificaion del juagador al que le pertenece la ficha
	void cambiarNumeroDeFicha(int nuevoNumeroDeJugador);


};



#endif /* FICHA_H_ */
