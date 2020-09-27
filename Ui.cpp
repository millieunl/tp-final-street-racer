#include "Ui.h"
#include<iostream>


Ui::Ui() {
	tempo = clock();
	paso = CLOCKS_PER_SEC/60;
		
	ancho = 29;
	alto = 29;
}

Ui::~Ui() {
	
}


void Ui::dibujar(){
	
	textbackground(GREEN);
	//dibuja barra izquierda (1,1)
	for (int i = 0; i < alto; i++){
		for (int j = 1; j < ancho; j++){
			gotoxy(i+2, j+1);
			std::cout<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	//dibuja segunda barra
	for (int i = 0; i < alto; i++){
		for (int j = 1; j < ancho; j++){
		gotoxy(91+i, j+1);
		std::cout<<" ";
		}
	std::cout<<std::endl;
	}
	
	
	//dibuja carretera
	textbackground(DARKGRAY);
	for (int i = 0; i < 58; i++){
		for (int j = 1; j < ancho; j++){
			gotoxy(32+i, j+1);
			std::cout<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	
	//textbackground(0);
	
}

void Ui::actualizar() {
	if(tempo + paso < clock()) {
		dibujar();
		tempo = clock();
	}
	
}

