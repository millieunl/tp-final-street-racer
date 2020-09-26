#include "Juego.h"
#include <conio2.h>



//contructor
Juego::Juego() {
	//inicia una instancia en memoria dinamica para el objeto auto
	auto1 = new Auto();
	//setea los limites de la pantalla
	auto1->setLimite(10,70,0,45);
}

//destructor de clase
Juego::~Juego() {
	delete auto1;
}

void Juego::eventos(){
	if (kbhit()){
		int tecla = getch();
		switch(tecla) {
		case 67: 			//derecha
			//llama funcion para moverse a la derecha
			break;
		case 68: 			//izquierda
			//llama funcion para moverse a la izquierda
			break;
		}
	}
}

void Juego::jugar(){
	
	while(true){
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
