#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Mochila.h"
using namespace std;


class Mochila_heavy_duty:public Mochila{
	
	public:
		Mochila_heavy_duty(void);
		Mochila_heavy_duty(const Mochila_heavy_duty &ob);
		~Mochila_heavy_duty(void);
		virtual Mochila *clone();
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_nome(string &nome){this->nome = nome;}
		virtual void set_capacidade(int &numero){this->capacidade = numero;}
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

