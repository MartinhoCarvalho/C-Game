#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include "Consola.h"
using namespace std;



class Bloco{	
	
	protected:
		string nome;
		string  aspecto;// aqui e uma string e devolve o objecto ja feito
		bool pode_escavar;
		bool permite_mineiro;
		bool cai_no_espaco_vazio;
		int toques_picareta_ate_partir;
		int toques_picareta_recebidos;
		int energia_a_dar_ou_retirar;
		int peso, valor;
	public:
		Bloco(void){};
		virtual ~Bloco(void);
		string getAspecto(int x);
		string outputBloco(void);
		char getCaracter(void);
		void desenha(int x, int y , Consola c, bool visivel);
		void desenha_coord_consola(int x_consola,int y_consola, Consola c, bool visivel);
		//####################### polimorfismo #############################################
		
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
		virtual void incrementa_toque_picareta(void);
		virtual int get_toques_de_picareta_recebidos(void);
		virtual void recebe_toque(int &valor);
		virtual int retorna_peso(void) = 0;
		virtual int retorna_valor(void) = 0;
		virtual void  cor(void){}
		//metodo para polimorfismo 
		virtual int retorna_numero_toques_recebidos(void) = 0;
		virtual int retorna_numero_toques_ate_partir(void) = 0;
		virtual bool get_permite_mineiro(void) = 0;
		virtual Bloco *duplica() = 0;
		virtual bool Puxa(void) = 0;
		virtual bool desaba(void);
		virtual bool escava(void) = 0;
		virtual int da_energia(void) = 0;
		//(operator=) com polimorfismo
		virtual Bloco &operator=(const Bloco &b);
		virtual bool coloca_no_Inicio(void){return false; }//este metodo e so para o twist
		//####################### polimorfismo #############################################
};
