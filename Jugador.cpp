#include "Jugador.h"

Jugador::Jugador() {
	//define el tiempo del auto del jugador
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	temporizador = new Temporizador();
	estaParpadeando = false;
	x = y = 1;
	
	//dibujo del auto del Jugador
	armarAuto();
	
}

void Jugador::armarAuto(){
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
	
	//carga la matriz con los colores del auto del jugador
	colorearAuto();
}
void Jugador::colorearAuto(){
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
void Jugador::actualizar(){
	if(tempo + paso < clock()) {
		dibujar();
		if(estaParpadeando){
			parpadear();
		}
		
		if(temporizador->tiempocumplido()){
			estaParpadeando = false;
			colorearAuto();
		}
		tempo = clock();
		
	}
	
}


void Jugador::moverDerecha() {
	if(x + ancho  <= maxLimiteX) {
		borrar(); 
		x++;
	}
}

void Jugador::moverIzquierda() {
	if(x > minLimiteX ){
		borrar(); 
		x--;
	}
}
void Jugador::parpadear(){
	//efecto cambia color auto chocado
	for(int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++){
			color[i][j]= rand()% 15;
		}
	}
}
void Jugador:: chocar(){
	borrar();
	temporizador->iniciar(1000);
	estaParpadeando = true;
	
}

Jugador::~Jugador() {
	delete temporizador;
	
}

