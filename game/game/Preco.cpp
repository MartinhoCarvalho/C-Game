#include "Preco.h"


Preco::Preco(void){
}


Preco::~Preco(void){

}

void Preco::setNome(string nome){
	this->nome=nome;
}

void Preco::setPreco(int valor){
	this->preco = valor;
}

int Preco::getpreco(void){
	return this->preco;
}
string Preco::getnome(void){
	ostringstream str;

	str << this->nome;
	return str.str();
}


string Preco::tabela_precos(void){
	ostringstream str;

	str << this->nome << " " << this->preco;
	return str.str();
}
