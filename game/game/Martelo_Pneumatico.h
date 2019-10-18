#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Picareta.h"
using namespace std;

class Martelo_Pneumatico:public Picareta{

	public:
		Martelo_Pneumatico(void);
		Martelo_Pneumatico(const Martelo_Pneumatico &ob);
		~Martelo_Pneumatico(void);
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

