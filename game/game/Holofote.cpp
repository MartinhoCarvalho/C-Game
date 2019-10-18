#include "Holofote.h"


Holofote::Holofote(void):Luz(){
	this->nome = "Holofote";
	this->raio_visao = 3;
}


Holofote::Holofote(const Holofote &ob):Luz(){
	this->nome = ob.nome;
	this->raio_visao = ob.raio_visao;
}

Holofote::~Holofote(void){
}


string  Holofote::retorna_nome_luz(void){
	return this->nome;
}

int Holofote::retorna_raio_visao(void){
	return this->raio_visao;
}

Luz *Holofote::clone(){
	return new Holofote(*this);
}