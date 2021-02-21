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
	
	void setVidas(int vida);
	int getVidas();
	
private:
	clock_t tempo;
	clock_t paso;
	int puntaje;
	int vidas;
	
	void mostrarPuntaje();
	void mostrarVidas();
};

#endif

