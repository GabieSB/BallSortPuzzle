#include "Nivel.h"

Nivel::Nivel(int num) {
	iniTubos = NULL;
	numero = numero;
	cantidadTubo = (num == 1) ? 3 : num + 3;
	isPassed = false;
	

}

void Nivel::agregarTubo(Tubo *&tubo) {
	if (iniTubos == NULL) {
		tubo->setAnt(NULL);
		tubo->setSig(NULL);
		iniTubos = tubo;
	}
	else {

		Tubo* aux = iniTubos;

		while (aux->getSig() != NULL) {
			aux = aux->getSig();
		}

		tubo->setAnt(aux);
		tubo->setSig(NULL);
		aux->setSig(tubo);
		
	}
}
void Nivel::cargarNivel(RenderWindow *& window) {

	nivel1(window);

}
void Nivel::nivel1(RenderWindow*& window) {
	
	Tubo* tubo1 = new Tubo(100, 300);

	for (int i = 0; i < 5; i++) {

		sf::CircleShape *esfera = new CircleShape();
		esfera->setRadius(20);
		if (i % 2 == 0) esfera->setFillColor(Color::Blue);
		else esfera->setFillColor(Color::Magenta);
		esfera->setPosition(100, 150);

		Bola* bola = new Bola(esfera);

		tubo1->push(bola);

		
	}

	tubo1->dibujarTubo(window);
	agregarTubo(tubo1);



	Tubo* tubo2 = new Tubo(300, 300);

	for (int i = 0; i < 5; i++) {

		sf::CircleShape* esfera = new CircleShape();
		esfera->setRadius(20);
		if (i % 2 == 0) esfera->setFillColor(Color::Magenta);
		else esfera->setFillColor(Color::Blue);
		Bola* bola = new Bola(esfera);

		tubo2->push(bola);



	}

	tubo2->dibujarTubo(window);
	agregarTubo(tubo2);
}

 Tubo *Nivel::esClickEnTubo(int xm, int ym) {

	 int diametroPorBola = 42;
	 int x = 100;
	 int y = 300;


	 if (xm > x && xm < x + 40 && ym < y - 40 && y > 200) {
		 cout << "Es click en tubo" << endl;
		 return iniTubos;
	 }

	 return NULL;
 }

 Tubo* Nivel::getTubos() {
	 return iniTubos;
 }
 /*101 , 337
138 , 336
100 , 131
140 , 133*/