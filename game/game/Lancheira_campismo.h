#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Energia.h"
using namespace std;
class Lancheira_campismo:public Energia{
	public:
		Lancheira_campismo(void);
		Lancheira_campismo(const Lancheira_campismo &ob);
		~Lancheira_campismo(void);
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_nome(string &nome){this->nome = nome;}
		virtual void set_energia_energetica(int &numero) { this->energia_energetica = numero;}
		virtual int retorna_energia_energetica(void);
		virtual string retorna_nome_da_energia(void); 
		virtual Energia *clone();
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################

};

