#ifndef JUGADOR_H
#define JUGADOR_H
/**
* Esta clase deriva de Vehiculo para crear al vehiculo del jugador
* que hereda metodos virtuales  y atributos comunes. Algunos los redefine para si misma.
* Tiene metodos  para definir comportamientos  propios como
como los del movimiento hacia derecha o izquierda o los del efecto del choque
*/

//incluimos los encabezados de las clases que necesitamos usar
//encabezado de la clase base
#include "Vehiculo.h"
//encabezado de la clase para medir tiempo
#include "Temporizador.h"

class Jugador : public Vehiculo{
public:
	//constructor y destructor
	Jugador(int velocidad);
	~Jugador();
	
	//metodos que se heredan de Vehiculo y se define en esta clase sus comportamientos
	void actualizar();
	void chocar();
	void reset();
	void mover();
    
	//metodos que no redefinimos aca
	int getVueltas(){return 0;};
	void acelerar(){};
	
private:
	//atributos y objetos de esta clase
	bool estaParpadeando;
	void romperAuto();
	
	//esta clase lo usa para medir la duracion del efecto de chocar
	Temporizador *temporizador;
	
	//metodos que definen comportamientos propios para esta clase
	void moverIzquierda();
	void moverDerecha();
	void colorearAuto();
	void parpadear();
	void choqueFx();
	
	//metodos heredados y que redefino aqui para darle forma al auto del jugador
	void armarAuto();
	
};

#endif

