#ifndef UI_H
#define UI_H
/**
*esta clase sirve para informar puntaje, nivel y vida al jugador/a
*/

//inlcuimos libreria necesaria
#include <ctime>

class Ui {
public:
	//contructor y destructor
	Ui(int vidas, int nivel);
	~Ui(){};
	
	//metodos
	void actualizar();
	void dibujar();
	void reset();
	
	void setPuntaje(int puntaje);
	void setVidas(int vida);
	void subirNivel();
	int getPuntaje();
	void setNivel(int nivel);
	
private:
	//atributos
	clock_t tempo;
	clock_t paso;
	int puntaje;
	int vidas;
	int nivel;
	int puntajeInicial;
	
	//metodos
	void mostrarPuntaje();
	void mostrarVidas();
	void mostrarNivel();
};

#endif

