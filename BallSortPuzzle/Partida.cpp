#include "Partida.h"
#include <dos.h> //for delay
Partida::Partida() {
	tuboSeleccionado = NULL;
	nivel = new Nivel(Global::getInstance().getNivel());
	movimientos = NULL;
	ventana = NULL;
	mov = 0;
	nivelCompleto = false;
	enJuego = true;
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
	
}

void Partida::dibujarPartida(RenderWindow*& ventana) {
	
	if (pintarImagenNivelCompleto) {
		pintarNivelGanado(ventana);
	}

}

void Partida::pintarNivelGanado(RenderWindow*& window) {

	Texture* textura5 = new Texture();

	string imagen5 = "Resources/completo.png";

	if (nivel->getNumero() == 5) {
		imagen5 = "Resources/juegoCompleto.png";
	}
	



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
				if(aux->getTope()!=NULL)tuboSeleccionado = aux;
				
				
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

	if (enJuego) {
		esClickEnTubo(xm, ym, window);
		esClickEnRetroceder(xm, ym, window);
		esClickEnGuardar(xm, ym, window);
	}
	else {
		clickSiguienteNivel(xm, ym);
		esClickEnReproducir(xm, ym, window);
	}


	esClickEnMenu(xm, ym, window);
	
	
	
}

void Partida::esClickEnRetroceder(int xm, int ym, RenderWindow*& window) {
	if (xm > 193 && xm < 242 && ym > 27 && ym < 73) {
		cout << "mov " << mov << endl;
		if (mov > 0) {
			nivel = NULL;
			nivel = popMovimiento();
			if (nivel != NULL && mov > 0) {
				mov--;
				
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
	if (xm > 40 && xm < 87 && ym > 32 && ym< 66) {
		Global::getInstance().setPantalla(1);
	}
}

void Partida::esClickEnGuardar(int xm, int ym, RenderWindow*& window) {
	
	if (xm > 123 && xm < 172 && ym > 28 && ym < 77) {
		guardarPartida();
	}
}

void Partida::esClickEnReproducir(int xm, int ym, RenderWindow*& window) {
	
	if (xm > 87 && xm < 515 && ym > 444 && ym < 535) {
		pintarImagenNivelCompleto = false;
		reproducirMovimientos(window);
		pintarImagenNivelCompleto = true;
	}
}

bool Partida::realizarMovimiento(Tubo *&tuboRecibe, RenderWindow*& window) {
	bool seRealizo = true;;
	Tubo* aux = tuboRecibe;
	
	if (aux->getTope() != NULL) {
		CircleShape* circuloTopeRecibe = aux->getTope()->getCircle();
		CircleShape* circuloTopeEnvia = tuboSeleccionado->getTope()->getCircle();
		
		if (aux->getCantidadActual() < 4 && circuloTopeRecibe->getFillColor() == circuloTopeEnvia->getFillColor()) {
			pushMovimiento();
			aux->push(tuboSeleccionado->pop());
			nivel->setMovimientos();
			if (mov < 5)mov++;

			if (nivel->nivelGanado()) { 
				pintarImagenNivelCompleto = true;
				nivelCompleto = true;
				enJuego = false;
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
		if (mov < 5)mov++;
		aux->push(tuboSeleccionado->pop());
		nivel->setMovimientos();

	}

	tuboSeleccionado = NULL;
	return seRealizo;


}
void Partida::clickSiguienteNivel(int xm, int ym) {

	if (xm > 87 && xm < 515 && ym > 326 && ym < 416) {
		
		movimientos = NULL;
		nivel->setIsCompleto(true);
		nivelCompleto = false;
		enRepeticion = false;
		pintarImagenNivelCompleto = false;
		iniCoordenas = NULL;
		enJuego = true;
		nivel = new Nivel(nivel->getNumero() + 1);
	}
}
void Partida::nivelGanado(RenderWindow *&window) {
	
	reproducirMovimientos(window);
	nivel->setIsCompleto(true);
	
}

void Partida::reproducirMovimientos(RenderWindow *&window) {
	
	
	int cont = 0;
	Nivel* aux = movimientos;
	while (aux != NULL) {
		cont++;
		if (aux->getAnt() == NULL) break;
		aux = aux->getAnt();

	}

	while (aux != NULL) {
		cont--;
		
		nivel = aux;
		window->clear(Color::Color(25, 43, 26, 255));
		pintarPartidaGeneral(window);
		window->display();
		Sleep(1000);
		aux = aux->getSig();

	}
	


}

void Partida::guardarCoordenadasMovimiento(int x, int y) {
	
	
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