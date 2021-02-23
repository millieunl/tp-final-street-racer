#ifndef UI_H
#define UI_H
/**
*esta clase sirve para informar puntaje y vida al jugador/a
*/

//inlcuimos libreria necesaria
#include <ctime>

class Ui {
public:
	//contructor y destructor
	Ui();
	~Ui(){};
	
	//metodos
	void actualizar();
	void dibujar();
	
	void setPuntaje(int puntaje);
	int getPuntaje();
	void setVidas(int vida);
	int getVidas();
	
	
private:
	//atributos
	clock_t tempo;
	clock_t paso;
	int puntaje;
	int vidas;
	
	//metodos
	void mostrarPuntaje();
	void mostrarVidas();
};

#endif

