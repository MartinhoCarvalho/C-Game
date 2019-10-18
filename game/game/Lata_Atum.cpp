#include "Lata_Atum.h"

Lata_Atum::Lata_Atum(void):Energia(){
	this->nome ="Lata_Atum";
	this->energia_energetica = 80;
}

Lata_Atum::Lata_Atum(const Lata_Atum &ob):Energia(){
	this->nome =ob.nome;
	this->energia_energetica = ob.energia_energetica;	
}

Lata_Atum::~Lata_Atum(void){
}

int Lata_Atum::retorna_energia_energetica(void){
	return this->energia_energetica;
}

string Lata_Atum::retorna_nome_da_energia(void){
	return this->nome;
}


Energia *Lata_Atum::clone(){
	return new Lata_Atum(*this);
}