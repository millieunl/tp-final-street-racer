#ifndef JUEGO_H
#define JUEGO_H

#include<iostream>

#include "Ui.h"
#include "Nivel.h"
#include "Jugador.h"
#include "LotusPoni.h"
#include "TruenoLoco.h"
#include "Vehiculo.h"


class Juego {
public:

	Juego();   			//constructor
	~Juego();  			//destructor
	
	void jugar(); 		//esta funcion inicia el juego
	
	
	
private:
	//Jugador *jugador;
	Vehiculo *jugador;
	Vehiculo *lotusPoni;
	Vehiculo *truenoLoco;
	Ui *ui;
	Nivel *nivel;
	
	bool chocoTrueno;
	bool chocoLotus;
	
	//metodos
	void eventos();
	bool hayColision( Vehiculo *v1, Vehiculo *v2);
	
};

#endif

