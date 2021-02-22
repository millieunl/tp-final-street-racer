#include "Juego.h"
#include "Jugador.h"
#include "LotusPoni.h"
#include "TruenoLoco.h"
#include <conio2.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
//contructor de la clase
Juego::Juego() {
	//iniciamos la semilla para random
	srand (time(NULL)); 
	
	//para fixear el color de fondo
	textbackground(DARKGRAY);
	clrscr();
	
	//instanciamos objetos y seteamos valores, inicializamos boleanas
	jugador = new Jugador();
	jugador->setPosicion(31,23);  //x = 31 y = 23
	
	lotusPoni = new LotusPoni();
	truenoLoco = new TruenoLoco();
	
	ui = new Ui();
	ui->setVidas(jugador->getVidas());
	
	nivel = new Nivel();
	nivel->dibujar();
	
	
	intro = new Intro();
	outro = new Outro();
	
	
}

//destructor de clase
Juego::~Juego() {
	delete intro;
	delete jugador;
	delete lotusPoni;
	delete truenoLoco;
	delete ui;
	delete nivel;
	delete outro;
}

void Juego::eventos(){
	if (kbhit()){
		int tecla = getch(); //captura la tecla que se presiona
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


void Juego::lanzarIntro(){
	textbackground(BLACK);
	clrscr();
	intro->actualizar();
	textbackground(DARKGRAY);
	clrscr();
}
 void Juego::lanzarOutro(){
	textbackground(BLACK);
	clrscr();
	outro->setPuntaje(ui->getPuntaje());
	outro->actualizar();
	textbackground(BLACK);
	clrscr();
}

void Juego:: reiniciar(){
	//reinicia todos los parametros para el juego
	jugador->reset();
	lotusPoni->reset();
	truenoLoco->reset();
	outro->reset();
}

void Juego::detectarColision(){
	
	//choque jugador-truenoLoco
	if(hayColision(jugador,truenoLoco)){
		truenoLoco->chocar();
		jugador->chocar();
	}
	//choque jugador-LotusPoni
	if(hayColision(jugador,lotusPoni)){
		lotusPoni->chocar();
		jugador->chocar();
	}
	//choque truenoLoco-lotusPoni
	if(hayColision(truenoLoco,lotusPoni)){
		lotusPoni->chocar();
		truenoLoco->chocar();
	}
}
void Juego::jugar(){
	while(true){ //mientras no quiera salir del juego
		
		//lanza la pantalla de introduccion del juego		
		lanzarIntro();
		
		//dibuja el escenario del juego
		nivel->dibujar();	
		
		//comienza el bucle del juego
		while(jugador->getVidas() > 0){  //mientras tenga vida
			
			//actualizamos
			ui->actualizar();
			nivel->actualizar();
			jugador->actualizar();
			lotusPoni->actualizar();
			truenoLoco->actualizar();
			
			//eventos para el teclado
			eventos();
			
			//para mostrar el puntaje y las vidas con la ui
			ui->setPuntaje(lotusPoni->getVueltas() + truenoLoco->getVueltas());
			ui->setVidas(jugador->getVidas());
			
			//si el puntaje alcanza multiplos de 20 aceleran los enemigos
			if((ui->getPuntaje() %20 == 0) && (ui->getPuntaje() != 0)){
				truenoLoco->acelerar();
				lotusPoni->acelerar();
			}	
			//detecta colisiones y muestra el choque
			detectarColision();
			
			//cuando no hay mas vidas y que no vaya abrutmanete a la pantalla de game over
			if(jugador->getVidas() == 0) { 
				ui->setVidas(0);
				ui->dibujar();
				Sleep(1000);
			}
		}// fin while anidado
		
		//lanza la pantalla de game over
		lanzarOutro();
		
		// decide si salir del  bucle del juego o no
		if(outro->getQuiereSalir()){
			//se va del bucle y termina el juego
			break; 
		}else{
			//reiniciar todos los parametros para volver a jugar
			reiniciar(); 
		}
	}//fin while principal	
	
}

