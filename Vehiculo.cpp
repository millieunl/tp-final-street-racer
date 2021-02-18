#include "Vehiculo.h"
#include <conio2.h>

Vehiculo::Vehiculo() {
	
	
	//cargar matriz con el dibujo del auto generico
	matriz[0][0] = 219;
	matriz[0][1] = 205;
	matriz[0][2] = 178;
	matriz[0][3] = 205;
	matriz[0][4] = 219;
	matriz[1][0] = ' ';
	matriz[1][1] = 47;
	matriz[1][2] = 219;
	matriz[1][3] = 92;
	matriz[1][4] = ' ';
	matriz[2][0] = 219;
	matriz[2][1] = 205;
	matriz[2][2] = 178;
	matriz[2][3] = 205;
	matriz[2][4] = 219;
	
	//guardamos el ancho y alto de la matriz
	ancho = 5; 
	alto = 3; 
	
	maxLimiteX = 85;
	minLimiteX = 31;
	maxLimiteY = 45;
	minLimiteY = 1;
}

void Vehiculo::dibujar(){
	//for para dibujar la matriz que tiene el diseño del auto
	for(int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++){
			textbackground(DARKGRAY);
			textcolor(color[i][j]);
			gotoxy(x+j,y+i);
			std::cout<<char(matriz[i][j]);
		}
		std::cout<<std::endl;
	}
}

void Vehiculo::borrar(){
	for(int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			textbackground(DARKGRAY);
			gotoxy(x+j,y+i);
			std::cout<<" ";
		}
	}
}

void Vehiculo::setLimite(int x0, int x1, int y0, int y1){
	minLimiteX = x0;
	maxLimiteX = x1;
}


void Vehiculo::setPosicion(int x, int y){
	this -> x = x;
	this -> y = y;
}
Vehiculo::~Vehiculo() {
	
}

