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
	Image* icon = new Image();
	icon->loadFromFile("Resources/icon.PNG");
	ventana->setIcon(icon->getSize().x, icon->getSize().y, icon->getPixelsPtr());
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
			else  if (Global::getInstance().getPantalla() == 3) {

				partida->cargarPartida(this->ventana);
				Global::getInstance().setPantalla(2);
			}
			else if(Global::getInstance().getPantalla() == 4){
				ventana->clear(Color::Color(25, 43, 26, 255));
				Texture* textura = new Texture();
				String imagen = "Resources/acerca.PNG";
				textura->loadFromFile(imagen);
				Sprite* sprite = new Sprite(*textura);
				sprite->setTexture(*textura);
				sprite->setPosition(Global::getInstance().getX(), Global::getInstance().getY());
				ventana->draw(*sprite);
				ventana->display();
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