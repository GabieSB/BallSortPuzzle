#include "Boton.h"

Boton::Boton(float posx, float posy, float width, float heigth, Color color, String nombre)
{
	btn = new RectangleShape({ width, heigth });
	btn->setFillColor(color);
	btn->setPosition(posx, posy);
	/*if (!fuente.loadFromFile("Fonts/samosan.ttf")) {
		cout<< "Fallo ";
	}*/
	txt_btn.setString(nombre);
	txt_btn.setFont(fuente);
	txt_btn.setPosition(posx, posy);
	txt_btn.setCharacterSize(10);
	txt_btn.setFillColor(Color::Black);
}

RectangleShape* Boton::getRect() {
	return btn;
}
