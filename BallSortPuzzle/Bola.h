#pragma once

#include <iostream>
using namespace std;

class Bola
{
private:

	int x;
	int y;
	string color;
	Bola* sig;
	Bola* ant;

public:
	Bola();
	Bola(string color, Bola* sig, Bola* ant);
	Bola(string color, Bola* sig, Bola* ant, int x, int y);
	void setColor(string color);
	void setX(int x);
	void setY(int y);
	void setSig(Bola *sig);
	void setAnt(Bola *ant);
	int getX();
	int getY();
	Bola* getAnt();
	Bola* getSig();

};



