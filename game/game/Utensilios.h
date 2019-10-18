#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include <vector>
//### TIPO1   #################
//#### Picareta ###############
# include "Picareta.h"
# include "Picareta_simples.h"
# include "Picareta_Automatica.h"
# include "Martelo_Pneumatico.h"
//#### Picareta ###############
//### Mochila #################
# include "Mochila.h"
# include "Mochila_Simples.h"
# include "Mochila_pro.h"
# include "Mochila_heavy_duty.h"
//### Mochila #################
//### LUZ #####################
# include "Luz.h"
# include "Isqueiro.h"
# include "Lanterna.h"
# include "Holofote.h"
//### LUZ #####################
//### Energia #################
# include "Energia.h"
# include "Lata_Atum.h"
# include "Bebida_Energetica.h"
# include "Lancheira_campismo.h"
# include "Frigorifico_Portatil.h"
//### Energia #################
//### TIPO1   #################
//### TIPO2   #################
//### TIPO2   #################
using namespace std;


class Utensilios{
	private:
		//### TIPO1   #################
		Picareta *picareta;
		Mochila *mochila;
		Luz *luz;
		Energia *energia;
		//### TIPO2   #################
		int recargas;
		int vida_extra;
		int dinamite;
		int Paraquedas;
		int ramdon;
	public:
		Utensilios(void);
		Utensilios(Utensilios &ob);
		~Utensilios(void);
		Utensilios &operator=(Utensilios &ob);
		//### TIPO1   #################
		int retorna_raio_visao(void);
		int retorna_energia(void);
		int retorna_peso_mochila(void);
		int retorna_capacidade(void);
		string tipo_picareta(void);
		string tipo_mochila(void);
		string tipo_luz(void);
		string tipo_energia(void);
		void actualiza_mochila(void);

		//metodos de compras 
		//picareta
		void compra_picareta_simples(void);
		void compra_picareta_automatica(void);
		void compra_martelo_pneumautico(void);
		int return_numero_toques(void);
		Picareta *return_picareta(void);
		//mochila
		void compra_mochila_simples(void);
		void compra_mochila_pro(void);
		void compra_mochila_heavy_duty(void);
		void carrega_mochila(int &peso, int &valor);
		int return_valor(void);
		Mochila *return_mochila(void);
		//luz
		void compra_isqueiro(void);
		void compra_lanterna(void);
		void compra_holofote(void);
		Luz *return_luz(void);
		//energia
		void compra_lata_atum(void);
		void compra_bebida_energetica(void);
		void compra_lancheira_campismo(void);
		void compra_frigorifico_portatil(void);
		Energia *return_energia(void);
		//metodos de compras 
		//### TIPO1   #################
		//### TIPO2   #################
		//metodos de compras
		void comprar_diversos(int &numero,string nome);
		void set_Recargas(int &valor);
		void set_paraquedas(int &valor);
		void set_vida_extra(int &valor);
		void set_dinamite(int &valor);
		int get_recargas(void);
		int get_paraquedas(void);
		int get_vida(void);
		int get_dinamite(void);
		void decrementa_paraquedas(void);
		void decrementa_random(void);
		int get_ramdom(void);
		//operator
};

