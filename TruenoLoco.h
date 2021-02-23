#ifndef TRUENOLOCO_H
#define TRUENOLOCO_H
//incluimos el encabezado de la clase base
#include "Vehiculo.h"

/**
* es la clase del enemigo TruenoLoco Auto Rojo que se mueve en diagonal
---------------------------------------------------------------------------------------------
* Esta CLASE se deriva de Vehiculos y hereda sus metodos y atributos para armar un Vehiculo
* esta clase redefine los metodos virtuales de VEHICULO y  define  eimplementa metodos y atributos propios 
* para el movimiento en diagonal, la cuenta de vueltas y la aceleracion de este enemigo
*/
class TruenoLoco :public Vehiculo {
public:
	TruenoLoco();
	~TruenoLoco(){};

	//metodos que se heredan de vehiculo para definir en esta clase sus comportamientos
	void actualizar();
	void mover();
	void chocar();
	int getVueltas();
	void acelerar();
	void reset();
		
private:
	//atributos propios de esta clase
	int direccion;
	//contadores para las vueltas , se usan para controlar que se acelere solo una vez, mientra se espera a la siguiente vuelta
	int contadorVueltas;
	int contadorInicial;
	
	//metodos propios de esta clase
	void reLanzarTrueno();
	void moverDiagonalDerecha();
	void moverDiagonalIzquierda();
	
	//metodos heredados de vehiculo como protected y redefinidos aqui 
	void armarAuto();
	

};

#endif

