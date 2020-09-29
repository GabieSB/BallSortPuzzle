#include "Global.h"
Global::Global() {
	pantalla = 1;
	ventana = nullptr;
	nivel = 1;

}

Global &Global::getInstance() {
	static Global INSTANCE;
	return INSTANCE;
}

int Global::getPantalla() {
	return this->pantalla;
}

void Global::setPantalla(int p) {
	this->pantalla = p;
}

int Global::getNivel() {
	return this->nivel;
}

/* 
void Global::setPartida(Partida *p) {
	this->partida = p;
}

Partida* Global::getPartida() {
	return this->partida;
}*/



void Global::setNivel(int n) {
	this->nivel = n;
}
int Global::getX() {
	if (nivel == 1) return 0;
	else if (nivel == 2) return 0;
	else if (nivel == 3) return 0;
	else if (nivel == 4) return 0;
	else return 0;
}

int Global::getY() {
	if (nivel == 1) return 0;
	else if (nivel == 2) return 0;
	else if (nivel == 3) return 0;
	else if (nivel == 4) return 0;
	else return 0;
}

RenderWindow* Global::getWindow() {
	return ventana;
}

void Global::setWindow(RenderWindow* v) {
	this->ventana = v;
}
