#include "Outro.h"
#include <conio2.h>
#include<iostream>

Outro::Outro() {
	x = 0;
	quiereSalir=false;
}

Outro::~Outro() {
	
}

void Outro::actualizar(){
	mostrarMenu();
	while(true){
		mostrarMensaje();
		if(eventos())break;
	}
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
		int tecla = getch(); //captura la tecla que se presiona
		
		switch(tecla) {
		case 67:
		case 77://derecha : NO VUELVE A JUGAR
			x = 65;
			quiereSalir = true;
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
			break;
			//return false;
			
		case 68:
		case 75://izquierda VULEVE A JUGAR
			x = 18;
			quiereSalir = false;
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
			break;
			//return false;
			
			
		case 13:
			if(!quiereSalir) return true;
			//if(!quiereSalir) break;
			//if(x == 18) return true; //quiere volver a jugar
			//else break;
		}
		
		
	} //fin
	return false;
}
