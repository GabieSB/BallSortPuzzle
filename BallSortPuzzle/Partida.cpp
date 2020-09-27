#include "Partida.h"
#include <dos.h> //for delay
Partida::Partida() {
	tuboSeleccionado = NULL;
	nivel = new Nivel(Global::getInstance().getNivel());
	movimientos = NULL;
	ventana = NULL;
	mov = 0;
	nivelCompleto = false;
	enRepeticion = false;
}

void Partida::cargarPartida(RenderWindow *&ventana) {
	//mov = 0;
	Texture* textura = new Texture();
	String imagen = "Resources/nivel"+ to_string(Global::getInstance().getNivel()) +".PNG";
	textura->loadFromFile(imagen);
	Sprite* sprite = new Sprite(*textura);
	sprite->setTexture(*textura);
	sprite->setPosition(Global::getInstance().getX(), Global::getInstance().getY());
	ventana->draw(*sprite);
	nivel->dibujarNivel(ventana);
	dibujarPartida(ventana);
	
}

void Partida::dibujarPartida(RenderWindow*& ventana) {


	Texture* textura1 = new Texture();
	string imagen = "Resources/repetir.PNG";

	Texture* textura2 = new Texture();
	string imagen2 = "Resources/menu.PNG";

	Texture* textura3 = new Texture();
	string imagen3 = "Resources/save.PNG";

	textura1->loadFromFile(imagen);
	textura2->loadFromFile(imagen2);
	textura3->loadFromFile(imagen3);

	Sprite* sprite1 = new Sprite(*textura1);
	Sprite* sprite2 = new Sprite(*textura2);
	Sprite* sprite3 = new Sprite(*textura3);
	sprite1->setTexture(*textura1);
	sprite1->setPosition(520, 5);
	sprite2->setPosition(20, 5);
	sprite3->setPosition(280, 5);
	ventana->draw(*sprite1);
	ventana->draw(*sprite2);
	ventana->draw(*sprite3);



	if (nivel->isCompleto()) {

		if (nivelCompleto) {
			if (!enRepeticion) {
			
				reproducirMovimientos(ventana);
			
				enRepeticion = true;

				cout << "Se termino de reproducir los movimientos" << endl;

			}
		
		}

		nivelCompleto = true;
	}

	if (nivelCompleto && enRepeticion) {

		Texture* textura2 = new Texture();
		string imagen2 = "Resources/win.jpg";

		if (!textura2->loadFromFile(imagen2))cout << "no se carga la imagen<<";
		Sprite* sprite2 = new Sprite(*textura2);
		sprite2->setTexture(*textura2);
		sprite2->setPosition(60, 90);
		ventana->draw(*sprite2);
	}
}

void Partida::pushMovimiento() {

	Nivel* nuevo = new Nivel(*nivel);

	if (nuevo->isCompleto()) nuevo->setIsCompleto(false);

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
void Partida::dibujarMenu() {

	

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
				//nivel->pushMovimiento(xm, ym);
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
	esClickEnMenu(xm, ym, window);
	esClickEnGuardar(xm, ym, window);
	if (nivelCompleto) {
		clickSiguienteNivel(xm, ym);
	}
}

void Partida::esClickEnRetroceder(int xm, int ym, RenderWindow*& window) {
	if (xm > 530 && xm < 590 && ym < 65 && ym> 10) {
		if (mov > 0) {
			nivel = NULL;
			nivel = popMovimiento();
			if (nivel != NULL && mov > 0) {
				mov--;
				cout << nivel->getTubos()->getCantidadActual();
				nivel->dibujarNivel(window);
			}
			else {
				cout << "No hay mas movimientos" << endl;
			}
		}
		else {
			cout << "No hay mas movimientos" << endl;
		}
		
	}
}

void Partida::esClickEnMenu(int xm, int ym, RenderWindow*& window) {
	//Pantalla
	if (xm > 20 && xm < 84 && ym > 14 && ym< 78) {
		Global::getInstance().setPantalla(1);
	}
}

void Partida::esClickEnGuardar(int xm, int ym, RenderWindow*& window) {
	
	if (xm > 290 && xm < 337 && ym > 10 && ym < 60) {
		

	}
}

void Partida::realizarMovimiento(Tubo *&tuboRecibe, RenderWindow*& window) {
	Tubo* aux = tuboRecibe;
	if (mov < 5) mov++;
	if (aux->getTope() != NULL) {
		CircleShape* circuloTopeRecibe = aux->getTope()->getCircle();
		CircleShape* circuloTopeEnvia = tuboSeleccionado->getTope()->getCircle();
		cout << aux->getCantidadActual() << endl;
		if (aux->getCantidadActual() < 4 && circuloTopeRecibe->getFillColor() == circuloTopeEnvia->getFillColor()) {
			pushMovimiento();
			aux->push(tuboSeleccionado->pop());
			nivel->setMovimientos();
			
			if(nivel->nivelGanado()) pushMovimiento();
		}
		else {
			cout << "no se puede colocar " << endl;
			//nivel->popMovimiento();
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

	if (xm > 180 && xm < 433 && ym > 395 && ym < 447) {
		movimientos = NULL;
		nivel->setIsCompleto(true);
		nivelCompleto = false;
		enRepeticion = false;
		nivel = new Nivel(nivel->getNumero() + 1);
	}
}
void Partida::nivelGanado(RenderWindow *&window) {
	cout << "GANAAASTEEEE!" << endl;
	reproducirMovimientos(window);
	nivel->setIsCompleto(true);
	
}

void Partida::reproducirMovimientos(RenderWindow *&window) {
	cout << "Sleping" << endl;
	cout << "TOTA MOVIMIENTOS " << mov << endl;
	
	int cont = 0;
	Nivel* aux = movimientos;
	while (aux != NULL) {
		cont++;
		if (aux->getAnt() == NULL) break;
		aux = aux->getAnt();

	}

	while (aux != NULL) {
		cont--;
		cout << "movimeinto " << cont << endl;
		nivel = aux;
		window->clear(Color::Color(25, 43, 26, 255));
		cargarPartida(window);
		window->display();
		Sleep(1000);
		aux = aux->getSig();

	}
	cout << "sale del while" << endl;


}

void Partida::guardarPartida() {
	nivel->guardarNivel();


}