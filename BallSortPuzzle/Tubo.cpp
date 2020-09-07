#include "Tubo.h"
Tubo::Tubo(int x, int y) {
	pilaBolas = NULL;
	sig = NULL;
	ant = NULL;
	this->x = x;
	this->y = y;
	cantidadActual = 0;
	//rgar_tubo();
}

void Tubo::push( Bola *bola) {
	cantidadActual++;
	if (pilaBolas == NULL) {
		bola->setSig(NULL);
		bola->setAnt(NULL);
		pilaBolas = bola;

	}
	else {
		
		bola->setSig(NULL);
		bola->setAnt(pilaBolas);
		pilaBolas->setSig(bola);
		pilaBolas= bola;

	}
}
/*  
void Tubo::setWindow(RenderWindow* ventana) {
	this->ventana = ventana;

}*/

Bola* Tubo::pop() {
	Bola* nodoEliminado = pilaBolas;
	if (pilaBolas != NULL) {

		pilaBolas->setSig(NULL);
		pilaBolas= pilaBolas->getAnt();

	}
	return nodoEliminado;
}

void Tubo::cargar_tubo(RenderWindow*& ventana) {

	int MAX = 5;
	int inicioX = 10;
	int inicioY  = 20;


	for (int i = 0; i < MAX; i++) {

		sf::CircleShape esfera;
		esfera.setRadius(20);
		esfera.setOutlineColor(sf::Color::Red);
		esfera.setOutlineThickness(5);
		esfera.setPosition(inicioX, inicioY);
		inicioY += 4;

		//Bola* bola = new Bola(esfera);
		//push(bola);
		
		//ventana->draw(esfera);
	}

}



void Tubo::dibujarTubo(RenderWindow*& ventana) {
	Bola* aux = pilaBolas;
	int auxY = y;
	int diametro = 42;
	
	while (aux != NULL)
	{
		aux->getCircle()->setPosition(x, auxY);
		ventana->draw(*aux->getCircle());
		auxY -= diametro;
		aux = aux->getAnt();
	}

		
	
	
}

void Tubo::setAnt(Tubo* ant) {
	this->ant = ant;
}
void Tubo::setSig(Tubo* sig) {
	this->sig = sig;
}

Tubo* Tubo::getSig() {
	return sig;
}
Tubo* Tubo::getAnt() {
	return ant;
}

int Tubo::getCantidadActual() {
	return cantidadActual;
}

int Tubo::getX() {
	return x;
}
int Tubo::getY() {
	return y;

}