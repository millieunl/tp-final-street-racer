#include "Juego.h"
#include <conio2.h>
#include <stdlib.h>



//contructor
Juego::Juego() {
	srand (time(NULL));
	//inicia una instancia en memoria dinamica para el objeto auto
	textbackground(DARKGRAY);
	clrscr();
	jugador = new Jugador();
	ui = new Ui();
	nivel = new Nivel();
	
	//setea la posicion inicial del auto del jugador
	jugador->setPosicion(31,23);  //x = 31 y = 23
	
	//setea la posicion del enemigo LotusPoni
	lotusPoni.setPosicion(31,4);
	
	
	//setea los limites de la ruta donde se mueve el auto
	//jugador->setLimite(30,85,1,45);
	
	//dibuja el nivel una sola vez
	nivel->dibujar();
	
	
}

//destructor de clase
Juego::~Juego() {
	delete jugador;
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

void Juego::jugar(){
	while(true){
		ui->actualizar();
		nivel->actualizar();
		eventos();
		jugador->actualizar();
		
		lotusPoni.actualizar();
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
