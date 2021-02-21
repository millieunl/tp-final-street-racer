#include "Intro.h"
#include <conio2.h>
#include<iostream>

Intro::Intro() {
	
}

Intro::~Intro() {
	
}

void Intro::mostraReglas(){
	
	textcolor(LIGHTGREEN);
	gotoxy(25,3);
	std::cout<<"<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>";
	gotoxy(25,4);
	std::cout<<"<<  __   __   ___  ___  __     __        __   ___  __     >>"<<std::endl;
	gotoxy(25,5);
	std::cout<<"<< /__` |__) |__  |__  |  "<<char(92)<<"   |__)  /"<<char(92)<<"  /  ` |__  |__)    >>"<<std::endl;
	gotoxy(25,6);
	std::cout<<"<<.__/  |    |___ |___ |__/   |  "<<char(92)<<" /~~"<<char(92)<<" "<<char(92)<<"__, |___ |  "<<char(92)<<"    >>"<<std::endl;
	gotoxy(25,7);
	std::cout<<"<<                                                        >>";
	gotoxy(25,8);
	std::cout<<"<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>";
	
	
	textcolor(LIGHTCYAN);
	gotoxy(18,10);
	std::cout<<"BIENVENIDO/A A SPEED RACER CORREDOR/A. Comienza esta alocada carrera de autos!"<<std::endl;
	
	for (int i = 0;i<110;i++){
		textcolor(rand()%6 +10);
		gotoxy(1+i,12);
		std::cout<<"*";
	}
	textcolor(YELLOW);
	gotoxy(1,13);
	std::cout<<char(173)<<"Como se juega?"<<std::endl;
	
	textcolor(WHITE);
	gotoxy(1,15);
	std::cout<<"- * - Tu auto se desplaza hacia los costados con las teclas izquierda y derecha del teclado."<<std::endl;
	std::cout<<"- * - esquiva a los enemigos y obstaculos para llegar lo mas lejos que puedas."<<std::endl;
	std::cout<<"- * - Atencion que cada enemigo sorteado suma puntaje!"<<std::endl;
	std::cout<<"- * - "<<char(173)<<"Ten cuidado, chocar enemigos y osbtaculos en el camino te quitara vidas!"<<std::endl;
	std::cout<<"- * - Si te quedas sin vidas... pierdes este juego."<<std::endl;
	std::cout<<"- * - Para no perder, esquiva los enemigos Trueno Loco y con Lotus Poni y a los obstaculos."<<std::endl;
	std::cout<<"- * - Esquivalos, "<<std::endl;
	std::cout<<"- * -"<<char(173)<<"Mas desafiante! Cada 20 puntos los obstaculos y enemigos sorteados obtendran mayor velocidad! "<<std::endl;
	for (int i = 0;i<110;i++){
		textcolor(rand()%6 +10);
		gotoxy(1+i,24);
		std::cout<<"*";
		
	}
	gotoxy(1,25);
	textcolor(WHITE);
	std::cout<<"- * -Hace calor, el sol quema el asfalto, puedes sentir los motores en marcha. "<<std::endl;
	textcolor(LIGHTMAGENTA);
	std::cout<< "----> Estas preparado/a para comenzar?  Presiona ENTER CUANDO ESTES LISTO/A?<----"<<std::endl;
	
}

void  Intro::actualizar(){
	while(true){
		mostraReglas();
		if(eventos()) break;
	}	
}
bool Intro::eventos(){
	if (kbhit()){
		int tecla = getch(); //captura la tecla que se presiona
		if(tecla == 13){
			return true;
		}else{
			std::cout<<"otra tecla, no pasa nada"<<std::endl;
			return false;
		}
	}
}


