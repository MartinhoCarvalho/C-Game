#include "Mochila_pro.h"


Mochila_pro::Mochila_pro(void):Mochila(){
	this->capacidade = 25;
	this->nome = "Mochila_pro";
	this->peso = 0;
}


Mochila_pro::Mochila_pro(const Mochila_pro &ob):Mochila(){
	this->nome = ob.nome;
	this->capacidade =ob.capacidade ;
}

Mochila_pro::~Mochila_pro(void){
}



Mochila *Mochila_pro::clone(){
	return new Mochila_pro(*this);
}


int Mochila_pro::return_peso(void){
	return this->peso;
}

int Mochila_pro::retorna_capacidade(void){
	return this->capacidade;
}


string Mochila_pro::retorna_nome_mochila(void){
	ostringstream str;
	str << this->nome;
	return str.str();
}

int Mochila_pro::return_valor(void){
	return this->valor;
}

void Mochila_pro::carrega_mochila(int &peso,int &valor){
	int total = peso+this->peso;
	if(total < this->retorna_capacidade()){
		this->peso+=peso;
		this->valor+=valor;
	}
}

void Mochila_pro::set_valor(int &valor){
	this->valor = valor;
}

void Mochila_pro::set_peso(int &valor){
	this->peso = valor;
}

