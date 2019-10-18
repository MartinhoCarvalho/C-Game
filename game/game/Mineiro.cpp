#include "Mineiro.h"
# include "Bloco.h"
# include "Mina.h"

//########################## Construtor  & Destrutor ############################
Mineiro::Mineiro(void){
	this->vida = this->utensilios.retorna_energia();
	this->dinheiro = 150;
	this->peso = this->utensilios.retorna_peso_mochila();
	this->raio_visao = this->utensilios.retorna_raio_visao();// raiod e visao comeca a 1 incialmente
	this->cordy = 0; 
	this->cordx = 0;
	this->pedras_ecavadas = 0;
}

Mineiro::Mineiro(Mineiro &ob){
	this->dinheiro = ob.dinheiro;
	this->vida = ob.vida;
	this->vida =ob.vida;
	this->peso = ob.peso;
	this->raio_visao = ob.raio_visao;
	this->cordx = ob.cordx;
	this->cordy = ob.cordy;
	mina = NULL;
	this->utensilios = ob.utensilios;
	this->pedras_ecavadas = ob.pedras_ecavadas;
}

Mineiro &Mineiro::operator=(Mineiro &ob){
	if(this != &ob){
		this->dinheiro = ob.dinheiro;	
		this->vida = ob.vida;
		this->vida =ob.vida;
		this->peso = ob.peso;
		this->pedras_ecavadas = ob.pedras_ecavadas;
		this->raio_visao = ob.raio_visao;
		this->cordx = ob.cordx;
		this->cordy = ob.cordy;
		mina = NULL;
		this->utensilios = ob.utensilios;	
	}
	return *this;
}

Mineiro::~Mineiro(void){
}

//########################## Construtor  & Destrutor ############################

// ################# Metodos que devolvem informaçao do Mineiro  ###############################

void Mineiro::set_n_pedras_escavadas(void){
	this->pedras_ecavadas++;
}

int Mineiro::get_numero_blocos_escavados(void){
	return this->pedras_ecavadas;
}

int Mineiro::return_cordx(void){
	return this->cordx;
}

int Mineiro::return_cordy(void){
	return this->cordy;
}

void Mineiro::set_cordx_cordy(int &x, int &y){
	this->cordx = x;
	this->cordy = y;
}

void  Mineiro::actualiza_vida(float &vida){
	this->vida = vida;
}

void Mineiro ::retira_vida(float &vida){
	this->vida += vida;
}


void Mineiro::retira_vida_escada(void){
	if(this->mina->Mapa(this->cordx,this->cordy) == "Escada"){
		float valor = -2.0;
		this->retira_vida(valor);	
	}
}

void Mineiro::insert_moedas(int valor){
	//this->dinheiro = 0;
	this->dinheiro =valor;
}

void Mineiro::retira_moedas(int valor){
	this->dinheiro -= valor;
}

float  Mineiro ::devolve_energia_mineiro(void){
	return this->vida;
}

int Mineiro:: devolve_numero_moedas(void){
	return this->dinheiro;
}

float  Mineiro::return_energia_utensilio(void){
	float valor =this->utensilios.retorna_energia(); 
	return valor;
}

void Mineiro::desenha(int x, int y,int raio ,char car ,Consola c){
	int t = 1,l = 1,p = 1,v = 0,flag = 0;
	int aux = t;
	int deslocamento = 5;

	//posicionar o mineiro no centro
	for(int i = 0 ; i  <  7 ; i++){//colunas fixas ate 6 do tabuleiro
		v= 0;//deslocamento das colunas
		for(int j =  0 ; j < 7 ; j++){//linhas fixas ate 6
			t = v * 5;//vai me dando o deslocamento de 5* numero car de cada bloco
			if(i== 3 && j == 3){//estou no centro da matriz 
			   t = v* 5;
			   if(car =='E'){
					this->desenha_escada(deslocamento+t-2,l+1,car,c);
			   }
			   else if(car =='V'){
				   this->desenha_viga(deslocamento+t-2,l+1,car,c);
			   }
			   else if(car =='D'){
				   this->desenha_dinamite(deslocamento+t-2,l+1,car,c);
			   }
			   else{
					this->desenha_default(deslocamento+t-2,l+1,car,c);
			   }
				v++;
			   break;
			}
		 v++;
	     }
	 l+=5;
	}
		
}

