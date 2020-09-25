#include "Boton.h"
Boton::Boton(float posx, float posy, String nombre)
{
	this->btn = new Texture();
	nombre = "Resources/boton" + nombre + ".PNG";
	btn->loadFromFile(nombre);
	this->imagen = new Sprite(*btn);
	imagen->setTexture(*btn);
	imagen->setPosition(posx, posy);
}

Sprite* Boton::getImagen() {
	return imagen;
}
