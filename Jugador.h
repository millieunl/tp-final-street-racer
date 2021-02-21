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
	void moverIzquierda();
	void moverDerecha();
    void moverDiagonalDerecha(){};
	void moverDiagonalIzquierda(){};
	void chocar();
	int getVueltas(){};
	void acelerar(){};
	

	
	


private:
	//atributos y objetos de esta clase
	bool estaParpadeando;
	
	Temporizador *temporizador;
	
	//metodos propios de esta clase
	void colorearAuto();
	void parpadear();
	
	//metodos heredados
	void armarAuto();
	
};

#endif

