#pragma once
#include <iostream>

#include "Bola.h"
using namespace std;


class Tubo
{
private:
	//RenderWindow* ventana;
	Bola* pilaBolas;
	Tubo* sig;
	Tubo* ant;
	int x;
	int y;
	int cantidadActual;


public :
	Tubo(int x, int y);
	void dibujarTubo(RenderWindow*& ventana);
	void push(Bola *bola);
	Bola* pop();
	void cargar_tubo(RenderWindow*& ventana);
	void setAnt(Tubo* ant);
	void setSig(Tubo* sig);
	Tubo* getSig();
	Tubo* getAnt();
	int getX();
	int getY();
	int getCantidadActual();

//	void setWindow(RenderWindow*& ventana);




};

