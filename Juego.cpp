#include "Juego.h"
#include <conio2.h>
#include <stdlib.h>



#include <time.h>

//contructor
Juego::Juego() {
	
	srand (time(NULL));
	//inicia una instancia en memoria dinamica para el objeto auto
	textbackground(DARKGRAY);
	clrscr();
	jugador = new Jugador();
	lotusPoni = new LotusPoni();
	truenoLoco = new TruenoLoco();
	ui = new Ui();
	nivel = new Nivel();
	
	//setea la posicion inicial del auto del jugador
	jugador->setPosicion(31,23);  //x = 31 y = 23
	
	//dibuja el nivel una sola vez
	nivel->dibujar();
	
	chocoTrueno = false;
}

//destructor de clase
Juego::~Juego() {
	delete jugador;
	delete lotusPoni;
	delete truenoLoco;
	delete ui;
	delete nivel;
}

void Juego::eventos(){
	if (kbhit()){
		int tecla = getch();
		switch(tecla) {
		case 67:
		case 77://derecha
			//llama funcion para moverse a la derecha
			jugador->moverDerecha();
			break;
		case 68:
		case 75://izquierda
			//llama funcion para moverse a la izquierda
			jugador->moverIzquierda();
			break;
		}
	}
}

bool Juego::hayColision( int ancho, int alto, int x0, int y0, int x1, int y1){
	
	if((x0 < x1 + ancho) && (x0 + ancho > x1) && (y0 < y1 + alto) && (y0 + alto > y1)){
		return true;
	}
	return false;
	/*
	//chequea si hay colision en un
	chocoTrueno = hayColision(truenoLoco.ancho, truenoLoco.alto, TruenoLoco.x);
	chocoPoni = 
	chocoObstaculo = 
	
	if(chocoTrueno){
	truenoLoco.kill();
	jugador.kill();
}
	void Juego::matar(obejto, quienchoco){
	if quienchoco{
	obejto.kill();
	};
	*/


}
void Juego::jugar(){
	while(true){
		ui->actualizar();
		nivel->actualizar();
		eventos();
		jugador->actualizar();
		//lotusPoni->actualizar();
		truenoLoco->actualizar();
		chocoTrueno = hayColision(truenoLoco->getAncho(), truenoLoco->getAlto(), truenoLoco->x, truenoLoco->y, jugador->x, jugador->y);
		if(chocoTrueno) {
			gotoxy(1,1);
			std::cout<<"chocoo"<<std::endl;
			
		}
	}
	
	/*
	clock_t tiempoInicial = clock();
	clock_t tiempoActual;
	clock_t paso = CLOCKS_PER_SEC/1;
	while(true) {
		tiempoActual = clock();
		if(tiempoActual - tiempoInicial > paso){
			std::cout<<"hola"<<std::endl;
			//auto1.update();
			tiempoInicial = clock();
		}
	}
	*/
}
