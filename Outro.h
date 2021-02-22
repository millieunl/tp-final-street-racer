#ifndef OUTRO_H
#define OUTRO_H

class Outro {
public:
	Outro();
	~Outro();
	
	void actualizar();
	
private:
	int x;
	bool quiereSalir;
	void mostrarMenu();
	void mostrarMensaje();
	bool eventos();
	
};

#endif

