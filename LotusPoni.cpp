#include "LotusPoni.h"
#include <conio2.h>

LotusPoni::LotusPoni() {	
	armarAuto();
	reset();
}

void LotusPoni::acelerar(){
	if(contadorVueltas== contadorAceleraciones)  return;
	contadorAceleraciones=contadorVueltas;
	velocidad += 2;
	paso = CLOCKS_PER_SEC/velocidad;
	
	gotoxy(1,3);
	std::cout<<"acelera Poni  " <<velocidad;
	
	
}
void LotusPoni::armarAuto(){
	//matriz que carga el dise�o del auto
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
	color[0][2] = 14;  //punta es amarilla
	color[0][3] = 0;
	color[0][4] = 0;   //rueda es negra
	color[1][0] = 0;
	color[1][1] = 15;   //costado izq
	color[1][2] = 6;   //cabina es marron
	color[1][3] = 15;   //costado dere
	color[1][4] = 0;
	color[2][0] = 0;    //rueda es negra
	color[2][1] = 0;
	color[2][2] = 14;    //cola es amarilla
	color[2][3] = 0;
	color[2][4] = 0;    //rueda es negra
}
void LotusPoni::actualizar(){
	if(tempo + paso < clock()) {
		mover();
		dibujar();
		tempo = clock();
	}
}

void LotusPoni::reiniciarLotus(){
	borrar();
	setPosicion(minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) ),3);
}
void LotusPoni:: mover(){
	if (y + alto < maxLimiteY){
		borrar();
		y++;;
	}else {
		reiniciarLotus();
		contadorVueltas+=1;
	}
	
}

//cuando el auto choca se reinicia a su posicion inicial
void LotusPoni::chocar(){
	reiniciarLotus();
}

int LotusPoni::getVueltas(){
	return contadorVueltas;
}

LotusPoni::~LotusPoni() {
	
}

void LotusPoni::reset(){
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	y = 3;
	
	velocidad = 4;
	tempo = clock();
	paso = CLOCKS_PER_SEC/velocidad;

	contadorVueltas = 0;
	contadorAceleraciones = 0;
}
