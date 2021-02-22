#ifndef INTRO_H
#define INTRO_H
#include <ctime>

class Intro {
public:
	Intro();
	~Intro();
	
	//metodos
	void actualizar();
	
	
	
private:
	//metodos
	void mostraReglas();
	bool eventos();
	
	clock_t tempo;
	clock_t paso;
};

#endif

