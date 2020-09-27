#pragma once
#include <SFML/Graphics.hpp>
#include "Nivel.h"
#include "Tubo.h"
#include "Movimiento.h"
#include "Global.h"
#include<windows.h>
#include <iostream>

class Partida{
private:
	Nivel *nivel;
	RenderWindow* ventana;
	Tubo* tuboSeleccionado;
	Nivel* movimientos;
	String pantalla;
	int mov;
	bool nivelCompleto;
	bool enRepeticion;
	//se deberia crear una lista de niveles, este es temporal

	//usuario

public:

	Partida();
	void cargarPartida(RenderWindow *& window);
	bool esClickEnTubo(int xm, int ym, RenderWindow*& window);
	void seleccionarBolaTope(Tubo*& tubo);
	void realizarMovimiento(Tubo *&tuboRecibe, RenderWindow*& window);
	void dibujarPartida(RenderWindow*& ventana);
	void analizarClicks(int x, int y, RenderWindow*& window);
	void esClickEnRetroceder(int x, int y, RenderWindow*& window);
	void esClickEnMenu(int x, int y, RenderWindow*& window);
	void esClickEnGuardar(int x, int y, RenderWindow*& window);
	void pushMovimiento();
	Nivel* popMovimiento();
	Nivel* copiarContenidoNivel(const Nivel*& viejo, Nivel* nuevo);
	void analizarTubosNivel();
	void guardarPartida();
	void nivelGanado(RenderWindow*& window);
	void clickSiguienteNivel(int x, int y);
	void dibujarMenu();
	void reproducirMovimientos(RenderWindow*& window);
	

};

