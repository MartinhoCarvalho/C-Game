#include "Picareta_simples.h"


Picareta_simples::Picareta_simples(void):Picareta(){
	this->custo_energetico = 1;
	this->toques = 1;
	this->nome = "Picareta_Simples";
}



Picareta_simples::Picareta_simples( const Picareta_simples &ob):Picareta(){
	this->custo_energetico = ob.custo_energetico;
	this->toques = ob.toques;
	this->nome = ob.nome;
}

Picareta_simples::~Picareta_simples(void){
}


int Picareta_simples::retorna_custo_energetico(void){
	return this->custo_energetico;
}


int Picareta_simples::retorna_numero_toques(void){
	return this->toques;
}

string Picareta_simples::retorna_nome_utensilio(void){
	return this->nome;
}


Picareta  *Picareta_simples::clone(){
	return new Picareta_simples(*this);
}
