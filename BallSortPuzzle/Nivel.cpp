#include "Nivel.h"

Nivel::Nivel(int num) {
	iniTubos = NULL;
	numero = num;
	Global::getInstance().setNivel(num);
	if (num == 1) {
		cantidadTubo = 3;
	}
	else {
		cantidadTubo = numero+3;
	}

	isPassed = false;
	movimientos = 0;

	cargarNivel(num);
	
}

Nivel::Nivel(const Nivel& nivel) {
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
bool Nivel::isCompleto() {
	return isPassed;
}
void Nivel::setIsCompleto(bool estado) {
	isPassed = estado;
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
void Nivel::cargarNivel(int num) {
	Global::getInstance().setNivel(num);

	if (num == 1) {
		nivel1();
	}
	else if(num == 2){
		nivel2();
    }
	else if (num == 3) {
		nivel3();
	}
	else if (num == 4) {
		nivel4();
	}
	else if (num == 5) {
		nivel5();
	}
	else {
		cout << "JUEGO TERMINADO" << endl;
	}


}
void Nivel::nivel1() {
	string tuboColores1[5] = { "azul", "rojo","azul", "rojo" };
	string tuboColores2[5] = { "rojo", "azul","rojo", "azul" };

	generarTubo(200, 300, tuboColores1);
	generarTubo(270, 300, tuboColores2);
	Tubo* tubo1 = new Tubo(340, 300);
	agregarTubo(tubo1);
}

void Nivel::nivel2() {


	string tuboColores1[5] = { "azul", "amarillo","rojo", "azul" };
	string tuboColores2[5] = { "amarillo", "amarillo","rojo", "azul" };
	string tuboColores3[5] = { "rojo",  "azul" ,"amarillo", "rojo" };

	generarTubo(200, 220, tuboColores1);
	generarTubo(275, 220, tuboColores2);
	generarTubo(350, 220, tuboColores3);
	Tubo* tubo1 = new Tubo(238, 407);
	Tubo* tubo2 = new Tubo(313, 407);
	agregarTubo(tubo1);
	agregarTubo(tubo2);
}

void Nivel::nivel3() {

	string tuboColores1[5] = { "azul", "amarillo","rojo", "azul"};
	string tuboColores2[5] = { "morado", "amarillo","amarillo", "azul"};
	string tuboColores3[5] = { "rojo",  "morado" ,"azul", "morado"};
	string tuboColores4[5] = { "rojo",  "amarillo" ,"morado", "rojo"};

	generarTubo(200, 220, tuboColores1);
	generarTubo(275, 220, tuboColores2);
	generarTubo(348, 220, tuboColores3);
	generarTubo(200, 408, tuboColores4);
	Tubo* tubo1 = new Tubo(275, 390);
	Tubo* tubo2 = new Tubo(348, 390);
	agregarTubo(tubo1);
	agregarTubo(tubo2);
}
void Nivel::nivel4() {


	string tuboColores1[5] = { "verde", "amarillo","azul", "rosado" };
	string tuboColores2[5] = { "amarillo", "verde","azul", "rosado" };
	string tuboColores3[5] = { "rosado",  "rojo" ,"amarillo", "rojo" };
	string tuboColores4[5] = { "amarillo",  "rosado" ,"rojo", "azul" };
	string tuboColores5[5] = { "verde",  "verde" ,"rojo", "azul" };

	generarTubo(165, 220, tuboColores1);
	generarTubo(237, 220, tuboColores2);
	generarTubo(307, 220, tuboColores3);
	generarTubo(380, 220, tuboColores4);
	generarTubo(198, 410, tuboColores5);
	Tubo* tubo1 = new Tubo(273, 410);
	Tubo* tubo2 = new Tubo(345, 410);
	agregarTubo(tubo1);
	agregarTubo(tubo2);
}
void Nivel::nivel5() {


	string tuboColores1[5] = { "rojo", "morado","azul", "rosado" };
	string tuboColores2[5] = { "amarillo", "verde","azul", "morado" };
	string tuboColores3[5] = { "rosado",  "rojo" ,"amarillo", "rosado" };
	string tuboColores4[5] = { "morado",  "amarillo" ,"rojo", "azul" };
	string tuboColores5[5] = { "verde",  "verde" ,"rojo", "azul" };
	string tuboColores6[6] = { "verde",  "amarillo" ,"rosado", "morado" };

	generarTubo(200, 220, tuboColores1);
	generarTubo(277, 220, tuboColores2);
	generarTubo(350, 220, tuboColores3);
	generarTubo(425, 220, tuboColores4);
	generarTubo(200, 410, tuboColores5);
	generarTubo(274, 410, tuboColores6);
	Tubo* tubo1 = new Tubo(350, 410);
	Tubo* tubo2 = new Tubo(425, 410);
	agregarTubo(tubo1);
	agregarTubo(tubo2);
}

void Nivel::generarTubo(int x, int y, string colores[]) {
	Tubo* tubo = new Tubo(x, y);
	for (int i = 0; i < 4; i++) {

		sf::CircleShape* esfera = new CircleShape();
		esfera->setRadius(10);
		esfera->setFillColor(getColor(colores[i]));
		cout << "Color " << colores[i] << endl;

		Bola* bola = new Bola(esfera);
		bola->setColor(colores[i]);

		tubo->push(bola);


	}

	agregarTubo(tubo);
}
Color Nivel::getColor(string name) {
	if (name == "rojo") {
		return Color::Color(255, 87, 51);
	}
	else if(name == "amarillo") {
		return Color::Color(237, 215, 31);
	}
	else if(name == "papaya") {
		return Color::Color(225, 171, 129);
	}
	else if (name == "azul") {
		return Color::Color(60, 117, 202);
	}
	else if (name == "verde") {
		return Color::Color(89, 197, 87);
	}
	else if (name == "negro") {
		return Color::Color(7, 20, 7);
	}
	else if (name == "morado") {
		return Color::Color(124, 38, 180);
	}
	else if (name == "rosado") {
		return Color::Color(212, 75, 187);
	}
	else if (name == "gris") {
		return Color::Color(71, 68, 73);
	}
	else if (name == "cafe") {
		return Color::Color(284, 67, 61);
	}
	else if (name == "naranja") {
		return Color::Color(218, 94, 47);
	}
	/*else {
		return Color::Color(218, 94, 47);
	}*/
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
	int cont = 0;


	while (aux != NULL) {
		
		if (aux->getCantidadActual() == 4) {
			cont++;
		}
		else {
			if (aux->getCantidadActual() > 0)  return false;
		}
		aux = aux->getSig();
	}
	cout << "numero - 2"<<cantidadTubo-2 << endl;

	if (numero == 0 && cont == 3 || numero > 1 && cont == cantidadTubo - 2) {
		return true;
	}
	
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

 int Nivel::getNumero() {
	 return numero;
 }

 void Nivel::guardarNivel() {
	 ofstream archivo;
	 archivo.open("partidas/prueba.txt", ios::out);

	 archivo << "#"<<this->numero<< ">"<<this->cantidadTubo<<endl;
	 Tubo* aux = iniTubos;
	 while (aux!=NULL)
	 {
		 archivo << "[" ;
		 if (aux->getTope() != NULL) {
			 archivo << "{" << aux->getCantidadActual()<<"}" << endl;
			 Bola* auxTope = aux->getTope();

			 while (auxTope!=NULL)
			 {
				 archivo << auxTope->getColor() << endl;

				 auxTope = auxTope->getAnt();

			 }

			 
		}
		 archivo << "]" << endl;
		 aux = aux->getSig();
	 }
	


	 

	archivo.close();


 }
 /*101 , 337
138 , 336
100 , 131
140 , 133*/