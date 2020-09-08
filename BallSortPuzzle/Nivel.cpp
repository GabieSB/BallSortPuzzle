#include "Nivel.h"

Nivel::Nivel(int num) {
	iniTubos = NULL;
	numero = numero;
	cantidadTubo = (num == 1) ? 3 : num + 3;
	isPassed = false;
	movimientos = 0;
	
	cargarNivel();
}

Nivel::Nivel(const Nivel& nivel) {
	cout << "se usa el constructor de copia" << endl;
	numero = nivel.numero;
	cantidadTubo = nivel.cantidadTubo;
	isPassed = nivel.isPassed;
	movimientos = nivel.movimientos;
	iniTubos = NULL;
	//copiar tubos
	Tubo* aux = new Tubo();
	*aux = *nivel.iniTubos;
	while (aux != NULL) {
		Tubo* aux2 = new Tubo(*aux);
		agregarTubo(aux2);
		aux = aux->getSig();
	}
	


}

void Nivel::setSig(Nivel* sig) {
	this->sig = sig;
}
void Nivel::setAnt(Nivel* ant) {
	this->ant = ant;
}

Nivel* Nivel::getSig() {
	return sig;
}
Nivel* Nivel::getAnt() {
return ant;
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
void Nivel::cargarNivel() {

	nivel1();

}
void Nivel::nivel1() {
	
	Tubo* tubo1 = new Tubo(100, 300);

	for (int i = 0; i < 5; i++) {
		cout << "se ke pone la posicion a las esferas" << endl;
		sf::CircleShape *esfera = new CircleShape();
		esfera->setRadius(20);
		if (i % 2 == 0) esfera->setFillColor(Color::Blue);
		else esfera->setFillColor(Color::Magenta);
	
		
		Bola* bola = new Bola(esfera);

		tubo1->push(bola);

		
	}

	//tubo1->dibujarTubo(window);
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

	//tubo2->dibujarTubo(window);
	agregarTubo(tubo2);
	Tubo* tubo3 = new Tubo(500, 300);
	agregarTubo(tubo3);
}

void Nivel::dibujarNivel(RenderWindow *& ventana) {

	Tubo* aux = iniTubos;

	while (aux != NULL) {
		aux->dibujarTubo(ventana);

		aux = aux->getSig();
	}
	
}

bool Nivel::nivelGanado() {
	Tubo* aux = iniTubos;

	int tubosParaGanar = cantidadTubo = (numero == 1) ? 2 : numero - 2;
	int cont = 0;

	while (aux != NULL) {
		
		if (aux->getCantidadActual() == 5) {
			cont++;
		}
		else {
			if (aux->getCantidadActual() > 0)  return false;
		}
		aux = aux->getSig();
	}

	if (cont == tubosParaGanar) return true;
}

 Tubo* Nivel::getTubos() {
	 return iniTubos;
 }

 void Nivel::setMovimientos() {
	 movimientos++;
 }
 int Nivel::getMovimientos() {
	 return movimientos;

 }
 void Nivel::setTubos(Tubo *tubos) {
	 iniTubos = tubos;
 }
 /*101 , 337
138 , 336
100 , 131
140 , 133*/