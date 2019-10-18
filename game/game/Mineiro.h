#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include <fstream>
# include <vector>
# include <cstdlib>
# include <cstddef>	
# include <sstream>
//# include "Preco.h"
# include "Consola.h"
# include "Utensilios.h"
# define ESCADA 2
class Mina;//tenho que chamar aqui a class Mina para fazer polimorfismo
using namespace std;


class Mineiro{
	private:
		int dinheiro;
		int cordx, cordy;
		int peso, raio_visao,pedras_ecavadas;
		Mina *mina;
		Utensilios utensilios;
		float vida;
	
	public:
		Mineiro(void);
		Mineiro(Mineiro &ob);
		Mineiro &operator=(Mineiro &ob);
		Mineiro &operator=(const Mineiro &ob);
		~Mineiro(void);
		// ################# Metodos que devolvem informaçao do Mineiro  ###############################
		void set_n_pedras_escavadas(void);
		int get_numero_blocos_escavados(void);
		int return_cordx(void);
		void set_cordx_cordy(int &x ,int &y);
		int return_cordy(void);
		void retira_vida(float &vida);
		void retira_vida_escada(void);
		void actualiza_vida(float &vida);
		void insert_moedas(int valor);
		void soma_moedas(void);
		void actualiza_valores_mochila(void);
		void retira_moedas(int valor);
		int return_raio_visao(void);
		float return_energia_utensilio(void);
		int return_numero_recargas(void);
		int devolve_numero_moedas(void);
		float devolve_energia_mineiro(void);
		void desenha(int x, int y,int raio, char car, Consola c);
		void desenha_default(int x , int y, char car, Consola c);
		void desenha_escada(int x,int y,char car,Consola c);
		void desenha_viga (int x,int y,char car,Consola c);
		void desenha_dinamite (int x,int y,char car,Consola c);
		bool a_onde_estou(int lin);
		void da_martelada(int &x,int &y);
		void carrega_mochila(int &peso, int &valor);
		void recarrega_vida(int &vida);
		//informacao sobre os utenslios
		int numero_marteladas(void);
		int retorna_peso(void);
		int retorna_capacidade(void);
		void aplica_escada(int &valor);
		void aplica_viga(int &valor);
		int verifica_cordenadas(int &x, int &y);
		void utliza_vida_extra(void);
		void retira_dinamite(void);
		int return_vida_Extra(void);
		int return_DInamite(void);
		int return_valor(void);
		int return_paraquedes(void);
		void paraquedas_decrementa(void);
		string tipo_picareta(void);
		string tipo_luz(void);
		string tipo_energia(void);
		string tipo_mochila(void);
		string recargas(void);
		string Dinamite(void);
		string Vida_extra(void);
		string Paraquedas(void);	
		void mineiro_da_uma_martelada_no_bloco(int &x, int &y);
		void utiliza_ramdon(void);
		int get_ramdon(void);
		// ################# Metodos que devolvem informaçao do Mineiro  ###############################

		//################### Comandos ################################################################
		void teletransporte(int x , int y);
		void compra_utensilios(string nome, string &valor);
		//################### Comandos ################################################################

		//################# coloca a energia a com o valor do utensilio ##############################
		void iguala_energia(void);
		//################# coloca a energia a com o valor do utensilio ##############################

		//################# metodos de polimorfismo ###############################
		void set_mina(Mina &mina);
		bool pede_permisao_mina(int poscol,int poslin);

		//operador++
		//Mineiro &operator++(int n);
		//################# metodos de polimorfismo ###############################
};