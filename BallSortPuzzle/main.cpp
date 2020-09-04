#include <SFML/Graphics.hpp>
#include "Juego.h"

int main()
{
    string nombre = "Ball sort";
    Juego *juego = new Juego(600,600, nombre.c_str());

    juego->gameLoop();



    return 0;
}