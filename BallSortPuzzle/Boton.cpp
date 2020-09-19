#include "Boton.h"

Boton::Boton(float posx, float posy, float width, float heigth, Color color, String nombre)
{
	btn = new RectangleShape({ width, heigth });
	btn->setFillColor(color);
	btn->setPosition(posx, posy);
}

RectangleShape* Boton::getRect() {
	return btn;
}
