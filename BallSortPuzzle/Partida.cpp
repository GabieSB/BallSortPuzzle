#include "Partida.h"
#include "Nivel.h"


Partida::Partida() {
	nivel = NULL;
}

void Partida::cargarPartida(RenderWindow *&ventana) {

	
	nivel = new Nivel(1);
	nivel->cargarNivel(ventana);

}

Tubo* Partida::esClickEnTubo(int xm, int ym) {
	int x ;
	int y ;

	cout << "En partida" << endl;


	Tubo* aux = nivel->getTubos();
	while (aux != NULL) {
		x = aux->getX();
		y = aux->getY();
		if (xm > x && xm < x + 40 && ym < y + 40 && ym> y + 40 - (5 * 42)) {
			cout << "Es click en tubo" << endl;
			return aux;

		}

		aux = aux->getSig();
	}

	
}