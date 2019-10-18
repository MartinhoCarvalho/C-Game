#include "Lancheira_campismo.h"


Lancheira_campismo::Lancheira_campismo(void):Energia(){
	this->energia_energetica = 160;
	this->nome = "Lancheira_campismo";
}

Lancheira_campismo::Lancheira_campismo(const Lancheira_campismo &ob):Energia(){
	this->nome =ob.nome;
	this->energia_energetica = ob.energia_energetica;	
}


Lancheira_campismo::~Lancheira_campismo(void){

}


int Lancheira_campismo::retorna_energia_energetica(void){
	return this->energia_energetica = 160;
}

string Lancheira_campismo::retorna_nome_da_energia(void){
	return this->nome = "Lancheira_campismo";
}

Energia *Lancheira_campismo::clone(){
	return new Lancheira_campismo(*this);
}