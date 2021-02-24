#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H
#include <time.h>

/**
Esta clase se usa como cronometro 
para medir el tiempo para lanzar algun efecto
*/
class Temporizador {
public:
	//constructor y destructor
	Temporizador();
	~Temporizador(){};
	
	//atributos
	time_t tiempo_deseado;
	
	//metodos
	void iniciar(time_t td); 
	bool tiempocumplido();
private:
};

#endif

