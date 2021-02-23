#include "Juego.h"
#include "Jugador.h"
#include "LotusPoni.h"
#include "TruenoLoco.h"
#include <conio2.h>
//#include <stdlib.h>
#include <time.h>
#include <Windows.h>


//contructor de la clase
Juego::Juego() {
	//iniciamos la semilla para randomizar valores
	srand (time(NULL)); 
	
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

//destructor
Juego::~Juego() {
	//destruimos los objetos y // Libera la memoria reservada a cada uno
	delete intro;
	delete jugador;
	delete lotusPoni;
	delete truenoLoco;
	delete ui;
	delete nivel;
	delete outro;
}


void Juego::eventos(){
	
	jugador->mover();
	
	/*
	//if(kbhit()){
	int tecla = getch(); //captura la tecla que se presiona
	switch(tecla) {
	case 67:
	case 77://derecha
	//llama funcion para moverse a la derecha
	//jugador->moverDerecha();
	jugador->mover();
	break;
	case 68:
	case 75://izquierda
	//llama funcion para moverse a la izquierda
	//jugador->moverIzquierda();
	break;
	}
	}
	*/
	
}


//lanza la escena de introduccion al juego:limpia pantalla y actualiza la misma
void Juego::lanzarIntro(){
	textbackground(BLACK);
	clrscr();
	intro->actualizar();
	textbackground(DARKGRAY);
	clrscr();
}

//lanza la escena de GAME OVER al juego:limpia pantalla y actualiza la misma
void Juego::lanzarOutro(){
	textbackground(BLACK);
	clrscr();
	outro->setPuntaje(ui->getPuntaje());
	outro->actualizar();
	textbackground(BLACK);
	clrscr();
}

//hace los llamados a los metodos para reiniciar  todos los objetos
void Juego:: reiniciar(){
	//reinicia todos los parametros para el juego
	jugador->reset();
	lotusPoni->reset();
	truenoLoco->reset();
	outro->reset();
}

//devuelve true si hay  alguna colision entre dos objetos del tipo vehiculo
bool Juego::hayColision(Vehiculo *v1, Vehiculo *v2){
	if((v1-> getX() < v2->getX() + v2->getAncho()) &&
		(v1->getX() + v1->getAncho() > v2->getX()) &&
		(v1-> getY() < v2->getY() + v2->getAlto()) &&
		(v1->getY() + v1->getAlto() > v2->getY())){
		return true;
	}
		return false;
}

//Si hay colision entre vehiculos define quien choco con quien y muestra el choque
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

//actualiza la escena
void Juego::actualizar(){
	ui->actualizar();
	nivel->actualizar();
	jugador->actualizar();
	lotusPoni->actualizar();
	truenoLoco->actualizar();
}

//lanza el bucle principal del juego
void Juego::jugar(){
	//mientras no quiera salir del juego
	while(true){ 
		//lanza la pantalla de introduccion del juego		
		lanzarIntro();
		
		//dibuja el escenario del juego
		nivel->dibujar();	
		
		//bucle  para jugar mientras tenga vida
		while(jugador->getVidas() > 0){ 
			
			//actualizamos la escena completa
			actualizar();
			
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
			
		}// fin while anidado
		
		//cuando no hay mas vidas y que no vaya abrutmanete a la pantalla de game over
		ui->setVidas(0);
		ui->dibujar();
		Sleep(1000);
		
		//lanza la pantalla de game over
		lanzarOutro();
		
		// si es True sale del bucle = fin  del juego sino reinicia la jugada
		if(outro->getQuiereSalir()) break; 
		else reiniciar();
	
	}//fin while principal	
	
}

