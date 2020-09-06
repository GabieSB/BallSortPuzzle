#include "Tubo.h"
Tubo::Tubo() {
	pilaBolas = NULL;
	sig = NULL;
	ant = NULL;
	cargar_tubo();
}

void Tubo::push( Bola *bola) {
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

Bola* Tubo::pop() {
	Bola* nodoEliminado = pilaBolas;
	if (pilaBolas != NULL) {

		pilaBolas->setSig(NULL);
		pilaBolas= pilaBolas->getAnt();

	}
	return nodoEliminado;
}

void Tubo::cargar_tubo() {

}

void Tubo::dibujar_bola() {

}