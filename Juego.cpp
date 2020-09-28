#include "Juego.h"
#include <conio2.h>



//contructor
Juego::Juego() {
	//inicia una instancia en memoria dinamica para el objeto auto
	textbackground(DARKGRAY);
	clrscr();
	auto1 = new Auto();
	ui = new Ui();
	nivel = new Nivel();
	
	//setea los limites de la pantalla
	auto1->setLimite(30,85,0,45);
	
	//dibuja el nivel una sola vez
	nivel->dibujar();
}

//destructor de clase
Juego::~Juego() {
	delete auto1;
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
			auto1->moverDerecha();
			break;
		case 68:
		case 75://izquierda
			//llama funcion para moverse a la izquierda
			auto1->moverIzquierda();
			break;
		}
	}
}

void Juego::jugar(){
	while(true){
		ui->actualizar();
		nivel->actualizar();
		eventos();
		auto1->actualizar();
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
