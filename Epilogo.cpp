#include "Epilogo.h"
#include <conio2.h>
#include<iostream>

//contructor
Epilogo::Epilogo() {
	//inicializa variables
	reset();
}

//metodo que resetea todas las variables a valores por defecto
void Epilogo::reset(){
	x = 0;
	puntaje = 0;
	quiereSalir = false;	
	capturando = true;
}

//actualiza la escena mientras
void Epilogo::actualizar(){
	mostrarMenu();
	while(capturando){
		mostrarMensaje();  //informa que se perdio el juego
		eventos();
	}
}

//setea el puntaje alcanzado, recibe un entero
void Epilogo::setPuntaje(int puntaje){
	this ->puntaje = puntaje;
}


//devuelve TRUE si se eligio la opcion SALIR DEL JUDEGO por el teclado
// devuelve FALSE si quiere REINICIAR
bool Epilogo::getQuiereSalir(){
	return quiereSalir;
}

//muestra el titulo y puntaje obtenido y una linea de colores
void Epilogo::mostrarMensaje(){
	//titulo con el nombre del juego
	textcolor(LIGHTGREEN);
	gotoxy(30,5);
	std::cout<<"<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>";
	gotoxy(30,6);
	std::cout<<"<<   __              ___     __        ___  __    >>"<<std::endl;
	gotoxy(30,7);  
	std::cout<<"<<  / _`  /"<<char(92)<<"   |"<<char(92)<<"/| |__     /  "<<char(92)<<" "<<char(92)<<"  / |__  |__)   >>"<<std::endl;
	gotoxy(30,8);
	std::cout<<"<<  "<<char(92)<<"__> /~~"<<char(92)<<"  |  | |___    "<<char(92)<<"__/  "<<char(92)<<"/  |___ |  "<<char(92)<<"   >>"<<std::endl;
	gotoxy(30,9);
	std::cout<<"<<                                                >>";
	gotoxy(30,10);
	std::cout<<"<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>";
	
	gotoxy(30,12);
	std::cout<<"Has obtenido "<<puntaje<<" puntos en esta carrera!!";
	
	//linea de color
	for (int i = 0;i<100;i++){
		textcolor(rand()%6 +10);
		gotoxy(6+i,15);
		std::cout<<"*";
	}
}

//muestra el menu con los botones para salir o seguir jugando
void Epilogo::mostrarMenu(){
	textcolor(YELLOW);
	gotoxy(45,17);
	std::cout<< "Quieres volver a jugar?"<<std::endl;
	textcolor(LIGHTGREEN);
	gotoxy(1,19);
	std::cout<< ">> Selecciona una opcion con las teclas [IZQUIERDA] o [DERECHA] y presiona [ENTER] para aceptar <<"<<std::endl;
	
	//botones
	//por defecto aparece este "resaltado"
	gotoxy(18,22);
	textcolor(YELLOW);
	std::cout<< "------------------------"<<std::endl;
	gotoxy(19,23);
	textcolor(LIGHTMAGENTA);
	std::cout<< "QUIERO JUGAR DE NUEVO!"<<std::endl;
	gotoxy(18,24);
	textcolor(YELLOW);
	std::cout<< "------------------------"<<std::endl;
	
	//este esta en modo "apagado", no esta resaltado por defecto
	gotoxy(66,23);
	textcolor(LIGHTGRAY);
	std::cout<< "DESEO SALIR DEL JUEGO "<<std::endl;
	
}

//captura los eventos del teclado
//para que se pueda capturar la opcion que elige el jugador(rejugar o salir)
bool Epilogo::eventos(){
	if (kbhit()){
		clrscr();
		//reescribe el menu
		mostrarMenu();
		//captura la tecla que se presiona
		int tecla = getch(); 
		switch(tecla){
		case 67:
		case 77: 
			//resalta texto izquierda
			gotoxy(65,22);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			gotoxy(66,23);
			textcolor(LIGHTMAGENTA);
			std::cout<< "DESEO SALIR DEL JUEGO "<<std::endl;
			gotoxy(65,24);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			
			//EFECTO->saca de foco esta opcion, ES LA OPCION NO ELEGIDA
			gotoxy(18,22);
			std::cout<< "                                  "<<std::endl;
			gotoxy(19,23);
			textcolor(LIGHTGRAY);
			std::cout<< "QUIERO JUGAR DE NUEVO!"<<std::endl;
			gotoxy(18,24);
			std::cout<< "                                "<<std::endl;
			
			//setea la boleana en True por que desea seguir jugando
			quiereSalir = true;
			break;
			
		case 68:
		case 75:
			//resalta texto derecha, si estoy listo y pone borde de seleccion
			gotoxy(18,22);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			gotoxy(19,23);
			textcolor(LIGHTMAGENTA);
			std::cout<< "QUIERO JUGAR DE NUEVO!"<<std::endl;
			gotoxy(18,24);
			textcolor(YELLOW);
			std::cout<< "------------------------"<<std::endl;
			
			//EFECTO->saca de foco la opcion no estoy listo, es la opcion NO ELEGIDA
			gotoxy(65,22);
			std::cout<< "                                "<<std::endl;
			gotoxy(66,23);
			textcolor(LIGHTGRAY);
			std::cout<< "DESEO SALIR DEL JUEGO "<<std::endl;
			gotoxy(65,24);
			std::cout<< "                                    "<<std::endl;
			
			//setea la boleana en false para poder seguir jugando
			quiereSalir = false;  
			break;
			
		case 13:
			//cuando capturando es true, significa que
			// se presiono ENTER y ya se eligio una opcion
			capturando = false;
			break;
		}
	}		
return false;
}

//muestra un texto de despedida con agradecimiento al jugador/a y nombre de la autora
void Epilogo:: mostrarDespedida(){
	clrscr();
	//mensaje que dice : " Gracias por jugar!"
	gotoxy(12,6);
	textcolor(LIGHTGREEN);
	std::cout<< "  __   __        __          __      __   __   __                __        __       /"<<std::endl;
	gotoxy(12,7);
	std::cout<<" / _` |__)  /"<<char(92)<<"  /  ` |  /"<<char(92)<<"  /__`    |__) /  "<<char(92)<<" |__)       | |  | / _`  /"<<char(92)<<"  |__)     /"<<std::endl;
	gotoxy(12,8);
	std::cout<<" "<<char(92)<<"__> |  "<<char(92)<<" /~~"<<char(92)<<" "<<char(92)<<"__, | /~~"
		<<char(92)<<" .__/    |    "<<char(92)<<"__/ |  "<<char(92)<<"    "<<char(92)<<"__/ "
		<<char(92)<<"__/ "<<char(92)<<"__> /~~"<<char(92)<<" |  "<<char(92)<<"    ."<<std::endl;
	
	//nombre alumna autora
	gotoxy(40,12);
	textcolor(LIGHTCYAN);
	std::cout<< "MARIA EMILIA CORBETTA 2021 "<<std::endl;
	textcolor(LIGHTGRAY);
	
}