int Mineiro::return_raio_visao(void){
	return this->utensilios.retorna_raio_visao();
}

void Mineiro::desenha_escada(int x, int y,char car ,Consola c){
	int contador = 1, col = 1;
	for (int t = y; t < y+5; t++) {//linhas
			col = 0;
			c.setBackgroundColor(c.CINZENTO);
			c.setTextColor(c.AMARELO_CLARO);
			for(int i = x; i < x+5; i++){//colunas
				if(contador==1 && col== 2){//desenhar cabeça 
					c.gotoxy(i-2,t);
					cout << (char) 195 ;
					c.gotoxy(i-1,t);
					cout << (char) ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)'*';
					c.gotoxy(i+1,t);
					cout << (char) ' ';
					c.gotoxy(i+2,t);
					cout << (char) 180;
				}
				else if (contador == 2 && col == 1 ){
					/*c.gotoxy(i-1,t);
					cout << (char) 195 ;*/
				    c.gotoxy(i-1,t);
					cout << (char) 195;
					c.gotoxy(i,t);
					cout << (char) 204; 
					c.gotoxy(i+1,t);
					cout << (char) 193;
					c.gotoxy(i+2,t);
					cout << (char) 185;
					c.gotoxy(i+3,t);
					cout << (char) 180;
				}
				else if (contador == 3 && col == 2){
					c.gotoxy(i-2,t);
					cout << (char) 195 ;
					c.gotoxy(i-1,t);
					cout << (char) ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)179;
					c.gotoxy(i+1,t);
					cout << (char) ' ';
					c.gotoxy(i+2,t);
					cout << (char) 180;
				}
				else if (contador == 4 && col == 2){
					c.gotoxy(i-2,t);
					cout << (char) 195 ;
					c.gotoxy(i-1,t);
					cout << (char) ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)193;
					cout << (char) ' ';
					c.gotoxy(i+2,t);
					cout << (char) 180;
				}
				else if (contador == 5 && col == 1){
					c.gotoxy(i-1,t);
					cout << (char) 195 ;
					c.gotoxy(i,t);
					cout << (char) ' ';
					c.gotoxy(i,t);
					cout << (char)188;
					c.gotoxy(i+1,t);
					cout << (char) ' ';
					c.gotoxy(i+2,t);
					cout << (char) 200;
					c.gotoxy(i+3,t);
					cout << (char) 180;
				}
				col++;
			}
			contador++;
		}
	c.setTextColor(c.PRETO);
	c.setBackgroundColor(c.PRETO);
}

void Mineiro::desenha_viga(int x, int y,char car ,Consola c){
	int contador = 1, col = 1;
	c.setBackgroundColor(c.CINZENTO);
	c.setTextColor(c.AMARELO_CLARO);
	for (int t = y; t < y+5; t++) {//linhas
			col = 0;
			for(int i = x; i < x+5; i++){//colunas
				if(contador==1 && col== 2){//desenhar cabeça 
					c.gotoxy(i-2,t);
					cout << (char) 203;
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)'*';
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << (char) 203;
				}
				else if (contador == 2 && col == 1 ){
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i,t);
					cout << (char) 204;
					c.gotoxy(i+1,t);
					cout << (char) 193;
					c.gotoxy(i+2,t);
					cout << (char) 185;
					c.gotoxy(i+3,t);
					cout << ' ';
				}
				else if (contador == 3 && col == 2){
					c.gotoxy(i-2,t);
					cout << ' ';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)179;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << ' ';
				}
				else if (contador == 4 && col == 2){
					c.gotoxy(i-2,t);
					cout << ' ';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)193;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << ' ';
				}
				else if (contador == 5 && col == 1){
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i,t);
					cout << (char) 188;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << (char) 200;
					c.gotoxy(i+3,t);
					cout << ' ';
				}
				col++;
			}
			contador++;
		}
	c.setBackgroundColor(c.PRETO);
	c.setTextColor(c.PRETO);
}

