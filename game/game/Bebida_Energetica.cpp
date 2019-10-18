#include "Bebida_Energetica.h"


Bebida_Energetica::Bebida_Energetica(void):Energia(){
	this->energia_energetica = 120;
	this->nome = "Bebida_Energetica";
}

Bebida_Energetica::Bebida_Energetica(const Bebida_Energetica &ob):Energia(){
	this->nome =ob.nome;
	this->energia_energetica = ob.energia_energetica;	
}

Bebida_Energetica::~Bebida_Energetica(void){
}


int Bebida_Energetica::retorna_energia_energetica(void){
	return this->energia_energetica = 120;
}


string Bebida_Energetica::retorna_nome_da_energia(void){
	return this->nome = "Bebida_Energetica";
}


Energia *Bebida_Energetica::clone(){
	return new Bebida_Energetica(*this);
}