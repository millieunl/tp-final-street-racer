#ifndef JUEGO_H
#define JUEGO_H

//incluimos los encabezados de las clases 
#include "Ui.h"
#include "Nivel.h"
#include "Vehiculo.h"
#include "Intro.h"
#include "Outro.h"
#include "Obstaculo.h"
class Juego {
public:

	Juego();   			//constructor
	~Juego();  			//destructor	
	//metdodo que lanza todo el juego, es publico por que se llama desde main
	void jugar(); 		//esta funcion inicia el juego
	
private:
	//atributos
	//punteros Vehiculo que apunta a la clase base, pero  luego referencia a las derivadas
	Vehiculo *jugador;
	Vehiculo *lotusPoni;
	Vehiculo *truenoLoco;
	Obstaculo *obstaculo;
	
	//
	Ui *ui;
	Nivel *nivel;
	Intro *intro;
	Outro *outro;
	
	//metodos
	void actualizar();
	void eventos();
	void lanzarIntro();
	void lanzarOutro();
	void reiniciar();
	void detectarColision(Vehiculo *v1, Obstaculo *obs);
	void detectarColision(Vehiculo *v1, Vehiculo *v2);
	bool hayColision( Vehiculo *v1, Vehiculo *v2);
	bool hayColision(Vehiculo *v1, Obstaculo *obs);
	
};

#endif

