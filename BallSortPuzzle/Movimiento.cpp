#include "Movimiento.h"

Movimiento::Movimiento(int x, int y, Movimiento *sig, Movimiento *ant) {

	this->x = x;
	this->y = y;
	this->ant = ant;
	this->sig = sig;

}

void Movimiento::setX(int x) {
	this->y = y;

}
void Movimiento::setY(int y) {
	this->x = x;
}

int Movimiento::getX() {
	return x;
}

int Movimiento::getY() {
	return y;
}

void Movimiento::setSig(Movimiento *sig) {
	this->sig = sig;

}
void Movimiento::setAnt(Movimiento *ant) {
	this->ant = ant;
}

Movimiento* Movimiento::getSig() {
	return sig;
}

Movimiento* Movimiento::getAnt() {
	return ant;
}