void Mineiro::desenha_dinamite(int x, int y,char car ,Consola c){
	int contador = 1, col = 1;
	c.setBackgroundColor(c.CINZENTO);
	for (int t = y; t < y+5; t++) {//linhas
			col = 0;
			for(int i = x; i < x+5; i++){//colunas
				if(contador==1 && col== 2){//desenhar cabeça 
					c.gotoxy(i-2,t);
					c.setTextColor(c.AZUL);
					cout << '*';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					c.setTextColor(c.AMARELO_CLARO);
					cout << (char)'*';
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					c.setTextColor(c.AZUL);
					cout << '*';
				}
				else if (contador == 2 && col == 1 ){
					c.setTextColor(c.AMARELO_CLARO);
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i,t);
					cout << (char) 204;
					c.gotoxy(i+1,t);
					cout << (char) 193;
					c.gotoxy(i+2,t);
					cout << (char) 185;
					c.gotoxy(i+3,t);
					cout << ' ';
				}
				else if (contador == 3 && col == 2){					
					c.setTextColor(c.AMARELO_CLARO);
					c.gotoxy(i-2,t);
					cout << ' ';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)179;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << ' ';
				}
				else if (contador == 4 && col == 2){						
					c.setTextColor(c.AMARELO_CLARO);
					c.gotoxy(i-2,t);
					cout << ' ';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)193;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << ' ';
				}
				else if (contador == 5 && col == 1){
					c.setTextColor(c.AZUL);
					c.gotoxy(i-1,t);
					cout << '*';
					c.gotoxy(i,t);
					c.setTextColor(c.AMARELO_CLARO);
					cout << (char) 188;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << (char) 200;
					c.gotoxy(i+3,t);
					c.setTextColor(c.AZUL);
					cout << '*';
				}
				col++;
			}
			contador++;
		}
	c.setBackgroundColor(c.PRETO);
	c.setTextColor(c.PRETO);
}

void Mineiro::desenha_default(int x , int y, char car, Consola c){

	int contador = 1, col = 1;
	for (int t = y; t < y+5; t++) {//linhas
			col = 0;
			c.setBackgroundColor(c.CINZENTO);
			c.setTextColor(c.AMARELO_CLARO);
		//	c.setTextColor(c.AMARELO);
			for(int i = x; i < x+5; i++){//colunas
				if(contador==1 && col== 2){//desenhar cabeça 
					c.gotoxy(i-2,t);
					cout << ' ';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)'*';
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << ' ';
				}
				else if (contador == 2 && col == 1 ){
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i,t);
					cout << (char) 204;
					c.gotoxy(i+1,t);
					cout << (char) 193;
					c.gotoxy(i+2,t);
					cout << (char) 185;
					c.gotoxy(i+3,t);
					cout << ' ';
				}
				else if (contador == 3 && col == 2){
					c.gotoxy(i-2,t);
					cout << ' ';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)179;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << ' ';
				}
				else if (contador == 4 && col == 2){
				    c.gotoxy(i-2,t);
					cout << ' ';
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i, t);//posicionar o caracter no ecran
					cout << (char)193;
				    c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << ' ';
				}
				else if (contador == 5 && col == 1){
					c.gotoxy(i-1,t);
					cout << ' ';
					c.gotoxy(i,t);
					cout << (char) 188;
					c.gotoxy(i+1,t);
					cout << ' ';
					c.gotoxy(i+2,t);
					cout << (char) 200;
					c.gotoxy(i+3,t);
					cout << ' ';
				}
				col++;
			}
			contador++;
		}
	c.setTextColor(c.PRETO);
	c.setBackgroundColor(c.PRETO);
}

// ################# Metodos que devolvem informaçao do Mineiro  ###############################


