#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Bola
{
private:
	CircleShape *circle;
	int x;
	int y;
	Color color;
	Bola* sig;
	Bola* ant;

public:
	Bola();
	Bola( Bola* sig, Bola* ant);
	Bola(CircleShape *circle);
	void setColor(Color color);
	void setX(int x);
	void setY(int y);
	void setSig(Bola *sig);
	void setAnt(Bola *ant);
	void setCircle(CircleShape *circle);
	int getX();
	int getY();
	Bola* getAnt();
	Bola* getSig();
	CircleShape* getCircle();


};


