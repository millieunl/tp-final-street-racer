#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H
#include <time.h>
class Temporizador {
public:
	Temporizador();
	~Temporizador();
	//time_t tiempo_actual;
	time_t tiempo_deseado;
	void iniciar(time_t td);
	bool tiempocumplido();
private:
};

#endif

