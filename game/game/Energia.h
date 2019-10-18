#pragma once
# include <iostream>
# include <sstream>
# include <string>

using namespace std;



class Energia{
	protected:
		string nome;
		int energia_energetica;
	public:
		Energia(void){}
		~Energia(void);
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_nome(string &nome){this->nome = nome;}
		virtual void set_energia_energetica(int &numero) { this->energia_energetica = numero;}
		virtual int retorna_energia_energetica(void);
		virtual string retorna_nome_da_energia(void); 
		virtual Energia *clone() = 0;
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
};

