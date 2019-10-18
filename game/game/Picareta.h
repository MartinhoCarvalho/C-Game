#pragma once
# include <iostream>
# include <sstream>
# include <string>


using namespace std;

class Picareta{
	protected:
		int toques,custo_energetico;
		string nome;
	public:
		Picareta(void){ }
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_toques(int &numero){ this->toques = numero;}
		virtual void set_custo_energetico(int &numero){ this->custo_energetico = numero;}	
		virtual void set_nome(string &nome){ this->nome = nome;};
		virtual int retorna_numero_toques(void) = 0;
		virtual int retorna_custo_energetico(void) = 0;
		virtual string retorna_nome_utensilio(void) = 0;
		virtual Picareta *clone() = 0;
		virtual ~Picareta(void);
		//########################## Encapsulamento ########################
		//########################## POLIMORFISMO ##########################
};

