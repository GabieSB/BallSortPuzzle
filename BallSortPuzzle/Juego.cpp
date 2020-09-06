#include "Juego.h"
#include <iostream>;
using namespace std;
Juego::Juego(int ancho, int alto) {
	this->ancho = ancho;
	this->alto = alto;
	image();
}

void Juego::dibujar() {
	RenderWindow* ventana = new RenderWindow(VideoMode(ancho, alto), "Ball sort");
	while (ventana->isOpen()) {
		Event event;
		while (ventana->pollEvent(event)) {
			if (event.type == Event::Closed) {
				ventana->close();
			}
			ventana->clear(Color::White);
			ventana->draw(*sprite1);
			ventana->display();
		}
	}
}

void Juego::image() {
	this->textura1 = new Texture();
	imagen = "Resources/tubo.PNG";
	textura1->loadFromFile(imagen);
	this->sprite1 = new Sprite(*textura1);
	sprite1->setTexture(*textura1);
}