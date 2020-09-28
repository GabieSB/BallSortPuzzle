#pragma once
#include <SFML/Graphics.hpp>
#include "Nivel.h"
#include "Tubo.h"
#include "Movimiento.h"
#include "Global.h"
#include<windows.h>
#include <iostream>
#include <fstream>
//#include "fstream"

class Partida{
private:


	RenderWindow* ventana;
	Nivel* nivel;
	Tubo* tuboSeleccionado;
	Nivel* movimientos;
	Movimiento* iniCoordenas;
	String pantalla;
	int mov;
	bool nivelCompleto;
	bool enRepeticion;
	bool pintarImagenNivelCompleto;
	int auxX;
	int auxY;

	//se deberia crear una lista de niveles, este es temporal

	//usuario

public:

	Partida();
	void pintarPartidaGeneral(RenderWindow *& window);
	bool esClickEnTubo(int xm, int ym, RenderWindow*& window);
	void seleccionarBolaTope(Tubo*& tubo);
	bool realizarMovimiento(Tubo *&tuboRecibe, RenderWindow*& window);
	void dibujarPartida(RenderWindow*& ventana);
	void analizarClicks(int x, int y, RenderWindow*& window);
	void esClickEnRetroceder(int x, int y, RenderWindow*& window);
	void esClickEnMenu(int x, int y, RenderWindow*& window);
	void esClickEnGuardar(int x, int y, RenderWindow*& window);
	void esClickEnReproducir(int x, int y, RenderWindow*& window);
	void pushMovimiento();
	Nivel* popMovimiento();
	Nivel* copiarContenidoNivel(const Nivel*& viejo, Nivel* nuevo);
	void analizarTubosNivel();
	void guardarPartida();
	void nivelGanado(RenderWindow*& window);
	void clickSiguienteNivel(int x, int y);
	void cargarPartida(RenderWindow *&window);
	void reproducirMovimientos(RenderWindow*& window);
	void guardarCoordenadasMovimiento(int x, int y);

	void pintarNivelGanado(RenderWindow *&);
	

};

