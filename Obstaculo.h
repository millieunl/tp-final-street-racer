#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "LotusPoni.h"
#include "Temporizador.h"
/** 
* CLASE OBSTACULO se utiliza para crear un obstaculo 
*deriva de la clase LotusPoni por que tiene comportamientos  
y caracteristicas similares.
No se aplica Polimorfismo aqui porque se considera que no es un vehiculo
*/

class Obstaculo :  public LotusPoni {
public:
	Obstaculo(int velocidad);
	~Obstaculo();

	//metodos publicos que hereda de LotusPoni y se redefinen aqui
	void actualizar();
	void chocar();
	
private:
	//para cronometrar cada cuanto aparece un obstaculo a la carretea
	Temporizador *temporizador;
	void mover();
	
};

#endif

