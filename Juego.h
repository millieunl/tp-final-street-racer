#ifndef JUEGO_H
#define JUEGO_H

#include<iostream>

#include "Ui.h"
#include "Nivel.h"
#include "Jugador.h"
#include "LotusPoni.h"
#include "TruenoLoco.h"



class Juego {
public:

	Juego();   			//constructor
	~Juego();  			//destructor
	
	void jugar(); 		//esta funcion inicia el juego
	
	
	
private:
	Jugador *jugador;
	LotusPoni *lotusPoni;
	TruenoLoco *truenoLoco;
	Ui *ui;
	Nivel *nivel;
	
	bool chocoTrueno;
	
	//metodos
	void eventos();
	bool hayColision( int ancho, int alto, int x0, int y0, int x1, int y1);
	
};

#endif

