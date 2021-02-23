#ifndef NIVEL_H
#define NIVEL_H

//inclimos libreria para trabajar con el tiempo
#include <ctime>

/**
* Esta clase se usa para armar el escenario del Juego
* arma una ruta con una linea punteada y bordes rodeada de pasto
*/
class Nivel {
public:
	//contructor y destructor
	Nivel();
	~Nivel(){};
	
	//metodos publicos
	void actualizar();
	void dibujar();
	
private:
	//atributos
	int altoPasto;
	int anchoPasto;
	int y;
	
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

