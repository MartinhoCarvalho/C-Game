#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Mochila.h"
using namespace std;


class Mochila_Simples:public Mochila{
	

	public:
		Mochila_Simples(void);
		Mochila_Simples(const Mochila_Simples &ob);
		~Mochila_Simples(void);
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_nome(string &nome){this->nome = nome;}
		virtual void set_capacidade(int &numero){this->capacidade = numero;}
		virtual Mochila *clone();
		virtual int retorna_capacidade(void);
		virtual string retorna_nome_mochila(void);
		virtual void carrega_mochila(int &peso,int &valor);
		virtual int return_peso(void);
		virtual int return_valor(void);
		virtual void set_valor(int &valor);
		virtual void set_peso(int &peso);
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
};

