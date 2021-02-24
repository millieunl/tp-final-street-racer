#ifndef EPILOGO_H
#define EPILOGO_H

/**
* esta clase se usa para mostrar un mensaje de salida del juego
informa que se perdio el juego, muestra el puntaje alcanzado
y pregunta por si se quiere seguir jugando
*/
class Epilogo {
public:
	Epilogo(int puntaje);
	~Epilogo(){};
	
	//metodos publicos
	void actualizar();
	void setPuntaje(int puntaje);
	void reset();
	bool getQuiereSalir();
	void mostrarDespedida();
	
private:
	//atributos
	int puntaje;
	
	//metodos
	bool quiereSalir;
	bool capturando; //se usa para saber cuando caputuro el evento ENTER
	bool eventos();
	void mostrarMenu();
	void mostrarMensaje();
	
};

#endif

