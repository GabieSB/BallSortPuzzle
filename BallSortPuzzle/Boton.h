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
	Font fuente;
	Text txt_btn;

public:
	Boton(float posx, float posy, String nombre);
	Sprite* getImagen();
};

