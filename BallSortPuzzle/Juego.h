#pragma once
#include <iostream>;
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Juego {


private:
	RenderWindow * ventana;
	int fps;
	Texture textura1;
	Sprite sprite1;
public:
	Juego(int ancho, int alto, string titulo);
	void gameLoop();
	void dibujar();
};