// ################# Metodos Dos Utensilios ###############################
void Mineiro::utiliza_ramdon(void){
	if(this->utensilios.get_ramdom() > 0){
		this->utensilios.decrementa_random();
		 srand (time(NULL));
		 int x,y;
		 int i,j;
		 do{
			x = (rand() %this->mina->get_colunas()-2);
			y = (rand() %this->mina->get_linhas()-2);
			if(x >= 0 && x < this->mina->get_colunas() && y >=0 && y < this->mina->get_linhas()){
				i = x;
				j = y;
			}	 
			else{
				 i = 0;
				 j = 0;
			 }
		 }while(x < 0 || y < 0);
		 this->set_cordx_cordy(i,j);
		 this->mina->coloca_bloco_posx_posy(x,y,"VA");
	}
}

int Mineiro::get_ramdon(void){
	return this->utensilios.get_ramdom();
}

int Mineiro::numero_marteladas(void){
	return this->utensilios.return_numero_toques();
}

void Mineiro:: carrega_mochila(int &peso,int &valor){
	this->utensilios.carrega_mochila(peso,valor);
	this->peso= this->utensilios.retorna_peso_mochila();
}

/*
int retorna_peso(void);
		int retorna_capacidade(void);

*/
int Mineiro::retorna_capacidade(void){
	return this->utensilios.retorna_capacidade();
}

int Mineiro::retorna_peso(void){
	this->peso = this->utensilios.retorna_peso_mochila();
	return this->peso;
}

int Mineiro::return_valor(void){
	return this->utensilios.return_valor();
}

void Mineiro::soma_moedas(void){
	this->dinheiro+=this->utensilios.return_valor();
	this->actualiza_valores_mochila();
}

void Mineiro::actualiza_valores_mochila(void){
	this->utensilios.actualiza_mochila();
}

// a onde estou
bool Mineiro::a_onde_estou(int lin){
	return this->mina->resposta_posicao(lin);
}

//informacao sobre os utenslios tipo 2
void Mineiro::aplica_escada(int &valor){
	valor = valor * -1;
	if(this->utensilios.get_recargas() > 0 ){
		this->utensilios.set_Recargas(valor);
		this->mina->coloca_bloco_posx_posy(this->cordx,this->cordy,"E");
	}
}

int Mineiro:: verifica_cordenadas(int &x, int &y){
	if(x == 0 && y== 0){
		return 1;
	}
	else if (x <= this->mina->get_colunas() && y == 0 ){
		return 1;
	}
	else if (x == 0&& y <= this->mina->get_linhas()){
		return 1;
	}//verificar num raio de 1
	//else if (this->cordx - x ==  ){
	//	return 1;
	//}

}

int Mineiro::return_numero_recargas(void){
	return this->utensilios.get_recargas();
}

void Mineiro::aplica_viga(int &valor){
	valor = valor * -1;
	if(this->utensilios.get_recargas() > 0 ){
		this->utensilios.set_Recargas(valor);
		this->mina->coloca_bloco_posx_posy(this->cordx,this->cordy,"V");
	}
}

void Mineiro::utliza_vida_extra(void){
	int valor = -1;
	this->utensilios.set_vida_extra(valor);
}

void Mineiro::retira_dinamite(void){
	int valor = -1;
	this->utensilios.set_dinamite(valor);
}

int Mineiro::return_vida_Extra(void){
	return this->utensilios.get_vida();
}

int Mineiro::return_DInamite(void){
	return this->utensilios.get_dinamite();
}

string  Mineiro ::tipo_picareta(void){
	ostringstream str;
	str << this->utensilios.tipo_picareta();
	return str.str();
}

string Mineiro::tipo_energia(void){
	ostringstream str;
	str << this->utensilios.tipo_energia();
	return str.str();
}

string Mineiro::tipo_mochila(void){
	ostringstream str;
	str << this->utensilios.tipo_mochila();
	return str.str();
}

string Mineiro::tipo_luz(void){
	ostringstream str;

	str<< this->utensilios.tipo_luz();
	return str.str();
}

string Mineiro::recargas(void){
	ostringstream str;

	str<< "Recargas "<< this->utensilios.get_recargas();
	return str.str();

}

