#include "Menu.h"
Menu::Menu(Partida* p) {
	partida = p;
}
void Menu::botones(RenderWindow* v) {
	//int posx, int posy, String nombre, 
	titulo = new Boton(70,20,"5");
	jugar = new Boton(180, 120, "1");
	cargarp = new Boton(180, 200, "2");
	acerca_de = new Boton(180, 280, "3");
	salirp = new Boton(180, 360, "4");
	v->draw(*titulo->getImagen());
	v->draw(*jugar->getImagen());
	v->draw(*cargarp->getImagen());
	v->draw(*acerca_de->getImagen());
	v->draw(*salirp->getImagen());
}

void Menu::analizarClicks(int posx, int posy, RenderWindow*& window) {
	window->clear(Color::Color(25,43,26,255));
	iniciar(posx, posy, window);
	cargar(posx, posy, window);
	acercade(posx, posy, window);
	salir(posx, posy, window);
}

void Menu::iniciar(int posx, int posy, RenderWindow* v) {
	if (posx > 180 && posx < 430 && posy > 120 && posy < 175) {
		Global::getInstance().setPantalla(2);
	}
}


void Menu::cargar(int posx, int posy, RenderWindow*& window) {
	if (posx > 180 && posx < 430 && posy > 200 && posy < 240) {
		cout << "Entro";
		window->clear(Color::White);
	}
}


void Menu::acercade(int posx, int posy, RenderWindow*& window) {
	if (posx > 180 && posx < 430 && posy > 280 && posy < 335) {
		cout << "Entro";
		window->clear(Color::White);
	}
}

void Menu::salir(int posx, int posy, RenderWindow*& window) {
	if (posx > 180 && posx < 430 && posy > 355 && posy < 420) {
		window->close();
	}
}
