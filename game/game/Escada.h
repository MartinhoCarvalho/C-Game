#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Bloco.h"
using namespace std;

class Escada:public Bloco{
	private:
	
	public:
		Escada(void);
		Escada(const Escada &ob);
		~Escada(void);
		/*################  Polimorfismo ################################*/
		virtual bool get_permite_mineiro(void);
		//(operator=) com polimorfismo
		virtual bool Puxa(void);
		virtual bool escava(void);
		virtual Escada &operator=(const Bloco &b);
		virtual Bloco *duplica();
		virtual void incrementa_toque_picareta(void);
		virtual int get_toques_de_picareta_recebidos(void);
		virtual void recebe_toque(int &valor);
		virtual int retorna_peso(void);
		virtual int retorna_valor(void) ;
		virtual int retorna_numero_toques_recebidos(void);
		virtual int retorna_numero_toques_ate_partir(void);
		virtual int da_energia(void);
		/*################  Polimorfismo ################################*/
};

