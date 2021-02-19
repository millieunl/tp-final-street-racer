#include "TruenoLoco.h"

TruenoLoco::TruenoLoco() {
	//posiciona el auto del enemigo en una posicion fija en "Y" pero random en "X"
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	
	x =70;
	y = 3;
	// elige direccion al azar
	//0 es hacia la izquierda
	// 1 hacia la derecha
	direccion = direccion = rand()% 2;;
	tempo = clock();
	paso = CLOCKS_PER_SEC/10;
	
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

void TruenoLoco::moverDiagonalDerecha(){
	if( y + alto < maxLimiteY && x + ancho <= maxLimiteX){
		borrar();
		x++;
	}else{
		borrar();
		direccion = 0; //cambia direccio hacia izquierda
	}
}

void TruenoLoco::moverDiagonalIzquierda(){
	if( y + alto < maxLimiteY && x  > minLimiteX){
		borrar();
		x--;
	}else{
		borrar();
		direccion = 1; //cambia direccio hacia derecha
	}
}

void TruenoLoco:: mover(){
	
	if (y + alto < maxLimiteY){
		
		if( direccion == 0) moverDiagonalIzquierda();
		else moverDiagonalDerecha();
		y++;
	}else{
		borrar();
		x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
		y = 3;
		direccion = rand()% 2;
	}
	
	
}
TruenoLoco::~TruenoLoco() {
	
}

