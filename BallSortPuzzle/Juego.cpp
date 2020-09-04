#include "Juego.h"
#include <iostream>;
using namespace std;

Juego::Juego(int ancho, int alto, string titulo) 
{
	ventana = new RenderWindow(VideoMode(alto, ancho), "Ball sort");

	fps = 40;

	ventana->setFramerateLimit(fps);



	string nombre = "tubo.PNG";
	if (!textura1.loadFromFile("tubo.png")) {
		cout << "no se pudo cargar la imagen"<< nombre << endl;
	}
	sprite1.setTexture(textura1);

	gameLoop();
}


void Juego::gameLoop() {
	cout << "En el game loop" << endl;

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	while (ventana->isOpen()) {
		sf::Event event;
		while (ventana->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				ventana->close();
		}
		ventana->clear(sf::Color::White);
		ventana->draw(sprite1);
		ventana->display();
	
	}

}

void Juego::dibujar() {
	
}

