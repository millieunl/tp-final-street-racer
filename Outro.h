#ifndef OUTRO_H
#define OUTRO_H

class Outro {
public:
	Outro();
	~Outro();
	
	void actualizar();
	void setPuntaje(int puntaje);
	void reset();
	bool getQuiereSalir();
	
private:
	int x;
	bool quiereSalir;
	bool capturando;
	void mostrarMenu();
	void mostrarMensaje();
	bool eventos();
	int puntaje;
	
	 
	
};

#endif

