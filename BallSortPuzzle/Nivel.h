#pragma once
#include "Tubo.h"
#include "Bola.h"
class Nivel
{
private:
	Tubo* iniTubos;
	int numero;
	int cantidadTubo;
	bool isPassed;

public:

	Nivel(int numero);
	void cargarNivel(RenderWindow *&window);
	void nivel1(RenderWindow*& window);
	void agregarTubo(Tubo*& tubo);
	Tubo* esClickEnTubo(int x, int y);
	Tubo* getTubos();



};

