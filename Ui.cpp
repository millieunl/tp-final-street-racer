#include "Ui.h"
#include<iostream>


Ui::Ui() {
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	//inicializa el valor de puntos
	puntaje = 0;
	
}

Ui::~Ui() {
	
}

void Ui::setPuntaje(int puntaje) {
	this ->puntaje = puntaje;
}
	
int Ui::getPuntaje() {
	return puntaje;
}

void Ui::mostrarPuntaje() {
	gotoxy(55,1);
	textbackground(BLACK);
	textcolor(WHITE);
	std::cout<<"puntaje: "<<getPuntaje()<<std::endl;
}


void Ui::dibujar(){
	//ver si mostrar puntaje va a aca y ponemos esa funcion privada despues
}

void Ui::actualizar() {
	if(tempo + paso < clock()) {
		mostrarPuntaje();
		tempo = clock();
	}
	
}

