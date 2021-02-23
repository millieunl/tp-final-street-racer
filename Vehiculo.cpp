#include "Vehiculo.h"
#include <conio2.h>

//contructor que inicializa las variables con valores comunes para todas las derivadas
Vehiculo::Vehiculo() {
	
	//guardamos el ancho y alto de la matriz (ancho y alto del auto)
	ancho = 5; 
	alto = 3; 
	
	//limites maximos y minimos para x e y, sirven para limitar el movimiento de los autos
	maxLimiteX = 85;
	minLimiteX = 31;
	maxLimiteY = 27;
	minLimiteY = 1;
}

//recorre con un for las matrices para dibujar y colorear un vehiculo
void Vehiculo::dibujar(){
	for(int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++){
			textbackground(DARKGRAY);
			textcolor(color[i][j]);
			gotoxy(x+j,y+i);
			std::cout<<char(matriz[i][j]);
		}
		std::cout<<std::endl;
	}
}

//borra un vehiculo, se usa para borrar el rastro que deja mover el vehiculo en X,Y
//agrega un caracter vacio en la coordenada X,Y donde esta el vehiculo actualmente
void Vehiculo::borrar(){
	for(int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			textbackground(DARKGRAY);
			gotoxy(x+j,y+i);
			std::cout<<" ";
		}
	}
}

//setter y getters
//se usa para setear la posicion de un vehiculo en X e Y
void Vehiculo::setPosicion(int x, int y){
	this -> x = x;
	this -> y = y;
}

//devuelve el ancho del auto
int Vehiculo::getAncho(){
	return ancho;
}

//devuelve el alto del auto
int Vehiculo::getAlto(){
	return alto;
}

//devuelve la poscion X del auto
int Vehiculo::getX(){
	return x;
}

//devuelve la posicion Y del auto
int Vehiculo::getY(){
	return y;
}

//devuelve las vidas del conductor del auto
int Vehiculo::getVidas(){
	return vidas;
}




