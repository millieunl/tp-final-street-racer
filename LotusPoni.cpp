#include "LotusPoni.h"
#include <conio2.h>

//contructor
LotusPoni::LotusPoni(int velocidad): Vehiculo(velocidad) {	
	armarAuto();
	reset();
}

//Carga el modelo y color del LotusPoni
void LotusPoni::armarAuto(){
	//cargar matriz con codigo de los caracteres ascii  para el modelo del auto
	matriz[0][0] = 219;
	matriz[0][1] = 205;
	matriz[0][2] = 178;
	matriz[0][3] = 205;
	matriz[0][4] = 219;
	matriz[1][0] = ' ';
	matriz[1][1] = 47;
	matriz[1][2] = 219;
	matriz[1][3] = 92;
	matriz[1][4] = ' ';
	matriz[2][0] = 219;
	matriz[2][1] = 205;
	matriz[2][2] = 178;
	matriz[2][3] = 205;
	matriz[2][4] = 219;
	
	//carga la matriz con los colores del auto de LotusPoni
	//es AMARILLO
	color[0][0] = 0;  //rueda es negra
	color[0][1] = 0;
	color[0][2] = 14;  //punta es amarilla
	color[0][3] = 0;
	color[0][4] = 0;   //rueda es negra
	color[1][0] = 0;
	color[1][1] = 15;   //costado izq
	color[1][2] = 6;   //cabina es marron
	color[1][3] = 15;   //costado dere
	color[1][4] = 0;
	color[2][0] = 0;    //rueda es negra
	color[2][1] = 0;
	color[2][2] = 14;    //cola es amarilla
	color[2][3] = 0;
	color[2][4] = 0;    //rueda es negra
}

//actualiza el objeto en  posicion y dibujo
void LotusPoni::actualizar(){
	if(tempo + paso < clock()) {		
		mover();
		dibujar();
		tempo = clock();
	}
}

//reinicia la posicion de donde sale LotusPoni
void LotusPoni::reLanzar(){
	borrar();
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ));
	y = 3;
}

//se llama en el metodo actualizar, mueve este auto 
//verificando que esté dentro de la carretera y avanza el linea recta hacia abajo(y++)
void LotusPoni:: mover(){
	if (y + alto < maxLimiteY){
		borrar();
		y++;;
	}else {
		reLanzar();
		contadorVueltas+=1;
	}
	
}

//este metodo se llama en la clase Juego, para cuando se detecta un choque entre 
//LotusPoni y otro vehiculo/obstaculo, sirve para relanzar el auto
void LotusPoni::chocar(){
	reLanzar();
}

//este metodo acelera a LotusPoni y verifica que solo acelere una vez
void LotusPoni::acelerar(){
	if(contadorVueltas== contadorInicial)  return;
	contadorInicial=contadorVueltas;
	velocidad += 2;
	paso = CLOCKS_PER_SEC/velocidad;
}

//devuleve la cantidad de vueltas dadas hasta el momento
int LotusPoni::getVueltas(){
	return contadorVueltas;
}

//resetea las variables por defecto de LotusPoni para posicionar, definir velocidad, reloj y vueltas
void LotusPoni::reset(){
	//seta x e Y
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	y = 3;
	
	//inicializa contadores
	contadorVueltas = 0;
	contadorInicial = 0;	

	//velocidad inicial de lotusPoni
	velocidad = velocidadInicial;
	//inicializa reloj
	paso = CLOCKS_PER_SEC/velocidad;
	tempo = clock();
	
}
