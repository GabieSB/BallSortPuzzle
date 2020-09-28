#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"


using namespace sf;
using namespace std;
class Boton {
private:
	Texture* btn;
	Sprite* imagen;

public:
	Boton(float posx, float posy);
	Sprite* getImagen();
};

