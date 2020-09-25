#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Boton.h"
#include "Partida.h"
#include "Global.h"

using namespace std;
using namespace sf;
class Menu {
private:
	Boton* titulo, *jugar, * cargarp, * acerca_de, * salirp;
	Partida* partida;
public:
	Menu(Partida* p);
	void botones(RenderWindow* v);
	void analizarClicks(int posx, int posy, RenderWindow*& window);
	void iniciar(int posx, int posy, RenderWindow* v);
	void cargar(int posx, int posy, RenderWindow*& window);
	void acercade(int posx, int posy, RenderWindow*& window);
	void salir(int posx, int posy, RenderWindow*& window);
};

