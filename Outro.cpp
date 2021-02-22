#include "Outro.h"
#include <conio2.h>
#include<iostream>

Outro::Outro() {
	reset();
}

Outro::~Outro() {
	
}

void Outro::actualizar(){
	mostrarMenu();
	while(capturando){
		mostrarMensaje();  //informa que se perdio el juego
		eventos();
	}
}
void Outro::setPuntaje(int puntaje){
	this ->puntaje = puntaje;
}

bool Outro::getQuiereSalir(){
	return quiereSalir;
}
void Outro::mostrarMensaje(){
	//titulo con el nombre del juego
	textcolor(LIGHTGREEN);
	gotoxy(30,5);
	std::cout<<"<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>";
	gotoxy(30,6);
	std::cout<<"<<   __              ___     __        ___  __    >>"<<std::endl;
	gotoxy(30,7);  
	std::cout<<"<<  / _`  /"<<char(92)<<"   |"<<char(92)<<"/| |__     /  "<<char(92)<<" "<<char(92)<<"  / |__  |__)   >>"<<std::endl;
	gotoxy(30,8);
	std::cout<<"<<  "<<char(92)<<"__> /~~"<<char(92)<<"  |  | |___    "<<char(92)<<"__/  "<<char(92)<<"/  |___ |  "<<char(92)<<"   >>"<<std::endl;
	gotoxy(30,9);
	std::cout<<"<<                                                >>";
	gotoxy(30,10);
	std::cout<<"<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>";
	
	
	gotoxy(30,12);
	std::cout<<"Has obtenido "<<puntaje<<" puntos en esta carrera!!";
	//marquesina de color
	for (int i = 0;i<100;i++){
		textcolor(rand()%6 +10);
		gotoxy(6+i,15);
		std::cout<<"*";
	}
	
}

void Outro::mostrarMenu(){
	textcolor(YELLOW);
	gotoxy(45,17);
	std::cout<< "Quieres volver a jugar?"<<std::endl;
	textcolor(LIGHTGREEN);
	gotoxy(1,19);
	std::cout<< ">> Selecciona una opcion con las teclas [IZQUIERDA] o [DERECHA] y presiona [ENTER] para aceptar <<"<<std::endl;
	
	//botones 
	gotoxy(18,22);
	textcolor(YELLOW);
	std::cout<< "------------------------"<<std::endl;
	gotoxy(19,23);
	textcolor(LIGHTMAGENTA);
	std::cout<< "QUIERO JUGAR DE NUEVO!"<<std::endl;
	gotoxy(18,24);
	textcolor(YELLOW);
	std::cout<< "------------------------"<<std::endl;
	
	gotoxy(66,23);
	textcolor(LIGHTGRAY);
	std::cout<< "DESEO SALIR DEL JUEGO "<<std::endl;
	
}

bool Outro::eventos(){
	if (kbhit()){
		clrscr();
		mostrarMenu();
		int tecla = getch(); //captura la tecla que se presiona
		switch(tecla){
		case 67:
		case 77:
			//resalta texto izquierda
			gotoxy(65,22);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			gotoxy(66,23);
			textcolor(LIGHTMAGENTA);
			std::cout<< "DESEO SALIR DEL JUEGO "<<std::endl;
			gotoxy(65,24);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			
			gotoxy(18,22);
			std::cout<< "                                  "<<std::endl;
			gotoxy(19,23);
			textcolor(LIGHTGRAY);
			std::cout<< "QUIERO JUGAR DE NUEVO!"<<std::endl;
			gotoxy(18,24);
			std::cout<< "                                "<<std::endl;
			quiereSalir = true;
			break;
			//return false;
		case 68:
		case 75://iz
			//resalta texto derecha, si estoy listo y pone borde de seleccion
			gotoxy(18,22);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			gotoxy(19,23);
			textcolor(LIGHTMAGENTA);
			std::cout<< "QUIERO JUGAR DE NUEVO!"<<std::endl;
			gotoxy(18,24);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			
			//saca de foco la opcion no estoy listo
			gotoxy(65,22);
			std::cout<< "                                "<<std::endl;
			gotoxy(66,23);
			textcolor(LIGHTGRAY);
			std::cout<< "DESEO SALIR DEL JUEGO "<<std::endl;
			gotoxy(65,24);
			std::cout<< "                                    "<<std::endl;
			quiereSalir = false;  
			break;
			
		case 13:
			capturando = false;
			break;
		}
	}		
return false;
}
void Outro::reset(){
	x = 0;
	puntaje = 0;
	quiereSalir = false;	
	capturando = true;
}
