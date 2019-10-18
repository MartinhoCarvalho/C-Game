#include "Picareta_Automatica.h"


Picareta_Automatica::Picareta_Automatica(void):Picareta(){
	this->nome= "Picareta_Automatica";
	this->toques = 2;
	this->custo_energetico = 1;
}


Picareta_Automatica::Picareta_Automatica(const Picareta_Automatica &ob):Picareta(){
	this->custo_energetico = ob.custo_energetico;
	this->toques = ob.toques;
	this->nome = ob.nome;
}

Picareta_Automatica::~Picareta_Automatica(void){
}


int Picareta_Automatica::retorna_custo_energetico(void){
	return this->custo_energetico;
}

int Picareta_Automatica::retorna_numero_toques(void){
	return this->toques;
}

string Picareta_Automatica::retorna_nome_utensilio(void){
	return this->nome;
}


Picareta *Picareta_Automatica::clone(){
	return new Picareta_Automatica(*this);
}

/*
virtual int retorna_numero_toques(void);
virtual int retorna_custo_energetico(void);
virtual string retorna_nome_utensilio(void);
*/