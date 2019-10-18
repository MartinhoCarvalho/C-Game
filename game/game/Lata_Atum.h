#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Energia.h"

using namespace std;
class Lata_Atum:public Energia{
	public:
		Lata_Atum(void);
		Lata_Atum(const Lata_Atum &ob);
		~Lata_Atum(void);
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

