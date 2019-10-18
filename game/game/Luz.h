#pragma once
# include <iostream>
# include <sstream>
# include <string>

using namespace std;

class Luz{
	protected:
		string nome;
		int raio_visao;
	public:
		Luz(void){}
		~Luz(void);
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
		virtual void set_nome(string &nome){this->nome = nome;}
		virtual void set_raio_visao(int &raio){this->raio_visao = raio;}
		virtual int retorna_raio_visao(void);
		virtual string retorna_nome_luz(void);
		virtual Luz *clone() = 0;
		//########################## POLIMORFISMO ##########################
		//########################## Encapsulamento ########################
};

