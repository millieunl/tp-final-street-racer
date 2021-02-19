#include "Temporizador.h"

Temporizador::Temporizador() {
	
}

void Temporizador::iniciar(time_t td){
	//tiempo_actual = clock();
	tiempo_deseado = clock() + td;
}

bool Temporizador::tiempocumplido(){
	if(clock() > tiempo_deseado) return true;
	else return false;
}

Temporizador::~Temporizador() {
	
}

