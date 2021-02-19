#include "LotusPoni.h"


LotusPoni::LotusPoni() {
	//posiciona el auto del enemigo en una posicion fija en "Y" pero random en "X"
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	y = 3;

	tempo = clock();
	paso = CLOCKS_PER_SEC/5;
	
	//carga la matriz con los colores del auto del enemigo LotusPoni
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

void LotusPoni::actualizar(){
	if(tempo + paso < clock()) {
		mover();
		dibujar();
		tempo = clock();
	}
}

void LotusPoni:: mover(){
	if (y + alto < maxLimiteY){
		borrar();
		y++;;
	}else {
		borrar();
		setPosicion(minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) ),3);
		
	}
	
}
LotusPoni::~LotusPoni() {
	
}

