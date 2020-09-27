#ifndef JUEGO_H
#define JUEGO_H

#include<iostream>

#include "Auto.h"
#include "Ui.h"

class Juego {
public:

	Juego();   			//constructor
	~Juego();  			//destructor
	void jugar(); 		//esta funcion inicia el juego
	void eventos();
	
	
	
private:
	Auto *auto1;			//objeto auto principal
	Ui *ui;
};

#endif

