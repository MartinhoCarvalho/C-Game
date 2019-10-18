#pragma once
# include <iostream>
# include <sstream>
# include <string>

using namespace std;


class Mochila{
	protected:
		string nome;
		int capacidade,peso,valor;
	public:
		Mochila(void){this->peso = 0;this->valor = 0;}
		~Mochila(void);
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_nome(string &nome){this->nome = nome;}
		virtual void set_capacidade(int &numero){this->capacidade = numero;}
		virtual int retorna_capacidade(void) = 0;
		virtual string retorna_nome_mochila(void) = 0;
		virtual void carrega_mochila(int &peso,int &valor) = 0;
		virtual int return_peso(void) = 0;
		virtual int return_valor(void) = 0;
		virtual void set_valor(int &valor) = 0;
		virtual void set_peso(int &peso) = 0;
		virtual Mochila *clone() = 0;
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
};

