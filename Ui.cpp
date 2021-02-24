#include "Ui.h"
//incluimos librerias necesarias
#include<iostream>
#include <conio2.h>

//contructor
Ui::Ui(int vidas, int nivel) {
	this -> vidas = vidas;
	this ->nivel = nivel;
	//este metdodo inicializa variables a valores por defecto
	reset();
}

//dibuja en pantalla la informacion para el usuario
void Ui::dibujar(){
	mostrarPuntaje();
	mostrarVidas();
	mostrarNivel();
}

//
void Ui::actualizar() {
	if(tempo + paso < clock()) {
		dibujar();
		tempo = clock();
	}
}

//informa el numero de nievel
void Ui::mostrarNivel(){
	gotoxy(20,1);
	textbackground(BLACK);
	textcolor(BLACK);
	std::cout<<"                  "; //Fix para que limpie el renglon
	gotoxy(20,1);
	textcolor(WHITE);
	std::cout<<"Nivel: "<<nivel<<std::endl;
}

//muestra el puntaje en una posicion de la pantalla
void Ui::mostrarPuntaje() {
	gotoxy(50,1);
	textbackground(BLACK);
	textcolor(BLACK);
	std::cout<<"                  "; //Fix para que limpie el renglon
	gotoxy(50,1);
	textbackground(BLACK);
	textcolor(WHITE);
	std::cout<<"puntaje: "<<puntaje<<std::endl;
}

//muestra las vidas en una poscion de la pantalla
void Ui::mostrarVidas(){
	gotoxy(90,1);
	textbackground(BLACK);
	textcolor(WHITE);
	std::cout<<"Vidas: "<<vidas<<std::endl;
}

//reincia todas las variables
void Ui::reset(){
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	
	//inicializa el valor de puntos,nivel y vida
	puntaje = 0;
	puntajeInicial = 0;
	vidas = 0;
	nivel = 1;
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

//para setear el valor de nivel
void Ui::setNivel(int nivel){
	this -> nivel = nivel;
}

