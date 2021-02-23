#ifndef VEHICULO_H
#define VEHICULO_H


//incluimos librerias necesarias
//libreria para entrada/salida  estandar y poder usar std::cout
#include<iostream>
//libreria para usar clock() y obtener el tiempo
#include <ctime>

/**
*  CLASE  que sirve hacer clases derivadas para crear el auto del jugador 
*  y de los enemigos LotusPoni y TruenoLoco
*  contiene los atributos comunes a jugador y los enemigos.
*  metodos virtuales
*/

class Vehiculo {
public:
	//constructor y destructor 
	Vehiculo();
	virtual ~Vehiculo(){};
	
	//metodos  virtuales que se van a definir en las clases derivadas
	virtual void actualizar() = 0 ;
	virtual void mover() = 0;
	virtual void chocar() = 0;
	virtual void acelerar() = 0;
	virtual void reset() = 0;
	
	//getter cirtual
	virtual int getVueltas() = 0;
	
	//metodos que se implementan en esta misma clase y se heredan directamente(herencia simple) en las derivadas
	//getter y setter
	void setPosicion(int x, int y);
	int getAncho();
	int getAlto();
	int getX();
	int getY();
	int getVidas();
	
	
protected:
	//atributos comunes a todos los vehiculos
	int x;
	int y;
	int matriz[3][5];
	int color[3][5];
	int ancho;  		//ancho del auto coincide con cantidad de columnas de la matriz
	int alto;   		//alto del auto coinicde con cantidad de filas de la matriz
	int maxLimiteX;
	int maxLimiteY;
	int minLimiteX;
	int minLimiteY;
	int velocidad;  //un entero que sirve para calcular la velocidad y el tiempo
	int vidas;

	//variables tipo clock
	clock_t tempo;
	clock_t paso;
	
	//metodos virtuales que se definen en las derivadas
	virtual void armarAuto() = 0;
	
	//metodos protected para herencia simple
	void dibujar();
	void borrar();
	
};

#endif

