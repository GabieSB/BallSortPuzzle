#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

using namespace sf;
class Global
{
private:
	Global();

	//Atributos
	int pantalla;
	int nivel;
	RenderWindow* ventana;
public:
	static Global &getInstance();
	int getPantalla();
	void setPantalla(int p);
	int getNivel();
	void setNivel(int n);
	RenderWindow* getWindow();
	void setWindow(RenderWindow* v);
};

