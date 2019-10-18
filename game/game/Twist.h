#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Bloco.h"
using namespace std;


class Twist:public Bloco{
	private:
		string n1;

	public:
		Twist(void);
		Twist(const Twist &ob);
		~Twist(void){ };
		//########################## Encapsulamento ##########################
		virtual void set_nome(string &nome){this->nome = nome;}
		virtual string get_nome(void){return this->nome;};
		virtual void set_aspecto(string &str ){ this->aspecto = str;}
		virtual void set_pode_escavar(bool &str){  this->pode_escavar = str;}
		virtual void set_cai_espaco_vazio(bool &str){  this->cai_no_espaco_vazio = str;}
		virtual void set_numero_toques_ate_partir(int &numero){ this->toques_picareta_ate_partir = numero;}
		virtual void set_numero_toques_recebidos(int &numero){ this->toques_picareta_ate_partir = numero;}
		virtual void set_energia_a_dar(int &numero){ this->energia_a_dar_ou_retirar = numero;}
		virtual void set_peso(int &numero){ this->peso = numero;}
		virtual void set_valor(int &numero){ this->valor = numero;}
		//########################## Encapsulamento ##########################
		/*################  Polimorfismo ################################*/
		virtual bool get_permite_mineiro(void);
		//(operator=) com polimorfismo
		virtual Twist &operator=(const Bloco &b);
		virtual Bloco *duplica();
		virtual bool escava(void);
		virtual bool desaba(void);
		//puxa
		virtual bool Puxa(void);
		virtual void incrementa_toque_picareta(void);
		virtual int get_toques_de_picareta_recebidos(void);
		virtual void recebe_toque(int &valor);
		virtual int retorna_peso(void);
		virtual int retorna_valor(void) ;
		virtual int retorna_numero_toques_recebidos(void);
		virtual int retorna_numero_toques_ate_partir(void);
		virtual int da_energia(void);
		virtual void cor(void){ Consola c; c.setTextColor(c.PRETO);}
		virtual bool coloca_no_Inicio(void);
		/*################  Polimorfismo ################################*/
};

