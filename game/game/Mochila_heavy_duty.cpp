#include "Mochila_heavy_duty.h"


Mochila_heavy_duty::Mochila_heavy_duty(void):Mochila(){
	this->nome = "Mochila_heavy_duty";
	this->capacidade = 35;
	this->peso = 0;
}

Mochila_heavy_duty::Mochila_heavy_duty(const Mochila_heavy_duty &ob):Mochila(){
	this->nome = ob.nome;
	this->capacidade =ob.capacidade ;
}


Mochila_heavy_duty::~Mochila_heavy_duty(void){
}

Mochila *Mochila_heavy_duty::clone(){
	return new  Mochila_heavy_duty (*this);
}


int Mochila_heavy_duty::return_peso(void){
	return this->peso;
}

int Mochila_heavy_duty::retorna_capacidade(void){
	return this->capacidade;
}


string Mochila_heavy_duty::retorna_nome_mochila(void){
	ostringstream str;
	str << this->nome;
	return str.str();
}

int Mochila_heavy_duty::return_valor(void){
	return this->valor;
}

void Mochila_heavy_duty::carrega_mochila(int &peso,int &valor){
	int total = peso+this->peso;
	if(total < this->retorna_capacidade()){
		this->peso+=peso;
		this->valor+=valor;
	}
}

void Mochila_heavy_duty::set_valor(int &valor){
	this->valor = valor;
}

void Mochila_heavy_duty::set_peso(int &valor){
	this->peso = valor;
}