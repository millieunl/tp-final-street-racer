#include "Nivel.h"
#include <conio2.h>
#include<iostream>

Nivel::Nivel() {
	//inicializamos  las variables para el reloj
	tempo = clock();
	paso = CLOCKS_PER_SEC/30;
	
	//inicializamos el valor de ancho y alto  para las barras laterales (pasto)
	anchoPasto = 29; 
	altoPasto = 24 ;

	y = 0;
	
}

//dibujamos las barras de pasto en pantalla 
//parametros posX y posY y almacena enteros que definen posicion en X e Y del pasto
void Nivel::dibujarPasto(int posx, int posy) {
	textcolor(WHITE);
	for(int i=0; i<altoPasto; i++){
		for(int j=0; j < anchoPasto ; j++){	
			textbackground(GREEN);
			gotoxy(j + posx, i + posy);
			std::cout<<char(176); 
		}
	}
}
//dibuja una barra horizontal negra en una altura Y 
//que se pasa como argumento al llamar a este metodo
//parametros posY guarda un entero que define posicion en Y de la barra negra
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

//Para dibujar el Borde lateral de la carretera, dibuja una barra marron cada vez que
// se la llama. parametros posX y PosY reciben enteros que define posicion en X e Y de la barra
void Nivel::bordeCarretera(int posx, int posy){
	for(int i=0; i<altoPasto; i++){
		textbackground(BROWN);
		gotoxy(posx, i + posy);
		std::cout<<" ";
	}
}
//metodo que dibuja  y anima una linea punteada blanca en medio de la carretera
//para dar la sensacion de movimiento
void Nivel::decoracionCarretera() {
	//dibujamos una linea blanca y la cortamos con una linea gris para
	//dar la sensacion de linea punteada
	
	if(y <3){ 
		for (int i = 4; i < 22; i+=3){ 
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
		}
		//aumentamos en Y para animar  la linea y dar la sensacion
		//de movimiento, si no no hace el efecto
		y++;
	}else {
		//cuando Y sobrepasa los limites de la carretera, reinicia el valor de Y
		y = 0;
	}
}

//dibuja los distintos elementos del nivel (pasto, barras horizontales, borde de la carretera)
void Nivel::dibujar(){
	dibujarPasto(1,3);
	dibujarPasto(87,3);
	dibujarBarraHorizontal(1);
	dibujarBarraHorizontal(27);
	bordeCarretera(30,3);
	bordeCarretera(86,3);
} 

//actualiza el objeto 
void Nivel::actualizar(){
	//actualiza las lineas de la carretera
	if( tempo + paso <clock()){
		decoracionCarretera();
		tempo = clock();
	}
}
