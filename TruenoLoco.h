#ifndef TRUENOLOCO_H
#define TRUENOLOCO_H

#include "Vehiculo.h"
class TruenoLoco :public Vehiculo {
public:
	TruenoLoco();
	~TruenoLoco();
	
	int direccion = rand()%1;
	void actualizar();
	void moverDiagonalDerecha();
	void moverDiagonalIzquierda();
	void mover();
	
private:
};

#endif

