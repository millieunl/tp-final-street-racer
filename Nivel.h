#ifndef NIVEL_H
#define NIVEL_H

//inclimos libreria para trabajar con el tiempo
#include <ctime>

/**
* Esta clase se usa para armar el escenario/nivel del Juego
* arma una ruta con una linea punteada y bordes rodeada de pasto
* lleva la cuenta del nivel actual
*/
class Nivel {
public:
	//contructor y destructor
	Nivel();
	~Nivel(){};
	
	//metodos publicos
	void actualizar();
	void dibujar();
	void subirNivel();
	void reset();
	int getNivel();
	
private:
	//atributos
	int altoPasto;
	int anchoPasto;
	int y;
	int nivel;
	
	//variables para medir el tiempo 
	clock_t tempo;
	clock_t paso;
	
	//metodos, todos reciben argumentos que son posicion x e Y 
	void dibujarPasto(int posx, int posy); 
	void dibujarBarraHorizontal(int posy);
	void bordeCarretera(int posx, int posy);
	void decoracionCarretera();
	
};

#endif

