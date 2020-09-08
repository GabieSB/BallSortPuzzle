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
	Nivel* sig;
	Nivel* ant;
	int movimientos;

public:

	Nivel(int numero);
	Nivel(const Nivel& nivel);
	void cargarNivel();
	void nivel1();
	void agregarTubo(Tubo*& tubo);
	Tubo* esClickEnTubo(int x, int y);
	Tubo* getTubos();
	void dibujarNivel(RenderWindow*& ventana);
	bool nivelGanado();
	void setSig(Nivel* sig);
	void setAnt(Nivel* ant);
	void setTubos(Tubo* tubo);
	Nivel* getAnt();
	Nivel* getSig();
	void setMovimientos();
	int getMovimientos();



};

