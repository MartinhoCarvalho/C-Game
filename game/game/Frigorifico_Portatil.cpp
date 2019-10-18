#include "Frigorifico_Portatil.h"


Frigorifico_Portatil::Frigorifico_Portatil(void):Energia(){
	this->energia_energetica = 400;
	this->nome = "Frigorifico_Portatil";
}

Frigorifico_Portatil::Frigorifico_Portatil(const Frigorifico_Portatil &ob):Energia(){
	this->nome =ob.nome;
	this->energia_energetica = ob.energia_energetica;
}

Frigorifico_Portatil::~Frigorifico_Portatil(void){
}

int Frigorifico_Portatil::retorna_energia_energetica(void){
	return this->energia_energetica;
}

string Frigorifico_Portatil::retorna_nome_da_energia(void){
	return this->nome;
}

Energia *Frigorifico_Portatil::clone(){
	return new Frigorifico_Portatil(*this);
}