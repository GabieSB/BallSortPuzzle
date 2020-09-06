#include "Bola.h"

Bola::Bola() {
	this->color = "SIN COLOR";
	this->sig = NULL;
	this->ant = NULL;
	this->x = 0;
	this->y = 0;
}

Bola::Bola(string color, Bola* sig, Bola* ant) {
	this->color = color;
	this->sig = sig;
	this->ant = ant;
}

Bola::Bola(string color, Bola* sig, Bola* ant, int x, int y) {
	this->color = color;
	this->sig = sig;
	this->ant = ant;
	this->x = x;
	this->y = y;

}

void Bola::setSig(Bola* sig) {
	this->sig = sig;
}
void Bola::setAnt(Bola* ant) {
	this->ant = ant;
}

void Bola::setColor(string color) {
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


