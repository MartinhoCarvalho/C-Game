#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Consola.h"
# include "Bloco.h"
using namespace std;

class Dinamite_bloco:public Bloco{

public:
	Dinamite_bloco(void);
	~Dinamite_bloco(void);
	Dinamite_bloco(const Dinamite_bloco &ob);
	/*################  Polimorfismo ################################*/
	//metodo para polimorfismo
	virtual bool Puxa(void);
	virtual bool get_permite_mineiro(void);
	//operator =
	virtual Dinamite_bloco &operator=(Bloco &b);//operator programado derivado 
	virtual Bloco *duplica();
	virtual bool escava(void);
	virtual void incrementa_toque_picareta(void);
	virtual int get_toques_de_picareta_recebidos(void);
	virtual void recebe_toque(int &valor);
	virtual int retorna_peso(void);
	virtual int retorna_valor(void) ;
	virtual int retorna_numero_toques_recebidos(void);
	virtual int retorna_numero_toques_ate_partir(void);
	virtual int da_energia(void);
	virtual bool coloca_no_Inicio(void){return false; }//este metodo e so para o twist
	/*################  Polimorfismo ################################*/
};

