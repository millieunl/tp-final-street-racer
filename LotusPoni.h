#ifndef LOTUSPONI_H
#define LOTUSPONI_H

//incluimos el encabezado de la clase base
#include "Vehiculo.h"

/**
* es la clase del enemigo LotusPoni Auto AMARILLO que se mueve en linea recta
---------------------------------------------------------------------------------------------
* Esta CLASE se deriva de Vehiculos y hereda sus metodos y atributos para armar un Vehiculo
* esta clase redefine los metodos virtuales de VEHICULO y  define  eimplementa metodos y atributos propios 
* para el movimiento , la cuenta de vueltas y la aceleracion de este enemigo
*/
class LotusPoni : public Vehiculo {
public:
	//contructor y destructor
	LotusPoni();
	~LotusPoni(){};
	
	//metodos que se heredan de vehiculo para definir en esta clase sus comportamientos
	void actualizar();
	void mover();
	void chocar();
	int getVueltas();
	void acelerar();
	void reset();
	
protected:
	//atributos propios de la clase
	int contadorVueltas;
	int contadorInicial;
	
	//metodos propios de esta clase
	void reLanzar();
	
	//metodos heredados de vehiculo como protected y redefinidos aqui 
	void armarAuto();
	
};

#endif

