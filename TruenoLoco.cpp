#include "TruenoLoco.h"
#include <conio2.h>


TruenoLoco::TruenoLoco() {	
	//dibujo del auto Trueno Loco
	armarAuto();
	reset();	
}



void TruenoLoco::acelerar(){
	if(contadorInicial == contadorVueltas)return;
	contadorInicial=contadorVueltas;
	velocidad += 2;
	paso = CLOCKS_PER_SEC/velocidad;
}

void TruenoLoco::armarAuto(){
	//cargar matriz con el dibujo 
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
	
	//carga la matriz con los colores del auto del enemigo LotusPoni
	color[0][0] = 0;  //rueda es negra
	color[0][1] = 0;
	color[0][2] = 12;  //punta es amarilla
	color[0][3] = 0;
	color[0][4] = 0;   //rueda es negra
	color[1][0] = 0;
	color[1][1] = 12;   //costado izq
	color[1][2] = 4;   //cabina es marron
	color[1][3] = 12;   //costado dere
	color[1][4] = 0;
	color[2][0] = 0;    //rueda es negra
	color[2][1] = 0;
	color[2][2] = 12;    //cola es amarilla
	color[2][3] = 0;
	color[2][4] = 0;    //rueda es negra
}
void TruenoLoco::actualizar(){
	if(tempo + paso < clock()) {
		mover();
		dibujar();
		tempo = clock();
	}
}
void TruenoLoco::reiniciarTrueno(){
	borrar();
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	y = 3;
	direccion = rand()% 2;
}

void TruenoLoco::moverDiagonalDerecha(){
	if( y + alto < maxLimiteY && x + ancho <= maxLimiteX){
		borrar();
		x++;
	}else{
		borrar();
		direccion = 0; // 0 cambia direccio hacia izquierda
	}
}

void TruenoLoco::moverDiagonalIzquierda(){
	if( y + alto < maxLimiteY && x  > minLimiteX){
		borrar();
		x--;
	}else{
		borrar();
		direccion = 1; //1 cambia direccion hacia derecha
	}
}

void TruenoLoco:: mover(){
	
	if( y + alto < maxLimiteY ){
		if( direccion == 0 ) moverDiagonalIzquierda();
		else moverDiagonalDerecha();
		y++;
	}else{
		reiniciarTrueno();
		contadorVueltas+=1;
	}
	
	
}
//cuando el auto choca se reinicia a su posicion inicial
void TruenoLoco::chocar(){
	reiniciarTrueno();
}
int TruenoLoco::getVueltas(){
	return contadorVueltas;
}
TruenoLoco::~TruenoLoco() {
	
}

void TruenoLoco::reset(){
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	y = 3;
	
	//seteamos en el contructor la velocidad inicial para Trueno Loco
	velocidad = 3;
	
	// elige direccion al azar entre 0 y 1 (0 izq, 1 der)
	direccion = rand()% 2;
	tempo = clock();
	paso = CLOCKS_PER_SEC/velocidad;
	contadorVueltas = 0;
	contadorInicial = 0;
	
}
