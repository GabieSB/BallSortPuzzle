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

RenderWindow* Global::getWindow() {
	return ventana;
}

void Global::setWindow(RenderWindow* v) {
	this->ventana = v;
}
