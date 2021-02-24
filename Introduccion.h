#ifndef INTRODUCCION_H
#define INTRODUCCION_H
#include <ctime>
/**
*esta clase se usa para genrar la introduccion del juego que muestra
da la bienvenida y muestra las reglas del juego
Captura evento del teclado que sirve para pasar a la siguiente pantalla
*/
class Introduccion {
public:
	Introduccion(){};
	~Introduccion(){};
	
	//metodos
	void actualizar();
	
private:
	//metodos
	void mostraReglas();
	bool eventos();	
};

#endif

