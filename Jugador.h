#ifndef JUGADOR_H
#define JUGADOR_H

#include "Vehiculo.h"
#include "Temporizador.h"

class Jugador : public Vehiculo{
public:
	Jugador();
	~Jugador();
	
	void actualizar();
	void mover(){};
	void armarAuto();
	void moverIzquierda();
	void moverDerecha();
    void moverDiagonalDerecha(){};
	void moverDiagonalIzquierda(){};
	void chocar();
	
	
private:
	void colorearAuto();
	void parpadear();
	bool estaParpadeando;
	Temporizador *temporizador;
};

#endif

