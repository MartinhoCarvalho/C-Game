#include "Mochila_Simples.h"


Mochila_Simples::Mochila_Simples(void):Mochila(){
	this->nome = "Mochila_Simples";
	this->capacidade = 15;
	this->peso = 0;
}

Mochila_Simples::Mochila_Simples(const Mochila_Simples &ob):Mochila(){
	this->nome = ob.nome;
	this->capacidade =ob.capacidade ;
}


Mochila_Simples::~Mochila_Simples(void){
}


Mochila *Mochila_Simples::clone(){
	return new Mochila_Simples(*this);
}


int Mochila_Simples::return_peso(void){
	return this->peso;
}

int Mochila_Simples::retorna_capacidade(void){
	return this->capacidade;
}


string Mochila_Simples::retorna_nome_mochila(void){
	ostringstream str;
	str << this->nome;
	return str.str();
}

int Mochila_Simples::return_valor(void){
	return this->valor;
}

void Mochila_Simples::carrega_mochila(int &peso,int &valor){
	int total = peso+this->peso;
	if(total < this->retorna_capacidade()){
		this->peso+=peso;
		this->valor+=valor;
	}
}

void Mochila_Simples::set_valor(int &valor){
	this->valor = valor;
}

void Mochila_Simples::set_peso(int &valor){
	this->peso = valor;
}




/*
virtual int retorna_capacidade(void);
virtual string retorna_nome_mochila(void);
*/