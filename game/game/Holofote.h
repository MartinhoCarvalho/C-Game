#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Luz.h"
using namespace std;

class Holofote:public Luz{
public:
	Holofote(void);
	Holofote(const Holofote &ob);
	~Holofote(void);
	//########################## POLIMORFISMO ##########################
	//########################## Encapsulamento ########################
	virtual void set_nome(string &nome){this->nome = nome;}
	virtual void set_raio_visao(int &raio){this->raio_visao = raio;}
	virtual int retorna_raio_visao(void);
	virtual string retorna_nome_luz(void);
	virtual Luz *clone();
};

