#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Mochila.h"
using namespace std;

class Mochila_pro:public Mochila{

public:
	Mochila_pro(void);
	Mochila_pro(const Mochila_pro &ob);
	~Mochila_pro(void);
	//########################## POLIMORFISMO ##########################
	//########################## Encapsulamento ########################
	virtual Mochila *clone();
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

