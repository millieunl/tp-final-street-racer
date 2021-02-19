#ifndef TRUENOLOCO_H
#define TRUENOLOCO_H

#include "Vehiculo.h"
class TruenoLoco :public Vehiculo {
public:
	TruenoLoco();
	~TruenoLoco();

	void actualizar();
	
	
private:
	//atributos
	int direccion;
	
	//metodos
	void moverDiagonalDerecha();
	void moverDiagonalIzquierda();
	void mover();
	
	
};

#endif