string Mineiro::Paraquedas(void){
	ostringstream str;

	str<< "Paraquedas "<< this->utensilios.get_paraquedas();
	return str.str();

}

string Mineiro::Dinamite(void){
	ostringstream str;

	str<< "Dinamite "<< this->utensilios.get_dinamite();
	return str.str();
}

string Mineiro::Vida_extra(void){
	ostringstream str;

	str<< "Vida_extra "<< this->utensilios.get_vida();
	return str.str();
}

void Mineiro::recarrega_vida(int &vida){
	this->vida+=vida;
}

int Mineiro::return_paraquedes(void){
	return this->utensilios.get_paraquedas();
}

void Mineiro::paraquedas_decrementa(void){
	this->utensilios.decrementa_paraquedas();
}

void Mineiro::mineiro_da_uma_martelada_no_bloco(int &x,int &y){
	this->mina->mineiro_da_martelada(x,y);
}

// ################# Metodos Dos Utensilios ###############################


//################### metodo teletransporte ###################################################
void Mineiro::teletransporte(int x, int y){	
	this->mina->coloca_mineiro_na_posicao(x,y);
}

void Mineiro::compra_utensilios(string nome, string &valor){
	if(nome == "Picareta_simples"){
		this->utensilios.compra_picareta_simples();
	}
	else if(nome == "Picareta_Automatica"){
		this->utensilios.compra_picareta_automatica();
	}
	else if(nome == "Martelo_Pneumatico"){
		this->utensilios.compra_martelo_pneumautico();
	}
	else if(nome == "Mochila_Simples"){
		this->utensilios.compra_mochila_simples();
	}
	else if(nome == "Mochila_pro"){
		this->utensilios.compra_mochila_pro();
	}
	else if (nome == "Mochila_heavy_duty"){
		this->utensilios.compra_mochila_heavy_duty();
	}
	else if(nome == "Isqueiro"){
		this->utensilios.compra_isqueiro();
	}
	else if(nome == "Lanterna"){
		this->utensilios.compra_lanterna();
	}
	else if(nome == "Holofote"){
		this->utensilios.compra_holofote();
	}
	else if(nome == "Lata_Atum"){
		this->utensilios.compra_lata_atum();
	}
	else if(nome == "Bebida_Energetica"){
		this->utensilios.compra_bebida_energetica();
	}
	else if (nome == "Lancheira_campismo"){
		this->utensilios.compra_lancheira_campismo();
	}
	else if(nome == "Frigorifico_Portatil"){
		this->utensilios.compra_frigorifico_portatil();
	}
	else if (nome == "Recargas"){
		int numero = atoi(valor.c_str());
		this->utensilios.set_Recargas(numero);
	}
	else if (nome == "Vida"){
		int numero = atoi(valor.c_str());
		this->utensilios.set_vida_extra(numero);
	}
	else if (nome == "Dinamite"){
		int numero = atoi(valor.c_str());
		this->utensilios.set_dinamite(numero);
	}
	else if (nome == "Para_quedas"){
		int numero = atoi(valor.c_str());
		this->utensilios.set_paraquedas(numero);
	}
}

//################# coloca a energia a com o valor do utensilio ##############################
void  Mineiro::iguala_energia(void){
	/*if(this->a_onde_estou() == true){
		this->actualiza_vida(this->utensilios.retorna_energia());	
	}*/
}

//################### metodo teletransporte ###################################################

//polimorfisomo do mineiro 

void Mineiro::da_martelada(int &x,int &y){
	
}

void Mineiro::set_mina(Mina &mina){
	this->mina = &mina;
}

bool Mineiro::pede_permisao_mina(int poscol,int poslin){
	return this->mina->verifica(poscol,poslin);
}
//polimorfisomo do mineiro 

//operador++

//Mineiro &Mineiro::operator++(int n){
//	Mineiro temp = *this;
//	
//	temp.cordx++;
//
//	return temp;
//}

 Mineiro operator-(Mineiro &ob,float &vida){
	 Mineiro temp(ob);

	 temp.actualiza_vida(vida);

	return temp;
}