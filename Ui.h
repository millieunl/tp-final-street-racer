#ifndef UI_H
#define UI_H
#include <conio2.h>
#include <ctime>

class Ui {
public:
	Ui();
	~Ui();
	clock_t tempo;
	clock_t paso;
	int alto;
	int ancho;
	int puntaje;
	void actualizar();
	void dibujar();
	void barrasLaterales();
	void carretera();
	void setPuntaje(int puntaje);
	int getPuntaje();
	void mostrarPuntaje();
private:
};

#endif

