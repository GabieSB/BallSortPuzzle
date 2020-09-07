#pragma once
#include "Nivel.h"
#include "Tubo.h"
class Partida
{
private:
	Nivel *nivel;

	//se deberia crear una lista de niveles, este es temporal

	//usuario

public:

	Partida();
	void cargarPartida(RenderWindow *& window);
	Tubo* esClickEnTubo(int xm, int ym);


};

