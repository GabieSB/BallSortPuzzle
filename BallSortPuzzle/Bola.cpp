#include "Bola.h"

Bola::Bola() {
	this->color = Color::Transparent;
	this->sig = NULL;
	this->ant = NULL;
	

}

Bola::Bola(Bola* sig, Bola* ant) {
	
	this->sig = sig;
	this->ant = ant;
	this->x = 0;
	this->y = 0;

}

Bola::Bola(CircleShape *circle) {
	
	this->circle = circle;
	this->ant = NULL;
	this->sig = NULL;
	this->x = 0;
	this->y = 0;


}

void Bola::setCircle(CircleShape *circle) {

	this->circle = circle;
}

void Bola::setSig(Bola* sig) {
	this->sig = sig;
}
void Bola::setAnt(Bola* ant) {
	this->ant = ant;
}

void Bola::setColor(Color color) {
	this->color = color;
}
void Bola::setX(int x) {
	this->x = x;
}
void Bola::setY(int y) {
	this->y = y;

}

int Bola::getX() {
	return x;
}
int Bola::getY() {
	return y;

}
Bola* Bola::getAnt() {
	return ant;
}
Bola* Bola::getSig() {
	return sig;

}

CircleShape* Bola::getCircle() {
	return this->circle;

}




