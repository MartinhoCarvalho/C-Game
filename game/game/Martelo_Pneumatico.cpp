#include "Martelo_Pneumatico.h"


Martelo_Pneumatico::Martelo_Pneumatico(void){
	this->toques = 4;
	this->custo_energetico = 1;
	this->nome = "Martelo_Pneumatico";
}


Martelo_Pneumatico::Martelo_Pneumatico(const Martelo_Pneumatico &ob){
	this->nome= ob.nome;
	this->toques = ob.toques;
	this->custo_energetico = ob.custo_energetico;
}

Martelo_Pneumatico::~Martelo_Pneumatico(void){
}

int Martelo_Pneumatico::retorna_custo_energetico(void){
	return this->custo_energetico;
}

int Martelo_Pneumatico::retorna_numero_toques(void){
	return this->toques;
}


string Martelo_Pneumatico::retorna_nome_utensilio(void){
	return this->nome;
}

Picareta *Martelo_Pneumatico::clone(){
	return new Martelo_Pneumatico(*this);
}


