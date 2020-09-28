#include "Partida.h"
#include <dos.h> //for delay
Partida::Partida() {
	tuboSeleccionado = NULL;
	nivel = new Nivel(Global::getInstance().getNivel());
	movimientos = NULL;
	ventana = NULL;
	mov = 0;
	nivelCompleto = false;
	pintarImagenNivelCompleto = false;
	iniCoordenas = NULL;
}

void Partida::pintarPartidaGeneral(RenderWindow *&ventana) {
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
	pintarImagenNivelCompleto = false;
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
	sprite1->setPosition(520, 6);
	sprite2->setPosition(17, 6);
	sprite3->setPosition(280, 6);

	ventana->draw(*sprite1);
	//ventana->draw(*sprite2);
	ventana->draw(*sprite3);



	
	if (pintarImagenNivelCompleto) {
		pintarNivelGanado(ventana);
	}

	ventana->draw(*sprite2);
}

void Partida::pintarNivelGanado(RenderWindow*& window) {

	Texture* textura5 = new Texture();
	string imagen5 = "Resources/nivel.png";

	if (!textura5->loadFromFile(imagen5))cout << "no se carga la imagen<<";
	Sprite* sprite5 = new Sprite(*textura5);
	sprite5->setTexture(*textura5);
	sprite5->setPosition(0, 0);
	window->draw(*sprite5);
}

void Partida::pushMovimiento() {

	Nivel* nuevo = new Nivel(*nivel);

	if (nuevo->isCompleto()) nuevo->setIsCompleto(false);

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
	Nivel* nodoEliminado = movimientos;
	if (movimientos != NULL) {

		movimientos->setSig(NULL);
		movimientos = movimientos->getAnt();

	}
	return nodoEliminado;
}
void Partida::cargarPartida(RenderWindow *& window) {
	ifstream archivo("partidas/prueba.txt");
	string line;
	int cx;
	int cy;
	while (getline(archivo, line)) {
		if (line[0] == '#') {

			int num = line[1] - '0';
		
			nivel = new Nivel(num);
		}
		else {
			string number = "";
			for (int i = 0; i < line.length(); i++) {
				if (line[i] != ',') {
					number += line[i];
				}
				else {
					cx = stoi(number);
					number = "";
				}
			}
			cy = stoi(number);

			esClickEnTubo(cx,cy, window);
		}

	}
	archivo.close();
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
				this->auxX = xm;
				this->auxY = ym;
				tuboSeleccionado = aux;
				
			}
			else {
				//nivel->pushMovimiento(xm, ym);
				if (realizarMovimiento(aux, window)) {
					guardarCoordenadasMovimiento(this->auxX, this->auxY);
					guardarCoordenadasMovimiento(xm, ym);
				
				}
								
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
	esClickEnReproducir(xm, ym, window);
	if (nivelCompleto) {
		clickSiguienteNivel(xm, ym);
	}
}

void Partida::esClickEnRetroceder(int xm, int ym, RenderWindow*& window) {
	if (xm > 530 && xm < 590 && ym < 65 && ym> 10) {
		cout << "es click en retroceder" << endl;
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
		
		guardarPartida();
	}
}

void Partida::esClickEnReproducir(int xm, int ym, RenderWindow*& window) {

	if (xm > 129 && xm < 490 && ym > 388 && ym < 455) {
		cout << "click en reproducirr" << endl;
		reproducirMovimientos(window);
		pintarImagenNivelCompleto = true;
	}
}

bool Partida::realizarMovimiento(Tubo *&tuboRecibe, RenderWindow*& window) {
	bool seRealizo = true;;
	Tubo* aux = tuboRecibe;
	if (mov < 5)mov++;
	if (aux->getTope() != NULL) {
		CircleShape* circuloTopeRecibe = aux->getTope()->getCircle();
		CircleShape* circuloTopeEnvia = tuboSeleccionado->getTope()->getCircle();
		cout << aux->getCantidadActual() << endl;
		if (aux->getCantidadActual() < 4 && circuloTopeRecibe->getFillColor() == circuloTopeEnvia->getFillColor()) {
			pushMovimiento();
			aux->push(tuboSeleccionado->pop());
			nivel->setMovimientos();
			mov++;

			if (nivel->nivelGanado()) { 
				pintarImagenNivelCompleto = true;
				nivelCompleto = true;
				pushMovimiento(); 
			}
		}
		else {
			cout << "no se puede colocar " << endl;
			seRealizo = false;
			tuboSeleccionado->deseleccionarTope(window);
		}
	}
	else {//si el tope esta vacio coloca directamente
		pushMovimiento();
		mov++;
		aux->push(tuboSeleccionado->pop());
		nivel->setMovimientos();

	}

	tuboSeleccionado = NULL;
	return seRealizo;


}
void Partida::clickSiguienteNivel(int xm, int ym) {

	if (xm > 120 && xm < 490 && ym > 286 && ym < 355) {
		cout << "siguiente" << endl;
		movimientos = NULL;
		nivel->setIsCompleto(true);
		nivelCompleto = false;
		enRepeticion = false;
		pintarImagenNivelCompleto = false;
		iniCoordenas = NULL;
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
		pintarPartidaGeneral(window);
		window->display();
		Sleep(1000);
		aux = aux->getSig();

	}
	cout << "sale del while" << endl;


}

void Partida::guardarCoordenadasMovimiento(int x, int y) {
	cout << "se guarda   " << x << "  " << y << endl;
	
	if (iniCoordenas == NULL) {
		iniCoordenas = new Movimiento(x, y, NULL, NULL);
	}
	else {
		Movimiento* aux = iniCoordenas;

		while (aux->getSig() != NULL) {
			aux = aux->getSig();
		}

		Movimiento* nuevo = new Movimiento(x, y, NULL, aux);
		aux->setSig(nuevo);
	}
}

void Partida::guardarPartida() {
	
	ofstream archivo;
	archivo.open("partidas/prueba.txt", ios::out);

	archivo << "#" << nivel->getNumero() << endl;
	Movimiento* aux = iniCoordenas;

	while (aux != NULL) {
		archivo << aux->getX() << "," << aux->getY() << endl;
		aux = aux->getSig();
	}

	
	
}