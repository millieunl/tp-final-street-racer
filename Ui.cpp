#include "Ui.h"
#include<iostream>


Ui::Ui() {
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	//inicializa el valor de puntos
	puntaje = 0;
	vidas = 0;
	
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
	gotoxy(35,1);
	textbackground(BLACK);
	textcolor(BLACK);
	std::cout<<"                  "; //Fix para que limpie el renglon
	gotoxy(35,1);
	textbackground(BLACK);
	textcolor(WHITE);
	std::cout<<"puntaje: "<<puntaje<<std::endl;
}

void Ui::mostrarVidas(){
	gotoxy(70,1);
	textbackground(BLACK);
	textcolor(WHITE);
	std::cout<<"Vidas: "<<vidas<<std::endl;
}

void Ui::setVidas(int vidas){
	this -> vidas = vidas;
}

int Ui::getVidas(){
	return vidas;
}
void Ui::dibujar(){
	//ver si mostrar puntaje va a aca y ponemos esa funcion privada despues
	mostrarPuntaje();
	mostrarVidas();
}

void Ui::actualizar() {
	if(tempo + paso < clock()) {
		mostrarPuntaje();
		mostrarVidas();
		tempo = clock();
	}
}

