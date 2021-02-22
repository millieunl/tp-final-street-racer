#include "Juego.h"
#include <conio2.h>
#include <stdlib.h>



#include <time.h>

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
	
	//inicializamos variables booleanas
	chocoTrueno = false;
	chocoLotus = false;
	chocoLotusTrueno =  false;
	
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


void Juego::jugar(){
	//esta es la pantalla de la introduccion
	textbackground(BLACK);
	clrscr();
	//intro->actualizar();
	outro->actualizar();
	textbackground(DARKGRAY);
	clrscr();
	nivel->dibujar();

	//bucle del juego
	while(true){  
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
		if((ui->getPuntaje() %10 == 0) && (ui->getPuntaje() != 0)){
			truenoLoco->acelerar();
			lotusPoni->acelerar();
		}
	
		//deteccion de colision entre autos
		chocoTrueno = hayColision(jugador,truenoLoco);
		chocoLotus = hayColision(jugador,lotusPoni);
		chocoLotusTrueno = hayColision(truenoLoco,lotusPoni);
		
		//choque jugador-truenoLoco
		if(chocoTrueno){
			truenoLoco->chocar();
			jugador->chocar();
		}
		//choque jugador-LotusPoni
		if(chocoLotus){
			lotusPoni->chocar();
			jugador->chocar();
		}
		//choque truenoLoco-lotusPoni
		if(chocoLotusTrueno){
			lotusPoni->chocar();
			truenoLoco->chocar();
		}
		
		if(jugador->getVidas() == 0){
			//sale del juego
			break;
		}
	}// fin while
	textbackground(BLACK);
	clrscr();
	outro->actualizar();
	
		
}
