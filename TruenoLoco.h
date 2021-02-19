#ifndef TRUENOLOCO_H
#define TRUENOLOCO_H

#include "Vehiculo.h"

class TruenoLoco :public Vehiculo {
public:
	TruenoLoco();
	~TruenoLoco();

	void actualizar();
	//metodos
	void armarAuto();
	void moverDerecha(){};
	void moverIzquierda(){};
	void moverDiagonalDerecha();
	void moverDiagonalIzquierda();
	void mover();
	void chocar();
	
private:
	//atributos
	int direccion;
	void reiniciarTrueno();
	
	
	
	
};

#endif

