#include "Jugador.h"
#include <conio2.h>

//constructor
Jugador::Jugador(int velocidad) : Vehiculo(velocidad){
	temporizador = new Temporizador();
	armarAuto();
	reset();
}

//metodo para armar  auto completo con su modelo y color
void Jugador::armarAuto(){
	/* cargamos la matriz para el modelo del auto del jugador
	los numeros son codigos de caracteres ascii extended.
	Modelo del auto:
	¦-¦-¦
	 /¦\
	¦-¦-¦
	*/
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
	
	//carga la matriz para colorear el auto del jugador
	colorearAuto();
}

//esta funcion carga en cada posicion de una matriz codigos de color de conio2
//que sirve para colorear cada parte del auto
void Jugador::colorearAuto(){
	//carga la matriz con los colores del auto del jugador
	color[0][0] = 0;  //rueda negra
	color[0][1] = 0;   
	color[0][2] = 13;  //punta magenta
	color[0][3] = 0;
	color[0][4] = 0;   //rueda negra
	color[1][0] = 0;
	color[1][1] = 13;   //costado izq magenta
	color[1][2] = 5;   //cabina rosa oscuro
	color[1][3] = 13;   //costado dere magenta
	color[1][4] = 0;
	color[2][0] = 0;    //rueda negra
	color[2][1] = 0;
	color[2][2] = 13;    //cola magenta
	color[2][3] = 0;
	color[2][4] = 0;    //rueda negra
}

//carga en la matriz caracteres que dan la ilusion de que el auto se rompio
//se usa para el efecto de auto roto en el choque
void Jugador::romperAuto(){
	//cargar matriz con el modelo del auto  roto
	matriz[0][0] = 219;  //rueda
	matriz[0][1] = 205;
	matriz[0][2] = 219;
	matriz[0][3] = 205;
	matriz[0][4] = 254;   //rueda
	matriz[1][0] = ' ';
	matriz[1][1] = ' ';
	matriz[1][2] = 177;    //cabina
	matriz[1][3] = ' ';
	matriz[1][4] = 47;
	matriz[2][0] = 223;   //rueda
	matriz[2][1] = 205;
	matriz[2][2] = 219;
	matriz[2][3] = 205;
	matriz[2][4] = 220;  //rueda
}

//
void Jugador::actualizar(){
	//mide el tiempo para actualizar
	if(tempo + paso < clock()) {		
		//dibuja al auto(recorriendo la matriz con el modelo y color)
		dibujar();
		//efecto para el choque
		if(estaParpadeando){
			choqueFx();
		}
		tempo = clock();
	}
}


//Carga la matriz de colores del auto con codigos de color Random se usa 
// para crear un parpadeo de color  que se usara cuando choque
void Jugador::parpadear(){
	for(int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++){
			color[i][j]= rand()% 15;
		}
	}
}

//Metodo que hace el efecto de choque completo de parpadeo de color y rotura del auto
void Jugador::choqueFx(){
	parpadear();
	romperAuto();
	
	//verifica el tiempo para apagar el parpadeo y armar el auto cuando cumple el tiempo deseado
	if(temporizador->tiempocumplido()){
		estaParpadeando = false;
		armarAuto();
	}
}

//prepara las variables para mostrar el efecto del choque
//se debe llamar cuando se detecta colision del jugador con algun enemigo/obstaculo
void Jugador:: chocar(){
	borrar();
	temporizador->iniciar(1000);
	estaParpadeando = true;
	vidas--;
}

//sirve para mover el auto en X hacia la derecha segun el limite derecho de la pista
void Jugador::moverDerecha() {
	if(x + ancho  <= maxLimiteX) {
		borrar(); 
		x++;
	}
}

//Mueve al auto en X hacia la izquierda segun el limite izquierdo de la pista
void Jugador::moverIzquierda() {
	if(x > minLimiteX ){
		borrar(); 
		x--;
	}
}

//esta funcion determina el movimiento de del vehiculo
//llama a funcion mover derecha o izquierda el auto segun la tecla que se capture 
//implementando deteccion de evento de teclado
void Jugador:: mover(){
	if(kbhit()){
		//captura la tecla que se presiona
		int tecla = getch(); 
		switch(tecla) {
			//derecha
		case 67:
		case 77:
			//llama funcion para moverse a la derecha
			moverDerecha();
			break;
			//izquierda
		case 68:
		case 75:
			//llama funcion para moverse a la izquierda
			moverIzquierda();
			break;
		}
	}
}

//reinicia/resetea las variables por defecto para el inicio o reinicio del juego
void Jugador::reset(){
	velocidad = velocidadInicial;  
	tempo = clock();
	paso = CLOCKS_PER_SEC/velocidad;
	estaParpadeando = false;
	vidas = 3;
	x = 31;
	y = 23;
}

//destructor de clase
Jugador::~Jugador() {
	delete temporizador;
}
