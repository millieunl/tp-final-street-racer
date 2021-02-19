#ifndef VEHICULO_H
#define VEHICULO_H

#include<iostream>
#include <ctime>
//clase madre que sirve de "molde" para el auto del jugador, y de los enemigos

class Vehiculo {
public:
	//constructor
	Vehiculo();
	
	//atributos publicos que hacen a las caracteristicas de un auto
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
	
	//metodos 
	void dibujar();
	virtual void actualizar() = 0 ;
	void borrar();
	void setLimite(int x0, int x1, int y0, int y1);
	void setPosicion(int x, int y);
	int getAncho();
	int getAlto();
	
	//variables tipo clock
	clock_t tempo;
	clock_t paso;
	
	//destructor de clase
	~Vehiculo();
	
private:
};

#endif

