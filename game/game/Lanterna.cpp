#include "Lanterna.h"


Lanterna::Lanterna(void):Luz(){
	this->nome ="Lanterna";
	this->raio_visao = 2;
}


Lanterna::Lanterna(const Lanterna &ob):Luz(){
	this->nome = ob.nome;
	this->raio_visao = ob.raio_visao;
}

Lanterna::~Lanterna(void){
}


int Lanterna::retorna_raio_visao(void){
	return this->raio_visao;
}

string Lanterna::retorna_nome_luz(void){
	return this->nome;
}


Luz *Lanterna::clone(){
	return new Lanterna(*this);
}
