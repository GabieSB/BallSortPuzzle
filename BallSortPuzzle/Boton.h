#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
class Boton {
private:
	RectangleShape* btn;
	Font fuente;
	Text txt_btn;

public:
	Boton(int posx, int posy, float width, float heigth, Color color, String nombre);
	RectangleShape* getRect();
};

