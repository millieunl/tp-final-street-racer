#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "LotusPoni.h"
#include "Temporizador.h"

class Obstaculo :  public LotusPoni {
public:
	Obstaculo();
	~Obstaculo();

	
	
	void actualizar();
	void chocar();
	
	
	
private:
	Temporizador *temporizador;
	void mover();
	
};

#endif

