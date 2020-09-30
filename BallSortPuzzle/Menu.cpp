#include "Menu.h"
Menu::Menu(Partida* p) {
	partida = p;
}
void Menu::botones(RenderWindow* v) {
	//int posx, int posy, String nombre, 
	menu = new Boton(0,0);
	v->draw(*menu->getImagen());
}

void Menu::analizarClicks(int posx, int posy, RenderWindow*& window) {
	window->clear(Color::Color(25,43,26,255));
	iniciar(posx, posy, window);
	cargar(posx, posy, window);
	acercade(posx, posy, window);
	salir(posx, posy, window);
}

void Menu::iniciar(int posx, int posy, RenderWindow* v) {
	if (posx > 175 && posx < 430 && posy > 209 && posy < 267) {
		Global::getInstance().setPantalla(2);
	}
}


void Menu::cargar(int posx, int posy, RenderWindow*& window) {
	if (posx > 175 && posx < 430 && posy > 295 && posy < 350) {
		Global::getInstance().setPantalla(3);
		window->clear(Color::White);
	}
}


void Menu::acercade(int posx, int posy, RenderWindow*& window) {
	if (posx > 175 && posx < 430 && posy > 380 && posy < 435) {
		Global::getInstance().setPantalla(4);
	}
}

void Menu::salir(int posx, int posy, RenderWindow*& window) {
	if (posx > 175 && posx < 430 && posy > 468 && posy < 520) {
		window->close();
	}
}
