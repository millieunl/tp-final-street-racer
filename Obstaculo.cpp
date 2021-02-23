#include "Obstaculo.h"



Obstaculo::Obstaculo() {
	
	temporizador = new Temporizador();
	//como minimo sale cada 5 seg y como maximo 7
	temporizador->iniciar(rand()% 2000 + 5000);
	
	//armarAuto();
	matriz[0][0] = 220;
	matriz[0][1] = 220;
	matriz[0][2] = 220;
	matriz[0][3] = 220;
	matriz[0][4] = 220;
	matriz[1][0] = 219; //para izquierda
	matriz[1][1] = 223;
	matriz[1][2] = 223;
	matriz[1][3] = 223;
	matriz[1][4] = 219; //para derecha
	matriz[2][0] = 223; //pie izq
	matriz[2][1] = ' ';
	matriz[2][2] = ' ';
	matriz[2][3] = ' ';
	matriz[2][4] = 223; //pie der
	
	//carga la matriz con los colores para el obstaculo
	//es AMARILLO
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

Obstaculo::~Obstaculo() {
	delete temporizador;
}

void Obstaculo:: mover(){
	//si esta dentro de la carretera
	if(y + alto < maxLimiteY){
		borrar();
		y++;
	//si llega al fin de lac carreta	
	}else{
		reLanzar();
		contadorVueltas+=1;
		temporizador->iniciar(rand()% 2000 + 5000);
	}
}

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

void Obstaculo::chocar(){
	
	if(temporizador->tiempocumplido())reLanzar();
	temporizador->iniciar(rand()% 2000 + 5000);
}


