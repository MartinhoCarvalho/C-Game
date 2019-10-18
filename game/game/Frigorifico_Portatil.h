#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Energia.h"
using namespace std;
class Frigorifico_Portatil:public Energia{
public:
	Frigorifico_Portatil(void);
	Frigorifico_Portatil(const Frigorifico_Portatil &ob);
	~Frigorifico_Portatil(void);
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

