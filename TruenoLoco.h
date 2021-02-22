#ifndef TRUENOLOCO_H
#define TRUENOLOCO_H

#include "Vehiculo.h"

class TruenoLoco :public Vehiculo {
public:
	TruenoLoco();
	~TruenoLoco();

	//metodos que se heredan de vehiculos para definir en esta clase sus comportamientos
	void actualizar();
	void moverDiagonalDerecha();
	void moverDiagonalIzquierda();
	void mover();
	void chocar();
	int getVueltas();
	void acelerar();
	
	
	void moverDerecha(){};
	void moverIzquierda(){};
	void reset();

	
private:
	//atributos propios de esta clase
	int direccion;
	int contadorVueltas;
	int contadorInicial;
	
	//metodos propios de esta clase
	void reiniciarTrueno();
	
	
	//metodos heredados de vehiculo como protected y redefinidos aqui 
	void armarAuto();

	
	
	
	
	
	
	
	
	
	
	
};

#endif

