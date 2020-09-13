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
	Texture *textura1;
	Sprite *sprite1;
	String imagen;

public:

	Nivel(int numero);
	Nivel(const Nivel& nivel);
	void cargarNivel(int num);
	void nivel1();
	void nivel2();
	void nivel3();
	void nivel4();
	void nivel5();
	void agregarTubo(Tubo*& tubo);
	Tubo* esClickEnTubo(int x, int y);
	
	Tubo* getTubos();
	void dibujarNivel(RenderWindow*& ventana);
	bool nivelGanado();
	bool isCompleto();
	void setIsCompleto(bool estado);
	void setSig(Nivel* sig);
	void setAnt(Nivel* ant);
	void setTubos(Tubo* tubo);
	Nivel* getAnt();
	Nivel* getSig();
	void setMovimientos();
	int getMovimientos();
	int getNumero();
	Color getColor(string name);
	void generarTubo(int x, int y, string colores[]);



};

