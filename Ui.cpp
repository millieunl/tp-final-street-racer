#include "Ui.h"
#include<iostream>


Ui::Ui() {
	
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
	/*	
	ancho = 25;
	alto = 24 ;*/
	
	ancho = 29;  //con 30 anda bien
	alto = 24 ;
	
	puntaje = 0;
}

Ui::~Ui() {
	
}

void Ui::barrasLaterales() {
	//dibuja barra lateral izquierda
	textcolor(WHITE);
	for(int i=0; i<alto; i++){
		for(int j=0; j < ancho ; j++){	
			textbackground(GREEN);
			gotoxy(j+1,i+3);
			std::cout<<char(176);  //<<"x";
		}
	}
	 //dibuja barra lateral derecha
	for(int i=0; i<alto; i++){
		for(int j=0; j < ancho ; j++){	
			textbackground(GREEN);
			gotoxy(j+87,i+3);
			std::cout<<char(176);
		}
	}
	//borde de la carretera
	for(int i=0; i<alto; i++){
		textbackground(BROWN);
		gotoxy(30,i+3);
		std::cout<<" ";
	}
	for(int i=0; i<alto; i++){
		textbackground(BROWN);
		gotoxy(86,i+3);
		std::cout<<" ";
	}
	
	/*
	//esto para la carretera mas ancha BORRAR SI YA NO SIRVE
	for(int i=0; i<alto; i++){
		for(int j=0; j < ancho ; j++){	
			textbackground(GREEN);
			gotoxy(j+1,i+3);
			std::cout<<"x";
		}
	}
	for(int i=0; i<alto; i++){
		for(int j=0; j < ancho ; j++){	
			textbackground(GREEN);
			gotoxy(j+91,i+3);
			std::cout<<"x";
		}
	}*/
	
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

void Ui::carretera() {
	
	//dibuja barra arriba
	for (int i = 0; i < 115; i++){
		for(int j=0; j < 2 ; j++){	
			gotoxy(i+1,j+1);
			textbackground(BLACK);
			std::cout<<" "<<std::endl;
		}
	}
	//dibuja barra abajo
	for (int i = 0; i < 115; i++){
		for(int j=0; j < 2 ; j++){	
			gotoxy(i+1,j+27);
			textbackground(BLACK);
			std::cout<<" "<<std::endl;
		}
	}
	
	
	//dibuja linea blanca en medio de la carretera
	for (int i = 5; i < 30; i+=5){
	gotoxy(57, i-1);
	textcolor(WHITE);
	std::cout<<char(219)<<std::endl;
	}
	textbackground(BLACK);
	
}
void Ui::dibujar(){
	
	barrasLaterales();
	carretera();
}

void Ui::actualizar() {
	if(tempo + paso < clock()) {
		mostrarPuntaje();
		dibujar();
		//tempo = clock();
	}
	
}

