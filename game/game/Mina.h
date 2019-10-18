#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include <fstream>
# include "Consola.h"
# include <vector>
# include <cstddef>
# include <cstdlib>
# include <algorithm>
# include <dos.h>
//tipos de blocos 
# include "Pedra.h"
# include "Terreno_mole.h"
# include "Terreno_Duro.h"
# include "Terra_Aluminio.h"
# include "Terra_Carvao.h"
# include "Terra_Ferro.h"
# include "Terra_Ouro.h"
# include "Terra_Diamante.h"
# include "Terra_frango.h"
# include "Escada.h"
# include "Twist.h"
# include "Viga.h"
# include "Vazio.h"
# include <time.h>
# include "Dinamite_bloco.h"
# include <random>
//tipos de blocos

//mineiro
class Mineiro;
//mineiro

# define BLOCOS "bloco.txt"
# define TAM 7
using namespace std;




class Mina{
	private:
		vector<string>vec;
		int colunas, linhas, Nivel;
		Bloco ***mapa;
		int tam, numero_pedras;
		string nome;
		Mineiro *mineiro;
	public:
		//########################## Construtor  & Destrutor ############################
		Mina(void);
		Mina (const Mina &ob);
		Mina(int col,int lin,int dif);
		~Mina(void);
		//########################## Construtor  & Destrutor ############################

		//########################## funcoes da mina ############################
		//introduzir dados na mina
		void setnome(string &nome);
		string get_nome(void);
		//void setmineiro
		void setmineiro(Mineiro &ob);
		//visao do mineiro
		void desenha_mineiro_mapa(int col_mineiro,int lin_mineiro,int raio, Consola c);
		void visao_mineiro (int col_mineiro,int lin_mineiro,  Consola c, Mineiro &mineiro);
		void visao_mineiro_raio (int col_mineiro, int lin_mineiro,int raio,Consola c);
		void desenha_fundo_falso_lateral(int col_mineiro, int lin_mineiro,int raio,Consola c);
		void desenha_fundo_falso_cima(int col_mineiro, int lin_mineiro,int raio,Consola c);
		void redesenha_limites_tabuleiro(int col_mineiro, int lin_mineiro,int raio,Consola c);

		//funcao que le o nome dos blocos de um ficheiro  para um vector
		void createBlocos(void);
		//funcao que le o nome dos blocos de um ficheiro  para um vector

		//funcoes da mina
		void set_dados(int &col, int &lin ,int &dif);
		void createMina(int col, int lin,int dif);
		string Mapa(int col , int lin);
		int get_colunas(void){ return this->colunas;}
		int get_linhas (void){return this->linhas;}
		//funcoes da mina
		
		bool restricao(void);
		int gruta(void);
		void gruta_retira_vida(int &numero_blocos);
		void cai_pedra(void);
		void puxa_pedra(int &x ,int &y);
		void mata_mineiro(void);
	
		//Metodos para ler ficheiros
		void load_save_game(string nome_ficheiro, Consola c, int &p, int &q, int &d);
	
		//Metodos para ler ficheiros
		//funcoes do jogo
		void jogar(Mineiro mineiro,Consola c,string FILENAME);
		void criar_mapa_da_mina(int map_dif[][12]);
		int get_tipo_de_bloco(int aleatorio,int nivel_profundidade,int map_dif[][12]);
		void mostra_mapa_na_consola(int x, int y, int raio, int campo_visao);
		void adiciona_bloco_mais_bloco(int x_col, int y_col,string str);
		bool percorrer_mapa(int x ,int y);
		//funcoes do jogo
		//funcoes faz o contorno do ecran
		void setContorno(int n);
		int getContorno(void);
		//funcoes faz o contorno do ecran

		void linha_horizontal_cima (int x, int y,int tamanho);
		void linha_horizontal_baixo (int x, int y,int tamanho);
		void linha_horizontal_meio (int x, int y,int tamanho);
		void coloca_twist(void);
		void criar_buraco(void);
		void criar_twist(void);
		//########################## funcoes da mina ############################
		//##################  Metodos Para os comandos ####################################
		
		//comando b tipo col lin
		int reconhece_terreno(string tipo);
		void coloca_bloco_posx_posy(int x , int y, string tipo);
		void mineiro_da_martelada(int &x,int &y);
		// comando c lin col
		void coloca_mineiro_na_posicao(int x,int y);
		//##################  Metodos Para os comandos ###################################
		//operator <<
		//polimorfismo
		bool verifica (int x, int y);

		//polimorfismo

		//metodos de perguntas do mineiro
		bool  resposta_posicao(int lin);
		//metodos de perguntas do mineiro
		//operator =
		Mina &operator=(const Mina &ob); 
};