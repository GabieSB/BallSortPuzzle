#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Partida.h"

using namespace std;
using namespace sf;
class Juego {
private:
	RenderWindow* ventana;
	Partida* partida;
	Texture* textura1;
	Sprite* sprite1;
	int ancho;
	int alto;
	String imagen;


public:
	Juego(int ancho, int alto);
	void gameLoop();
	void image();
	void analizarEventos(Event event);
};



