#include "Temporizador.h"

//contructor
Temporizador::Temporizador() {
	//inicializa la variable tiempo deseado
	tiempo_deseado = 0;
}

//recibe como parametro la cantidad de milisegundos que se quiere medir
void Temporizador::iniciar(time_t td){
	tiempo_deseado = clock() + td;
}
//metodo que devuelve true si el tiempo deseado ya se cumplio
bool Temporizador::tiempocumplido(){
	if(clock() > tiempo_deseado) return true;
	else return false;
}


