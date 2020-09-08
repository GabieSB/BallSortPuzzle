#include "Partida.h"
#include "Nivel.h"
#include "Bola.h"

Partida::Partida() {
	tuboSeleccionado = NULL;
	nivel = new Nivel(1);
	movimientos = NULL;
	
	
}

void Partida::cargarPartida(RenderWindow *&ventana) {

	
	
	nivel->dibujarNivel(ventana);
	dibujarPartida(ventana);

}

void Partida::dibujarPartida(RenderWindow*& ventana) {


	Texture *textura1 = new Texture();
	string imagen = "Resources/repetir.PNG";

	if (textura1->loadFromFile(imagen));
	
	Sprite *sprite1 = new Sprite(*textura1);
	sprite1->setTexture(*textura1);
	sprite1->setPosition(720, 20);
	ventana->draw(*sprite1);
}



void Partida::pushMovimiento() {

	

	Nivel* nuevo = new Nivel(*nivel);


	cout << "Se guardo el movimiento" << endl;

	if (movimientos == NULL) {
		nuevo->setSig(NULL);
		nuevo->setAnt(NULL);
		movimientos = nuevo;

	}
	else {

		nuevo->setSig(NULL);
		nuevo->setAnt(movimientos);
		movimientos->setSig(nuevo);
		movimientos = nuevo;

	}
}
Nivel* Partida::popMovimiento() {
	cout << "se saca un  nive" << endl;
	Nivel* nodoEliminado = movimientos;
	if (movimientos != NULL) {

		movimientos->setSig(NULL);
		movimientos = movimientos->getAnt();
		

	}
	return nodoEliminado;
}

Nivel* Partida::copiarContenidoNivel(const Nivel*& viejo, Nivel* nuevo) {
	if (viejo) {
		*nuevo = *viejo;
	}
	else {
		
	}
	return NULL;
	
}
bool Partida::esClickEnTubo(int xm, int ym, RenderWindow *& window) {
	int x ;
	int y ;

	Tubo* aux = nivel->getTubos();
	while (aux != NULL) {
		x = aux->getX();
		y = aux->getY();
		if (xm > x && xm < x + 40 && ym < y + 40 && ym> y + 40 - (5 * 42)) {
			cout << "Es click en tubo" << endl;

			
			
			if (tuboSeleccionado == NULL) {
				aux->seleccionarTope(window);
				tuboSeleccionado = aux;
			}
			else {
				
				realizarMovimiento(aux, window);
			}
			
			
			return true;
		}

		aux = aux->getSig();
	}

	return false;
}

void Partida::analizarClicks(int xm, int ym ,RenderWindow *&window) {
	esClickEnTubo(xm,ym,window);
	esClickEnRetroceder(xm, ym, window);
}

void Partida::esClickEnRetroceder(int xm, int ym, RenderWindow*& window) {
	if (xm > 720 && xm < 780 && ym < 80 && ym> 20) {

		cout << "es en retroceso" << endl;
		nivel = NULL;
		nivel = popMovimiento();
		cout << "Movimientos del nivel " << nivel->getMovimientos() << endl;;
		cout << nivel->getTubos()->getCantidadActual();
		nivel->dibujarNivel(window);
	
	}
}



void Partida::realizarMovimiento(Tubo *&tuboRecibe, RenderWindow*& window) {
	Tubo* aux = tuboRecibe;
	if (aux->getTope() != NULL) {
		CircleShape* circuloTopeRecibe = aux->getTope()->getCircle();
		CircleShape* circuloTopeEnvia = tuboSeleccionado->getTope()->getCircle();
		cout << aux->getCantidadActual() << endl;
		if (aux->getCantidadActual() < 5 && circuloTopeRecibe->getFillColor() == circuloTopeEnvia->getFillColor()) {
			aux->push(tuboSeleccionado->pop());
			pushMovimiento();
			nivel->setMovimientos();
			if (nivel->nivelGanado()) cout << "GAAANAAASTEEEE " << endl;
		}
		else {
			cout << "no se puede colocar " << endl;
			tuboSeleccionado->deseleccionarTope(window);

		}
	}
	else {//si el tope esta vacio coloca directamente
		aux->push(tuboSeleccionado->pop());
		pushMovimiento();
		nivel->setMovimientos();
		

	}
	tuboSeleccionado = NULL;


}
void Partida::seleccionarBolaTope(Tubo  *&tubo) {
	cout << "En sleccionar bola" << endl;

	CircleShape* bolaSeleccionada = tubo->getTope()->getCircle();

	bolaSeleccionada->setPosition(bolaSeleccionada->getPosition().x, bolaSeleccionada->getPosition().y - 20);
}

