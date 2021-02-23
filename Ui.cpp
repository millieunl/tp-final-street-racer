#include "Ui.h"
//incluimos librerias necesarias
#include<iostream>
#include <conio2.h>

//contructor
Ui::Ui() {
	
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	//inicializa el valor de puntos y vida
	puntaje = 0;
	vidas = 0;
	
}

//
void Ui::dibujar(){
	mostrarPuntaje();
	mostrarVidas();
}

//
void Ui::actualizar() {
	if(tempo + paso < clock()) {
		mostrarPuntaje();
		mostrarVidas();
		tempo = clock();
	}
}

//muestra el puntaje en una posicion de la pantalla
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

//muestra las vidas en una poscion de la pantalla
void Ui::mostrarVidas(){
	gotoxy(70,1);
	textbackground(BLACK);
	textcolor(WHITE);
	std::cout<<"Vidas: "<<vidas<<std::endl;
}
//getter y setters
// se usa para setear el puntaje,
// 1 parametro, un entero que alamacena el puntaje acumulado
void Ui::setPuntaje(int puntaje) {
	this ->puntaje = puntaje;
}
	
//devuleve el valor guardado en la variable privada puntaje
int Ui::getPuntaje() {
	return puntaje;
}


//setea vidas , guarda el valor en la variable privada vidas
// 1 parametro, entero que almacena la cantidad de vidas 
void Ui::setVidas(int vidas){
	this -> vidas = vidas;
}

//devuleve el valor de vidas
int Ui::getVidas(){
	return vidas;
}

