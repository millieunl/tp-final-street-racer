#include "Auto.h"
#include <conio2.h>
#include <ctime>

Auto::Auto() {
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	//cargar matriz con el dibujo del auto
	matriz [0][0] = '0';
	matriz [0][1] = '-';
	matriz [0][2] = '0';
	matriz [1][0] = ' ';
	matriz [1][1] = '|';
	matriz [1][2] = ' ';
	matriz [2][0] = '0';
	matriz [2][1] = '-';
	matriz [2][2] = '0';
	
	//carga la posicion en x,y
	x = 18;
	y = 18;
	
	//cargar valor para fila y columna de la matriz
	ancho = 3;
	alto = 3;
}

Auto::~Auto() {
	
}

void Auto::dibujar(){
	//for para dibujar la matriz que tiene el diseño del auto
	for(int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++){
			gotoxy(x+j,y+i);
			std::cout<<matriz[i][j];
		}
		std::cout<<std::endl;
	}
}

void Auto :: eventos(){
	if (kbhit()){
		int tecla = getch();
		switch(tecla) {
		case 67: 			//derecha
			if(x + ancho < maxLimiteX) { borrar(); x = x + ancho;}
			break;
		case 68: 			//izquierda
			if(x - ancho > minLimiteX) { borrar(); x = x-ancho;}
			break;
		}
	}
}

void Auto::actualizar() {
	
	if(tempo + paso < clock()) {
		eventos();
		dibujar();
		tempo = clock();
	}
}

void Auto::borrar() {
	for(int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			gotoxy(x+j,y+i);
			std::cout<<" ";
		}
	}
}

void Auto::setLimite(int x0, int x1, int y0, int y1){
	minLimiteX = x0;
	maxLimiteX = x1;
}
