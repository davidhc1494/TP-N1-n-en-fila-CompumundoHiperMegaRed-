/*
 * Juego.cpp
 *
 *  Created on: 5 jul. 2021
 *      Author: claudio
 */

#include <iostream>
#include "Jugador.h"
using namespace std;

int main() {

	Mazo* mazo = new Mazo();
	for (int i = 0;i < mazo->obtenerCantidadDeCartas()/4;i++){
		Carta* carta1 = new Carta(CartaBloquearTurno);
		mazo->agregarCartas(carta1);
		Carta* carta2 = new Carta(CartaJugadaDoble);
		mazo->agregarCartas(carta2);
		Carta* carta3 = new Carta(CartaPierdeElTurno);
		mazo->agregarCartas(carta3);
		Carta* carta4 = new Carta(CartaNoLevantaCarta);
		mazo->agregarCartas(carta4);

	}

	cout << mazo->obtenerCantidadDeCartas();
	cout << mazo->obtenerFrente()->obtenerTipoDeCarta();
	Jugador* jugador1 = new Jugador(1);
	jugador1->guardarCarta(mazo->sacarCarta());
	cout << jugador1->obtenerCartas()->obtener(0)->obtenerTipoDeCarta();
	jugador1->guardarCarta(mazo->sacarCarta());
	jugador1->guardarCarta(mazo->sacarCarta());
	jugador1->guardarCarta(mazo->sacarCarta());
	jugador1->guardarCarta(mazo->sacarCarta());
	//cout << mazo->obtenerFrente()->obtenerTipoDeCarta();
	//ver este despues de la ultima carta devuelve cuaquiera
	TipoDeCarta tipoDecarta = jugador1->obtenerCartas()->obtener(1)->obtenerTipoDeCarta();
	switch (tipoDecarta) {
		case CartaBloquearTurno:
			cout<<"CartaBloquearTurno";
			break;
		case CartaJugadaDoble:
			cout<<"CartaJugadaDoble";
			break;
		default:
			break;
	}
	Carta* carta = jugador1->canjearCarta(1);
	TipoDeCarta tipoDecarta2 = carta->obtenerTipoDeCarta();
	switch (tipoDecarta2) {
			case CartaBloquearTurno:
				cout<<"CartaBloquearTurno";
				break;
			case CartaJugadaDoble:
				cout<<"CartaJugadaDoble";
				break;
			default:
				break;
		}
	mazo->agregarCartas(carta);

	return 0;
}


