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
	menu = new Menu(partida);
	gameLoop();
	evento = true;
	
}

void Juego::gameLoop() {
	
	while (this->ventana->isOpen()) {

		if (evento) {
			ventana->clear(Color::Color(25, 43, 26, 255));
			if (Global::getInstance().getPantalla() == 1) {
				menu->botones(ventana);
			}
			else {
				partida->cargarPartida(ventana);
				evento = false;
			}
			ventana->display();
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
		
		/*int x = 100;
		int y = 300;
		


		if (xm > x && xm < x + 40 && ym < y + 40 && ym> y+40 -(5*42)){
			cout << "Es click en tubo" << endl;
		
		}*/

	}
}

void Juego::image() {
	this->textura1 = new Texture();
	imagen = "Resources/nivel1.PNG";
	textura1->loadFromFile(imagen);
	this->sprite1 = new Sprite(*textura1);
	sprite1->setTexture(*textura1);
}