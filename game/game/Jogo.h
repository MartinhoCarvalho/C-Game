#pragma once
# include <iostream>
# include <cstdlib>
# include <cstddef>	
# include <sstream>
# include <string>
# include <algorithm>
# include "Consola.h"
# include <fstream>
# include <dos.h>
# include <vector>
# include "Mina.h"
# include "Mineiro.h"
# include "ERROR_Exception.h"
# include "GLOBALOPERATOR.h"
# include <map>
# include <conio.h>
# include <stdio.h>
# define LOGOTIPO "Logotipo.txt"
# define STARTMENU "StartMenu.txt"
# define SCORE "Score.txt"
# define DEBUG 1
# define TABELA_PRECOS "tabela_precos.txt"
using namespace std;


class Jogo{
	private:
		int col, lin ,dif;
		int condicao_paragem,paragem,tempo,flag,BLocos_Partidos;
		float valor;
		string nome, file, str,comando,comando2,comando3,comando4,comando5,comando6;
		vector <string > vec;
		vector<string>vec2;
		Mineiro **lista;
		Mina **lista2;
		int tam, **time;
		static int n;
		map<string,int>tabela_precos;
		map<string,int>lista_comandos;
		Consola ecran;
		char tecla;
		int mapa_dif[4][12];
		int mapa_dif2[4][12];

	public:
		// ############################### FUNCOES DE JOGO   ################################### 
		void game(void);
		void loadAtributosJogo(string comando);//valida as definicoes e nome do jogador para o jogo iniciar
		void LoadFicheiroUtensilios(string comando);
		void faz_concatenar_string_adciona_preco (string comando);
		void gere_jogo(void);
		//funcoes do jogo
		void duplica_array(int mapa[][12]);
		void duplica_array2(int mapa[][12]);
		void setCol(int col);
		void setLin(int lin);
		void setDif(int dif);
		void setNomeJogador(string nome);
		void set_condicao_paragem(int &valor);
		void limpa_vector_comandos(void);
		void limpa_minas_mineiros(void);
		void verifica_numero_blocos_escavados(Mineiro &mineiro);
		void escrever_score_dos_jogadores(void);
	/*	void limpa_vector_comandos*/
		//funcoes void
		
		//funcoes que retornao algo
		void Loadlogotipo(void);
		void LoadStartMenu(void);
		string LoadInsertConfiguracoes();
		string LoadScore(void);
		void ValidaComandoStartGame(string comando,Mina &mina,Mineiro &mineiro);
		
		//dados do jogo e e do jogador
		int getCol(void);
		int getLin(void);
		int getDif(void);
		string getNomeJogador(void);
		void reconhece_comandos(string &comando,Mina &mina,Mineiro &mineiro);
		void save_blocos_partidos_mineiro(Mineiro &mineiro);
		void save_Score_player(void);
		// ############################### FUNCOES DE JOGO   ################################### 

		// ############################### desenha output ecran ###################################
		void desenha_ecran(int &time,Mineiro &b, int poscol, int poslin);
		void desenha_informacao_relativa(int poscol,int poslin,Mineiro &b);
		void desenha_prompt(void);
		void error_msg(string msg);
		// ############################### desenha output ecran ###################################

		// ############################### Mineiro  ###################################
		//mineiro
		void actualiza_vida();
		//dados do jogo e e do jogador
		string procura (string comando);
		string outputDefinicoesJogo(void);//

		//valida ficheiro precos
		void valida_nome_ficheiro(void);

		void check_life_mineiro(Mineiro &mineiro,Mina &mina);
		// ############################### Mineiro  ###################################

		//######################## comandos do jogo  #####################################
		void teclado_setas(Mineiro &mineiro, Mina &mina,int &poscol, int &poslin);
		void comando_tecla_c(int poscol, int poslon, Mineiro &mineiro, Mina &mina);
		void comando_tecla_e(Mineiro &mineiro);
		void comando_tecla_v(Mineiro &mineiro);
		void comando_tecla_d(Mineiro &mineiro, Mina &mina);
		void comando_tecla_x(Mineiro &mineiro, Mina &mina);
		void comando_tecla_r(Mineiro &mineiro);
		void arrebenta_minas(int x , int y,Mina &mina,Mineiro &mineiro);
		void comando_tecla_p(void);
		void coloca_colunas(Mineiro &mineiro, Mina &mina);
		void linha_superior(Mina &mina,int &x,int &y);
		void inserir_tabela_comandos(void);
		int reconhece_comandos(void);
		void executar_comando(int &x, int &y, Mina &mina, Mineiro &mineiro);
		void superfice_vida(Mineiro &mineiro);
		void escava_jogo(Mineiro &mineiro, int &x, int &y);
		void converte_valores_em_moedas(Mineiro &mineiro);
		//comando u novo-utensilio
		void u_novo_utensilio(string nome,Mineiro &mineiro, int lin,Mina &mina);
		//comando b tipo lin col
		void coloca_bloco(Mina &mina);
		//comando t lin col
		void teletransportmineiro(Mineiro &mineiro);
		bool verifica_limites_mina(void);
		//comando t lin col
		//comando g valor
		void comando_g_valor(Mineiro &mineiro);
		//comando e valor
		void comando_e_valor(Mineiro &mineiro);
		//comando c novo-nome
		void comando_c_nome(Mineiro &ob_mineiro,  Mina &ob_mina);
		//comando c novo-nome
		//comando f muda foca_mina
		void f_nome(Mineiro &ob_mineiro, Mina &ob_mina);
		//comando a nome-origem nome-dest
		void comando_a_nome_nome_destino(Mineiro &ob_mineiro, Mina &ob_mina); 
		//Comando j
		void comando_j(int poscol,int poslin,Mineiro &mineiro,Mina &mina);
		//metodo para o comandoc e a
		void comando_save_dados(Mineiro &ob_mineiro, Mina &ob_mina);
		int pesquisa_nome(string nome);
		//metodo para o comandoc e a
		//comando x
		void comando_x(void);
		//precos
		void listagem_precos(void);
		void desabamento(Mineiro &mineiro, Mina &mina);
		int vida_extra(Mineiro &mineiro,Mina &mina);
		//######################## comandos do jogo  #####################################

		//######################## construtor e destrutor  #####################################
		Jogo(void);
		~Jogo(void);
		//construtor & destrutor
		Jogo &operator++(int n);
		//######################## construtor e destrutor  #####################################

};

