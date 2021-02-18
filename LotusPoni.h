#ifndef LOTUSPONI_H
#define LOTUSPONI_H

#include "Vehiculo.h"


class LotusPoni : public Vehiculo {
public:
	LotusPoni();
	~LotusPoni();
	
	int posX;
	int posY;
	void actualizar();
	void mover();
	
private:
};

#endif

