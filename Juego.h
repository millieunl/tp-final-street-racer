#ifndef JUEGO_H
#define JUEGO_H

#include<iostream>

#include "Ui.h"
#include "Nivel.h"
#include "Jugador.h"


class Juego {
public:

	Juego();   			//constructor
	~Juego();  			//destructor
	void jugar(); 		//esta funcion inicia el juego
	void eventos();
	
	
	
private:
	Jugador *jugador;
	Ui *ui;
	Nivel *nivel;
	
};

#endif

