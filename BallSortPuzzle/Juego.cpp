#include "Juego.h"
#include <iostream>
#include "Tubo.h"
#include "Nivel.h"
#include "Partida.h"
using namespace std;
Juego::Juego(int ancho, int alto) {
	this->ancho = ancho;
	this->alto = alto;
	ventana = new RenderWindow(VideoMode(ancho, alto), "Ball sort");
	Global::getInstance().setWindow(ventana);
	
	partida = new Partida();
	//Global::getInstance().setPartida(partida);
	menu = new Menu(partida);
	evento = true;
	
	gameLoop();
	
	
}

void Juego::gameLoop() {
	while (this->ventana->isOpen()) {

		if (evento ) {
			
			if (Global::getInstance().getPantalla() == 1 ) {
					ventana->clear(Color::Color(25, 43, 26, 255));
					menu->botones(ventana);
					ventana->display();
			}
			else if(Global::getInstance().getPantalla() == 2) {
				ventana->clear(Color::Color(25, 43, 26, 255));
				partida->pintarPartidaGeneral(ventana);
				evento = false;
				ventana->display();
			}
			else {

				partida->cargarPartida(this->ventana);
				Global::getInstance().setPantalla(2);
			}
		
		}
		Event event;
		while (this->ventana->pollEvent(event)) {
			analizarEventos(event);
		}
		
	}
}

void Juego::analizarEventos(Event event) {
	if (event.type == Event::Closed) {
		ventana->close();
	}
	else if (event.type == Event::MouseButtonPressed) {
		evento = true;
		cout << Mouse::getPosition(*ventana).x << " , " << Mouse::getPosition(*ventana).y << endl;
		int x = Mouse::getPosition(*ventana).x;
		int y = Mouse::getPosition(*ventana).y;
		
		if (Global::getInstance().getPantalla() == 1) {
			menu->analizarClicks(x, y, ventana);
		}
		else {
			partida->analizarClicks(x, y, ventana);
		}
	}
}