#include "Juego.h"
#include <iostream>

int main() {
    Juego* juego = new Juego(800, 600);

    juego->dibujar();
    return 0;
}

