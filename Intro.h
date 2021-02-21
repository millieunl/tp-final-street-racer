#ifndef INTRO_H
#define INTRO_H
#include <ctime>

class Intro {
public:
	Intro();
	~Intro();
	
	void actualizar();
	void mostraReglas();
	bool eventos();
	
	
private:
	clock_t tempo;
	clock_t paso;
};

#endif

