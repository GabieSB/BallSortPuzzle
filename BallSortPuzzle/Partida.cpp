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

	if (nivel->isCompleto()) {
		
		Texture* textura2 = new Texture();
		string imagen2 = "Resources/win.jpg";

		if (!textura2->loadFromFile("Resources/win.jpg"))cout << "no se carga la imagen<<";

		Sprite* sprite2 = new Sprite(*textura2);
		sprite2->setTexture(*textura2);
		sprite2->setPosition(150,120);
		ventana->draw(*sprite2);
	}
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

bool Partida::esClickEnTubo(int xm, int ym, RenderWindow *& window) {
	int x ;
	int y ;
	Tubo* aux = nivel->getTubos();
	while (aux != NULL) {
		x = aux->getX();
		y = aux->getY();
		if (xm > x && xm < x + 40 && ym < y + 40 && ym> y + 40 - (5 * 42)) {
			
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
	if (nivel->isCompleto()) {
		clickSiguienteNivel(xm, ym);
	}
}

void Partida::esClickEnRetroceder(int xm, int ym, RenderWindow*& window) {
	if (xm > 720 && xm < 780 && ym < 80 && ym> 20) {
		nivel = NULL;
		nivel = popMovimiento();
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
		if (aux->getCantidadActual() < 4 && circuloTopeRecibe->getFillColor() == circuloTopeEnvia->getFillColor()) {
			pushMovimiento();
			aux->push(tuboSeleccionado->pop());
			nivel->setMovimientos();
			if (nivel->nivelGanado()) nivelGanado(window);//ANALIZA SII GAAAAA
		}
		else {
			cout << "no se puede colocar " << endl;
			tuboSeleccionado->deseleccionarTope(window);

		}
	}
	else {//si el tope esta vacio coloca directamente
		pushMovimiento();
		aux->push(tuboSeleccionado->pop());
		
		nivel->setMovimientos();

	}
	tuboSeleccionado = NULL;


}
void Partida::clickSiguienteNivel(int xm, int ym) {

	if (xm > 263 && xm < 528 && ym > 419 && ym < 481) {
		movimientos = NULL;
		nivel->setIsCompleto(true);
		nivel = new Nivel(nivel->getNumero() + 1);
	}
}
void Partida::nivelGanado(RenderWindow *&window) {
	cout << "GANAAASTEEEE!" << endl;
	nivel->setIsCompleto(true);
	
}

void Partida::guardarPartida() {
	

}

