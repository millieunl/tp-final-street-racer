#ifndef LOTUSPONI_H
#define LOTUSPONI_H

#include "Vehiculo.h"


class LotusPoni : public Vehiculo {
public:
	LotusPoni();
	~LotusPoni();
	
	void actualizar();
	
	void moverDerecha(){};
	void moverIzquierda(){};
	void moverDiagonalDerecha(){};
	void moverDiagonalIzquierda(){};
	void mover();
	void chocar();
	int getVueltas();
	void acelerar();


private:
	void reiniciarLotus();
	void armarAuto();
	
	
	int contadorVueltas;
	int contadorAceleraciones;
	
	
	
};

#endif

