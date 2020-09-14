#include "Menu.h"

Menu::Menu() {
	partida = new Partida();
}
void Menu::botones(RenderWindow* v) {
	//int posx, int posy, float width, float heigth, String nombre, Color color
	btn1 = new Boton(200, 150, 200, 40, Color::Blue, "Iniciar");
	btn2 = new Boton(200,200,200,40,Color::Blue, "Cargar Partida");
	btn3 = new Boton(200, 250, 200, 40, Color::Blue, "Acerca de");
	btn4 = new Boton(200, 300, 200, 40, Color::Blue, "Salir");
	v->draw(*btn1->getRect());
	v->draw(*btn2->getRect());
	v->draw(*btn3->getRect());
	v->draw(*btn4->getRect());
}

void Menu::analizarClicks(int posx, int posy, RenderWindow*& window) {
	window->clear(Color::White);
	iniciar(posx,posy,window);
	cargar(posx, posy, window);
	acercade(posx, posy, window);
	salir(posx,posy,window);
}

void Menu::iniciar(int posx, int posy,RenderWindow * v) {
	if (posx > 200 && posx < 400 && posy > 150 && posy < 190) {
		cout << "Entro" << endl;
		v->clear(Color::White);
		//partida->cargarPartida(v);
	}
}


void Menu::cargar(int posx, int posy, RenderWindow*& window) {
	if (posx > 200 && posx < 400 && posy > 200 && posy < 240) {
		cout << "Entro";
		window->clear(Color::White);
	}
}


void Menu::acercade(int posx, int posy, RenderWindow*& window) {
	if (posx > 200 && posx < 400 && posy > 250 && posy < 290) {
		cout << "Entro";
		window->clear(Color::White);
	}
}

void Menu::salir(int posx, int posy, RenderWindow*& window) {
	if (posx > 200 && posx < 400 && posy > 300 && posy < 340) {
		window->close();
	}
}


