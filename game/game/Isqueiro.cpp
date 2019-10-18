#include "Isqueiro.h"


Isqueiro::Isqueiro(void):Luz(){
	this->nome ="Isqueiro";
	this->raio_visao = 1;
}


Isqueiro::Isqueiro(const Isqueiro &ob):Luz(){
	this->nome = ob.nome;
	this->raio_visao = ob.raio_visao;
}

Isqueiro::~Isqueiro(void){
}

int Isqueiro::retorna_raio_visao(void){
	return this->raio_visao;
}

string Isqueiro::retorna_nome_luz(void){
	return this->nome;
}


Luz *Isqueiro::clone(){
	return new Isqueiro(*this);
}