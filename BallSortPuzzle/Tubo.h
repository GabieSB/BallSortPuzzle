#pragma once
#include <iostream>

#include "Bola.h"
using namespace std;


class Tubo
{
private:
	Bola* pilaBolas;
	Tubo* sig;
	Tubo* ant;


public :
	Tubo();
	void dibujar_bola();
	void push(Bola *bola);
	Bola* pop();
	void cargar_tubo();




};

