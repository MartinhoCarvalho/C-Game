#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Picareta.h"
using namespace std;

class Picareta_simples:public Picareta{

	public:
		Picareta_simples(void);
		Picareta_simples(const Picareta_simples &ob);
		~Picareta_simples(void);
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_toques(int &numero){ this->toques = numero;}
		virtual void set_custo_energetico(int &numero){ this->custo_energetico = numero;}	
		virtual void set_nome(string &nome){ this->nome = nome;}
		virtual int retorna_numero_toques(void);
		virtual int retorna_custo_energetico(void);
		virtual string retorna_nome_utensilio(void);
		virtual Picareta *clone();
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
};

