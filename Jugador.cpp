#include "Jugador.h"

Jugador::Jugador() {
	//define el tiempo del auto del jugador
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	x = y = 1;
	
	//carga la matriz con los colores del auto del jugador
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
	
}

void Jugador::moverDerecha() {
	
	if(x + ancho < maxLimiteX) { borrar(); x = x + ancho;}
	
}

void Jugador::moverIzquierda() {
	
	if(x - ancho < minLimiteX) return;
	else{
		borrar(); 
		x = x-ancho;
	}
}


Jugador::~Jugador() {
	
}

