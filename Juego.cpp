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
	chocoLotus = false;
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

bool Juego::hayColision(Vehiculo *v1, Vehiculo *v2){
	//arreglar el tema de los punteros dentro de un argumento, quien libera ese puntero
	if((v1-> getX() < v2->getX() + v2->getAncho()) &&
		(v1->getX() + v1->getAncho() > v2->getX()) &&
	    (v1-> getY() < v2->getY() + v2->getAlto()) &&
		(v1->getY() + v1->getAlto() > v2->getY())){
		return true;
	}
	return false;
}



void Juego::jugar(){
	while(true){
		ui->actualizar();
		nivel->actualizar();
		eventos();
		jugador->actualizar();
		lotusPoni->actualizar();
		truenoLoco->actualizar();
		
		//deteccion de colision entre autos
		chocoTrueno = hayColision(jugador,truenoLoco);
		chocoLotus = hayColision(jugador,lotusPoni);
		
		//si hay choque con algun auto
		//choque con el enemigo truenoLoco
		if(chocoTrueno){
			truenoLoco->chocar();
			jugador->chocar();
		}
		//choque con el enemigo LotusPoni
		if(chocoLotus){
			lotusPoni->chocar();
			jugador->chocar();
		}
	}
		

}
