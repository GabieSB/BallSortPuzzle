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

void Global::setNivel(int n) {
	this->nivel = n;
}
int Global::getX() {
	if (nivel == 1) return 185;
	else if (nivel == 2) return 185;
	else if (nivel == 3) return 185;
	else if (nivel == 4) return 150;
	else return 185;
}

int Global::getY() {
	if (nivel == 1) return 165;
	else if (nivel == 2) return 85;
	else if (nivel == 3) return 85;
	else if (nivel == 4) return 85;
	else return 85;
}

RenderWindow* Global::getWindow() {
	return ventana;
}

void Global::setWindow(RenderWindow* v) {
	this->ventana = v;
}
