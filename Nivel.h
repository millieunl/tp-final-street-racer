#ifndef NIVEL_H
#define NIVEL_H
#include <ctime>


class Nivel {
public:
	Nivel();
	void actualizar();
	void dibujar();
	
private:
	int alto;
	int ancho;
	clock_t tempo;
	clock_t paso;
	void dibujarPasto(int posx, int posy);
	void dibujarBarraHorizontal(int posy);
	void bordeCarretera(int posx, int posy);
	void decoracionCarretera();
};

#endif

