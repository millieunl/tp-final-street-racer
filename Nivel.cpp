#include "Nivel.h"
#include <conio2.h>
#include<iostream>

Nivel::Nivel() {
	//inicializamos  las variables para el reloj
	tempo = clock();
	paso = CLOCKS_PER_SEC/20;
	
	//inicializamos el valor de ancho y alto  para las barras laterales (pasto)
	ancho = 29; 
	alto = 24 ;
	
	y = 0;
 
}

void Nivel::dibujarPasto(int posx, int posy) {
	textcolor(WHITE);
	for(int i=0; i<alto; i++){
		for(int j=0; j < ancho ; j++){	
			textbackground(GREEN);
			gotoxy(j + posx, i + posy);
			std::cout<<char(176); 
		}
	}
}

void Nivel::dibujarBarraHorizontal(int posy){
	//dibuja barra horizontal 
	for (int i = 0; i < 115; i++){
		for(int j=0; j < 2 ; j++){	
			gotoxy(i + 1,j + posy);
			textbackground(BLACK);
			std::cout<<" "<<std::endl;
		}
	}
}

void Nivel::bordeCarretera(int posx, int posy){
	//borde de la carretera
	for(int i=0; i<alto; i++){
		textbackground(BROWN);
		gotoxy(posx, i + posy);
		std::cout<<" ";
	}
}
//metodo que dibuja linea blanca en medio de la carretera
void Nivel::decoracionCarretera() {
	for (int i = 5; i < 30; i+=5){
		gotoxy(57, i-1);
		textcolor(WHITE);
		std::cout<<char(219)<<std::endl;
	}
	textbackground(BLACK);
}
//tetstststs
void Nivel::lineaMovil(){
	if(y <3){ //3
		for (int i = 4; i < 22; i+=3){ //18

			gotoxy(57, y+i);//4
			textcolor(WHITE);
			std::cout<<char(219);
			
			gotoxy(57, y+(i -1));
			textcolor(DARKGRAY);
			std::cout<<char(219);
			
		
			gotoxy(57, y+i+3);//7
			textcolor(WHITE);
			std::cout<<char(219);
			
			gotoxy(57, y+(i+5));
			textcolor(DARKGRAY);
			std::cout<<char(219);
			
			/*
			gotoxy(57, y+(i+6));//10
			textcolor(WHITE);
			std::cout<<char(219);
			
			gotoxy(57, y+(i+8));
			textcolor(DARKGRAY);
			std::cout<<char(219);
			*/
		
		}
		
		y++;
	}else {
		y = 0;
	}
	
	
	
	
	
}
void Nivel::dibujar(){
	//dibuja los distintos elementos del nivel (pasto, barras horizontales, borde de la carretera)
	dibujarPasto(1,3);
	dibujarPasto(87,3);
	dibujarBarraHorizontal(1);
	dibujarBarraHorizontal(27);
	bordeCarretera(30,3);
	bordeCarretera(86,3);
	
} 

void Nivel::actualizar(){
	//actualiza las lineas de la carretera
	if( tempo + paso <clock()){
		//decoracionCarretera();
		lineaMovil();
	
		tempo = clock();
	}
}
