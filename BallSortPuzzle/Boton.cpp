#include "Boton.h"
Boton::Boton(float posx, float posy)
{
	this->btn = new Texture();
	string nombre = "Resources/menu.PNG";
	btn->loadFromFile(nombre);
	this->imagen = new Sprite(*btn);
	imagen->setTexture(*btn);
	imagen->setPosition(posx, posy);
}

Sprite* Boton::getImagen() {
	return imagen;
}
