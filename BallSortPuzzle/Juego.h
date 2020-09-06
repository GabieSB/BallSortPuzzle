#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
class Juego {
private:
	Texture* textura1;
	Sprite* sprite1;
	int ancho;
	int alto;
	String imagen;

public:
	Juego(int ancho, int alto);
	void dibujar();
	void image();
};



