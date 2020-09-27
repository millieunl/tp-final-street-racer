#include "Auto.h"
#include <conio2.h>


Auto::Auto() {
	
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	//cargar matriz con el dibujo del auto
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
	
	
	//carga la matriz con los colores
	color[0][0] = 0;  //rueda
	color[0][1] = 0;
	color[0][2] = 13;  //punta
	color[0][3] = 0;
	color[0][4] = 0;   //rueda
	color[1][0] = 0;
	color[1][1] = 13;   //costado izq
	color[1][2] = 5;   //cabina
	color[1][3] = 13;   //costado dere
	color[1][4] = 0;
	color[2][0] = 0;    //rueda
	color[2][1] = 0;
	color[2][2] = 13;    //cola
	color[2][3] = 0;
	color[2][4] = 0;    //rueda
	
	
	/*
	//despues borras esto para test AUTO BLANCO
	color[0][0] = 15;  //rueda
	color[0][1] = 15;
	color[0][2] = 15;  //punta
	color[0][3] = 15;
	color[0][4] = 15;   //rueda
	color[1][0] = 15;
	color[1][1] = 15;   //costado izq
	color[1][2] = 15;   //cabina
	color[1][3] = 15;   //costado dere
	color[1][4] = 15;
	color[2][0] = 15;    //rueda
	color[2][1] = 15;
	color[2][2] = 15;    //cola
	color[2][3] = 15;
	color[2][4] = 15;    //rueda
	*/
	//carga la posicion en x,y
	//x = 26 ;
	x = 31;
	y = 23;
	
	//cargar valor para fila y columna de la matriz
	ancho = 5;
	alto = 3;
	
}

Auto::~Auto() {
	
}

void Auto::dibujar(){
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
void Auto::moverDerecha() {
	if(x + ancho < maxLimiteX) { borrar(); x = x + ancho;}
}

void Auto::moverIzquierda() {
	//if(x+1 > minLimiteX) { borrar(); x = x - ancho;}
	if(x - ancho < minLimiteX) return;
	else{
		borrar(); 
		x = x-ancho;
	}
}


void Auto::actualizar() {
	
	if(tempo + paso < clock()) {
		//fps++;
		//gotoxy(31,26);		
		//std::cout<<fps;
		dibujar();
		tempo = clock();
	}
	
	
}

void Auto::borrar() {
	
	for(int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			textbackground(DARKGRAY);
			gotoxy(x+j,y+i);
			std::cout<<" ";
		}
	}
}

void Auto::setLimite(int x0, int x1, int y0, int y1){
	minLimiteX = x0;
	maxLimiteX = x1;
}
