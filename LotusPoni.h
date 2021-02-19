#ifndef LOTUSPONI_H
#define LOTUSPONI_H

#include "Vehiculo.h"


class LotusPoni : public Vehiculo {
public:
	LotusPoni();
	~LotusPoni();
	
	void actualizar();
	void armarAuto();
	void moverDerecha(){};
	void moverIzquierda(){};
	void moverDiagonalDerecha(){};
	void moverDiagonalIzquierda(){};
	void mover();
	void chocar();
	
private:
	void reiniciarLotus();
	
};

#endif

