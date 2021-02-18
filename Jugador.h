#ifndef JUGADOR_H
#define JUGADOR_H

#include "Vehiculo.h"

class Jugador : public Vehiculo{
public:
	Jugador();
	~Jugador();
	
	void actualizar();
	void moverIzquierda();
	void moverDerecha();
	
	
private:
};

#endif

