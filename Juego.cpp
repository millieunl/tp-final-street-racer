#include "Juego.h"
#include "Jugador.h"
#include "LotusPoni.h"
#include "TruenoLoco.h"
#include <conio2.h>
#include <time.h>
#include <Windows.h>


//contructor de la clase
Juego::Juego() {
	//iniciamos la semilla para randomizar valores
	srand (time(NULL)); 
	
	//instanciamos objetos y seteamos valores, inicializamos boleanas
	jugador = new Jugador(30);
	jugador->setPosicion(31,23);  //x = 31 y = 23
	lotusPoni = new LotusPoni(4);
	truenoLoco = new TruenoLoco(5);
	obstaculo = new Obstaculo(2);
	ui = new Ui();
	ui->setVidas(jugador->getVidas());
	nivel = new Nivel();
	nivel->dibujar();
	introduccion = new Introduccion();
	epilogo = new Epilogo();
}

//destructor
Juego::~Juego() {
	//destruimos los objetos y // Libera la memoria reservada a cada uno
	delete introduccion;
	delete jugador;
	delete lotusPoni;
	delete truenoLoco;
	delete obstaculo;
	delete ui;
	delete nivel;
	delete epilogo;
}

//este metodo llama a  los eventos de otras clases
void Juego::eventos(){
	//llama al evento que sirven para mover al jugador
	jugador->mover();
}

//lanza la escena de introduccion al juego:limpia pantalla y actualiza la misma
void Juego::lanzarIntro(){
	textbackground(BLACK);
	clrscr();
	introduccion->actualizar();
	textbackground(DARKGRAY);
	clrscr();
}

//lanza la escena de GAME OVER al juego:limpia pantalla y actualiza la misma
void Juego::lanzarOutro(){
	textbackground(BLACK);
	clrscr();
	epilogo->setPuntaje(ui->getPuntaje());
	epilogo->actualizar();
	textbackground(BLACK);
	clrscr();
}

//hace los llamados a los metodos para reiniciar  todos los objetos
void Juego:: reiniciar(){
	//reinicia todos los parametros para el juego
	jugador->reset();
	lotusPoni->reset();
	truenoLoco->reset();
	obstaculo->reset();
	epilogo->reset();
}

//****************************************************
//sobrecarga de funciones
//este metodo recibe dos parametros de tipo vehiculos
//devuelve true si hay  alguna colision entre dos vehiculos
bool Juego::hayColision(Vehiculo *v1, Vehiculo *v2){
	if((v1-> getX() < v2->getX() + v2->getAncho()) &&
		(v1->getX() + v1->getAncho() > v2->getX()) &&
		(v1-> getY() < v2->getY() + v2->getAlto()) &&
		(v1->getY() + v1->getAlto() > v2->getY())){
		return true;
	}
		return false;
}

//este metodo recibe dos parametros de tipo= vehiculo y obstaculo
//devuelve  true si hay colision entre un vehiculo cualquiera y un osbstaculo
bool Juego::hayColision(Vehiculo *v1, Obstaculo *obs){
	if((v1-> getX() < obs->getX() + obs->getAncho()) &&
	(v1->getX() + v1->getAncho() > obs->getX()) &&
	(v1-> getY() < obs->getY() + obs->getAlto()) &&
	(v1->getY() + v1->getAlto() > obs->getY())){
	return true;
}
	return false;
}

//este metodo recibe dos parametros del tipo Vehiculo
//Si hay colision entre los dos vehiculos y muestra el choque entre ellos
void Juego::detectarColision(Vehiculo *v1, Vehiculo *v2){
	if(hayColision(v1,v2)){
		v1->chocar();
		v2->chocar();
	}
}

//este metodo se usa para detectar colision entre vehiculo y un obstaculo
//Si hay colision entre vehiculos define quien choco con quien y muestra el choque
void Juego::detectarColision(Vehiculo *v1, Obstaculo *obs){
	if(hayColision(v1,obs)){
		obs->chocar();
		v1->chocar();
	}
}

//**************************************
//actualiza la escena
void Juego::actualizar(){
	ui->actualizar();
	nivel->actualizar();
	jugador->actualizar();
	lotusPoni->actualizar();
	truenoLoco->actualizar();
	obstaculo->actualizar();
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
			
			//setea el puntaje en la UI , con la suma de cada vuelta completada (sin chocar) de los enemigos
			//sirve para que se pueda mostrar el puntaje y las vidas con la ui
			ui->setPuntaje(lotusPoni->getVueltas() + truenoLoco->getVueltas() + obstaculo->getVueltas());
			ui->setVidas(jugador->getVidas());
			
			//si el puntaje alcanza multiplos de 20 aceleran los enemigos
			if((ui->getPuntaje() %20 == 0) && (ui->getPuntaje() != 0)){
				truenoLoco->acelerar();
				lotusPoni->acelerar();
				obstaculo->acelerar();
			}	
			
			//detecta colisiones entre los distintos objetos y muestra el choque
			detectarColision(jugador,truenoLoco);
			detectarColision(jugador,lotusPoni);
			detectarColision(jugador,obstaculo);
			detectarColision(truenoLoco,lotusPoni);
			detectarColision(lotusPoni,obstaculo);
			detectarColision(truenoLoco,obstaculo);
			
		}// fin while anidado
		
		//cuando no hay mas vidas y que no vaya abrutmanete a la pantalla de game over
		ui->setVidas(0);
		ui->dibujar();
		Sleep(1000);
		
		//lanza la pantalla de game over
		lanzarOutro();
		
		// si es True sale del bucle = fin  del juego sino reinicia la jugada
		if(epilogo->getQuiereSalir()) {
			epilogo->mostrarDespedida();
			break; 
		}
		else reiniciar();
	
	}//fin while principal	
}

