#include "Tubo.h"
Tubo::Tubo(int x, int y) {
	pilaBolas = NULL;
	sig = NULL;
	ant = NULL;
	this->x = x;
	this->y = y;
	cantidadActual = 0;
	estaSeleccionado = false;
	//rgar_tubo();
}

Tubo::Tubo(const Tubo& tubos) {
	///*pilaBolas = NULL;
	sig = NULL;
	ant = NULL;
	x = tubos.x;
	y = tubos.y;
	estaSeleccionado = tubos.estaSeleccionado;

	Bola* aux = new Bola();
	*aux = *tubos.pilaBolas;
	pilaBolas = NULL;
	while (aux->getAnt() != NULL) {
		aux = aux->getAnt();
		cout << "sale del ciclo" << endl;
	}

	while (aux != NULL) {
		Bola* aux2 = new Bola(*aux);
		push(aux2);
		aux = aux->getSig();
	}

}


Tubo::Tubo() {
	pilaBolas = NULL;
	sig = NULL;
	ant = NULL;
	x = 0;
	y = 0;
	cantidadActual = 0;
	estaSeleccionado = false;

}


void Tubo::push( Bola *bola) {

	bola->getCircle()->setPosition(x, y-(40*cantidadActual));
	cout << "Se coloca una bola en x =" << bola->getCircle()->getPosition().x << " y =" << bola->getCircle()->getPosition().y <<" tubo "<<x<< endl;
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
		cantidadActual--;

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
	
	
	while (aux != NULL)
	{
		
		ventana->draw(*aux->getCircle());
	
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

bool Tubo::isSelected() {
	return estaSeleccionado;
}

void Tubo::setIsSelected(bool estado) {
	estaSeleccionado = estado;
}

Bola* Tubo::getTope() {
	return pilaBolas;
}

void Tubo::seleccionarTope(RenderWindow *&ventana) {
	
	if (pilaBolas != NULL) {
		cout << "Se selecciona" << endl;
		pilaBolas->getCircle()->move(0, -20);
		ventana->draw(*pilaBolas->getCircle());
		
	}
	this->estaSeleccionado = true;

}
void Tubo::deseleccionarTope(RenderWindow*& ventana) {
	cout << "Se deselecciona" << endl;
	if (pilaBolas != NULL ) {
		pilaBolas->getCircle()->move(0, 20);
		ventana->draw(*pilaBolas->getCircle());
	}
	this->estaSeleccionado = false;
}