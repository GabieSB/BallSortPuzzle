#include "Bola.h"
#include <iostream>
using namespace std;
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

Bola::Bola(const Bola& bola) {
	sig = NULL;
	ant = NULL;
	circle = new CircleShape();
	*circle = *bola.circle;
	cout<<"x ="<<circle->getPosition().x <<" y ="<<circle->getPosition().y<<endl;
}

Bola::Bola(CircleShape *circle) {
	
	this->circle = circle;
	this->ant = NULL;
	this->sig = NULL;
	this->x = 0;
	this->y = 0;
	cout << "Normal  x =" << circle->getPosition().x << " y =" << circle->getPosition().y << endl;

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




