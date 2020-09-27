#ifndef AUTO_H
#define AUTO_H

#include<iostream>
#include <ctime>

class Auto {
public:
	Auto();
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
	void dibujar();
	void actualizar();
	void eventos();
	void borrar();
	void moverIzquierda();
	void moverDerecha();
	void setLimite(int x0, int x1, int y0, int y1);
	
	clock_t tempo;
	clock_t paso;
	
	//borrar
	unsigned long int fps = 1;
	int fps2 = 0;
	clock_t tempo2 = clock();
	clock_t paso2 = CLOCKS_PER_SEC/5000;
	~Auto();
private:
	
	
};

#endif

