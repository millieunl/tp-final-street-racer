#ifndef UI_H
#define UI_H
#include <conio2.h>
#include <ctime>

class Ui {
public:
	Ui();
	~Ui();
	
	void actualizar();
	void dibujar();
	void setPuntaje(int puntaje);
	int getPuntaje();
	void mostrarPuntaje();
	
private:
	clock_t tempo;
	clock_t paso;
	int puntaje;
};

#endif

