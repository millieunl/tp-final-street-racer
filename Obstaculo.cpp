#include "Obstaculo.h"



Obstaculo::Obstaculo(int velocidad) : LotusPoni(velocidad){
	
	temporizador = new Temporizador();
	
	//como minimo sale cada 5 seg y como maximo 7
	temporizador->iniciar(rand()% 2000 + 5000);

	/*cargamos cada  posicion de la matriz con los caracteres para dibujar el obstaculo
	Forma del Obstaculo:
	_____
	¦   ¦
	¯   ¯
	*/
	matriz[0][0] = 220; 
	matriz[0][1] = 220;
	matriz[0][2] = 220;
	matriz[0][3] = 220;
	matriz[0][4] = 220;
	matriz[1][0] = 219; //pata izquierda
	matriz[1][1] = 223;
	matriz[1][2] = 223;
	matriz[1][3] = 223;
	matriz[1][4] = 219; //pata derecha
	matriz[2][0] = 223; //pie izq
	matriz[2][1] = ' ';
	matriz[2][2] = ' ';
	matriz[2][3] = ' ';
	matriz[2][4] = 223; //pie der
	
	//carga la matriz con los colores para el obstaculo
	//es AMARILLO Y NEGRO
	color[0][0] = 0;   //negro
	color[0][1] = 14;   //amarillo
	color[0][2] = 0; 
	color[0][3] = 14;
	color[0][4] = 0;   
	color[1][0] = 14;   //para izq
	color[1][1] = 0;   
	color[1][2] = 14;   
	color[1][3] = 0;   
	color[1][4] = 14;    //pata der
	color[2][0] = 0;    
	color[2][1] = 0;
	color[2][2] = 0;    
	color[2][3] = 0;
	color[2][4] = 0;    
	
}

//destuctor
Obstaculo::~Obstaculo() {
	delete temporizador;
}

//este metodo permite mover al osbtaculo en linea recta en Y
//cuando esta dentro de la carretera
//cuando el obstaculo "termina de pasar vivo" cuenta una vuelta
//reinicia un temporizador que regula cuando vuelve a aparecer
void Obstaculo:: mover(){
	//si esta dentro de la carretera
	if(y + alto < maxLimiteY){
		borrar();
		y++;
	//si llega al fin de lac carreta	
	}else{
		reLanzar();
		contadorVueltas+=1;
		//aqui reinicia el temporizados en un tiempo random en milisegundos entre 5  min y 7 max
		temporizador->iniciar(rand()% 2000 + 5000);
	}
}
//este metodo actualiza el objeto 
//llama a mover() cuando se cumple un tiempo determinado y luego dibuja
void Obstaculo::actualizar(){
	
	if(tempo + paso < clock()){
		if(temporizador->tiempocumplido()){
			mover();
			//fix para que no se dibuje antes que se cumpla el tiempo
			if(temporizador->tiempocumplido()){
				dibujar();
			}
		}
		tempo = clock();
	}
}

//este metodo se llama desde la clase juego cuando choca un vehiculo con el obstaculo
//solo relanza el obstaculo si paso un determinado tiempo
//reinicia el temporizador para volver a medir el tiempo 
void Obstaculo::chocar(){
	if(temporizador->tiempocumplido())reLanzar();
	temporizador->iniciar(rand()% 2000 + 5000);
}


