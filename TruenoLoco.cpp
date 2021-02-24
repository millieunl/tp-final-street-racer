#include "TruenoLoco.h"
#include <conio2.h>

//contructor
TruenoLoco::TruenoLoco(int velocidad): Vehiculo(velocidad) {	
	//dibujo del auto Trueno Loco
	armarAuto();
	reset();	
}


//Carga el modelo y color del TruenoLoco
void TruenoLoco::armarAuto(){
	
	//cargamos matriz con codigo de los caracteres ascii  para el modelo del auto
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
	
	//carga la matriz con los colores del auto de TruenoLoco
	//El auto es principalmente ROJO
	color[0][0] = 0;  //rueda es negra
	color[0][1] = 0;
	color[0][2] = 12;  //punta es Roja
	color[0][3] = 0;
	color[0][4] = 0;   //rueda es negra
	color[1][0] = 0;
	color[1][1] = 12;   //costado izq
	color[1][2] = 4;   //cabina es rojo oscuro
	color[1][3] = 12;   //costado dere
	color[1][4] = 0;
	color[2][0] = 0;    //rueda es negra
	color[2][1] = 0;
	color[2][2] = 12;    //cola es rojo
	color[2][3] = 0;
	color[2][4] = 0;    //rueda es negra
}
//actualiza el objeto en  posicion y dibujo
void TruenoLoco::actualizar(){
	if(tempo + paso < clock()) {		
		mover();
		dibujar();
		tempo = clock();
	}
}

//reinicia la posicion de donde sale TruenoLoco y redefine una direccion random
void TruenoLoco::reLanzar(){
	borrar();
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	y = 3;
	direccion = rand()% 2;
}


//se llama en el metodo actualizar, mueve el auto ,avanza en diagonal
//verificando que esté dentro de la carretera  y regulando las direcciones
void TruenoLoco:: mover(){
	//si el auto esta dentro de la carretea definimos como se mueve
	if( y + alto < maxLimiteY ){
		//
		if( direccion == 0 ) moverDiagonalIzquierda();
		else moverDiagonalDerecha();
		y++;
	}else{
		//si salio de pantalla, relanza el  y suma una vuelta
		reLanzar();
		contadorVueltas+=1;
	}
}
//realiza la logica para avanzar diagonalmente hacia la derecha
void TruenoLoco::moverDiagonalDerecha(){
	//si el auto NO choca el limite derecho de la carretera puede avanzar en X
	if( y + alto < maxLimiteY && x + ancho <= maxLimiteX){
		borrar();
		x++;
	}else{
		//sino, si el auto choca con el limite derecho, cambia la direccion a la izquierda
		borrar();
		direccion = 0; //0 es direccion a la izquierda
	}
}
//realiza la logica para avanzar diagonalmente hacia la izquierda
void TruenoLoco::moverDiagonalIzquierda(){
	//si el auto NO choca el limite izquierdo de la carretera sigue direccion en X
	if( y + alto < maxLimiteY && x  > minLimiteX){
		borrar();
		x--;
	}else{
		//sino, si el auto choca con el limite izquierdo, cambia direccion a la derecha
		borrar();
		direccion = 1; //1 cambia direccion hacia derecha
	}
}

//este metodo se llama en la clase Juego, para cuando se detecta un choque entre 
//TruenoLoco y otro vehiculo/obstaculo sirve para relanzar a este auto
void TruenoLoco::chocar(){
	reLanzar();
}

//devuleve la cantodad de vueltas que pudo dar truenoLoco
int TruenoLoco::getVueltas(){
	return contadorVueltas;
}

// gestiona la aceleracion del TruenoLoco
void TruenoLoco::acelerar(){
	velocidad += 2;
	paso = CLOCKS_PER_SEC/velocidad;
}

//resetea las variables por defecto de TruenoLoco para posicionar, definir velocidad, reloj, direccion y vueltas
void TruenoLoco::reset(){
	//setea las posicion en X e Y
	x = minLimiteX + ( rand() % (( maxLimiteX - ancho)- minLimiteX + 1 ) );
	y = 3;
	
	//inicializa contadores
	contadorVueltas = 0;

	// elige direccion al azar entre 0 y 1 (0 izq, 1 der)
	direccion = rand()% 2;
	
	//velocidad inicial de truenoLoco 
	velocidad = velocidadInicial;
	tempo = clock();
	paso = CLOCKS_PER_SEC/velocidad;
	

}
