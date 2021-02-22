#ifndef VEHICULO_H
#define VEHICULO_H

#include<iostream>
#include <ctime>
//clase madre que sirve de "molde" para el auto del jugador, y de los enemigos

class Vehiculo {
public:
	//constructor y destructor de la clase
	Vehiculo();
	~Vehiculo();
	
	//metodos  virtuales que se van a definir en las clases derivadas
	virtual void actualizar() = 0 ;
	virtual void moverDerecha()= 0;
	virtual void moverIzquierda()= 0;
	virtual void moverDiagonalDerecha() = 0;
	virtual void moverDiagonalIzquierda() = 0;
	virtual void mover() = 0;
	virtual void chocar() = 0;
	virtual int getVueltas() = 0;
	virtual void acelerar() = 0;
	virtual void reset() = 0;
	
	
	//metodos que se implementan en esta misma clase y se heredan directamente(herencia simple) en las derivadas
	void setLimite(int x0, int x1, int y0, int y1);
	void setPosicion(int x, int y);
	
	int getAncho();
	int getAlto();
	int getX();
	int getY();
	int getVidas();
	
	

protected:
	//atributos 
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

