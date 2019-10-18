#include "Utensilios.h"


Utensilios::Utensilios(void){
	//###### utensilios ####################
	this->energia = new Lata_Atum();
	this->picareta = new Picareta_simples();
	this->luz = new Isqueiro();
	this->mochila = new Mochila_Simples();
	delete mochila;
	this->mochila = new Mochila_Simples();
	//###### utensilios ####################
	//### TIPO2   #################
	this->recargas = 150;
	this->vida_extra = 3;
	this->dinamite = 8;
	this->Paraquedas = 1;
	this->ramdon = 5;
	//### TIPO2   #################
}



Utensilios::Utensilios( Utensilios &ob){
	this->energia = ob.return_energia();
	this->picareta = ob.return_picareta();
	this->luz = ob.return_luz();
	this->mochila = ob.return_mochila();
	this->recargas = ob.recargas;
	this->vida_extra = ob.vida_extra;
	this->dinamite = ob.dinamite;
	this->Paraquedas = ob.Paraquedas;
	this->ramdon = ob.ramdon;
}
Utensilios::~Utensilios(void){
	picareta = NULL;
	mochila = NULL;
	energia = NULL;
	luz = NULL;
}


//################### informacao sobre os utensilios do tipo 1 ########################
int Utensilios::retorna_raio_visao(void){
	return this->luz->retorna_raio_visao();
}

int Utensilios::retorna_energia(void){
	return this->energia->retorna_energia_energetica();
}

int Utensilios::retorna_peso_mochila(void){
	int valor = this->mochila->return_peso();
	return valor;
}

int Utensilios::return_valor(void){
	return this->mochila->return_valor();
}

int Utensilios::retorna_capacidade(void){
	return this->mochila->retorna_capacidade();
}

int Utensilios::return_numero_toques(void){
	return this->picareta->retorna_numero_toques();
}

string Utensilios::tipo_picareta(void){
  return this->picareta->retorna_nome_utensilio();
}

string Utensilios::tipo_mochila(void){
	return this->mochila->retorna_nome_mochila();
}

string Utensilios::tipo_energia(void){
	return this->energia->retorna_nome_da_energia();
}

string Utensilios::tipo_luz(void){
	return this->luz->retorna_nome_luz();
}
//################### informacao sobre os utensilios do tipo 1 ########################
//################## metodos de compras  ########################################
void Utensilios::compra_picareta_simples(void){
	delete this->picareta;
	this->picareta = new Picareta_simples();
}

void Utensilios::compra_picareta_automatica(void){
	delete this->picareta;
	this->picareta = new Picareta_Automatica();
}

void Utensilios::compra_martelo_pneumautico(void){
	delete this->picareta;
	this->picareta = new Martelo_Pneumatico();
}

Picareta *Utensilios::return_picareta(void){
	return this->picareta->clone();
}

void Utensilios::actualiza_mochila(void){
	int valor = 0;
	this->mochila->set_peso(valor);
	this->mochila->set_valor(valor);
}


void Utensilios::compra_mochila_simples(void){
	delete this->mochila;
	this->mochila = new Mochila_Simples();
}

void Utensilios::compra_mochila_pro(void){
	delete this->mochila;
	this->mochila = new Mochila_pro();
}

void Utensilios::compra_mochila_heavy_duty(void){
	delete this->mochila;
	this->mochila = new Mochila_heavy_duty();
}

Mochila *Utensilios::return_mochila(void){
	return this->mochila->clone();
}

void Utensilios::carrega_mochila(int &peso, int &valor){

	this->mochila->carrega_mochila(peso,valor);
}


void Utensilios::compra_isqueiro(void){
	delete this->luz;
	this->luz = new Isqueiro();
}

void Utensilios::compra_lanterna(void){
	delete this->luz;
	this-> luz = new Lanterna();
}

void Utensilios::compra_holofote(void){
	delete this->luz;
	this->luz = new Holofote();
}

Luz *Utensilios::return_luz(void){
	return this->luz->clone();
}

void Utensilios::compra_lata_atum(void){
	delete this->energia;
	this->energia = new Lata_Atum();
}

void Utensilios::compra_bebida_energetica(void){
	delete this->energia;
	this->energia = new Bebida_Energetica();
}

void Utensilios::compra_lancheira_campismo(void){
	delete this->energia;
	this->energia = new Lancheira_campismo();
}

void Utensilios::compra_frigorifico_portatil(void){
	delete energia;
	this->energia = new Frigorifico_Portatil();
}


Energia *Utensilios::return_energia(){
	return this->energia->clone();
}
//################## metodos de compras  ########################################

//################## metodos de compras  tipo 2 ########################################
void Utensilios::comprar_diversos(int &numero, string nome){
	if(nome == "Recargas"){
		this->set_Recargas(numero);
	}
	else if (nome == "paraquedas"){
		this->set_paraquedas(numero);
	}
	else if (nome == "vida"){
		this->set_vida_extra(numero);
	}
	else if (nome == "Dinamite"){
		this->set_dinamite(numero);
	}
}

void Utensilios::set_Recargas(int &valor){
	this->recargas+=valor;
}

void Utensilios::set_paraquedas(int &valor){
	this->Paraquedas+=valor;
} 

void Utensilios::set_vida_extra(int &valor){
	this->vida_extra+=valor;
}

void Utensilios::set_dinamite(int &valor){
	this->dinamite+=valor;
}

int Utensilios::get_dinamite(void){
	return this->dinamite;
}

int Utensilios::get_paraquedas(void){
	return this->Paraquedas;
}

int Utensilios::get_vida(void){
	return this->vida_extra;
}
int Utensilios::get_recargas(void){
	return this->recargas;
}

void Utensilios::decrementa_paraquedas(void){
	this->Paraquedas--;
}

void Utensilios::decrementa_random(void){
	this->ramdon--;
}

int Utensilios::get_ramdom(void){
	return this->ramdon;
}

//################## metodos de compras  tipo 2 ########################################
//operator=
Utensilios & Utensilios::operator=(Utensilios &ob){
	if(this != &ob){
		picareta = ob.return_picareta();
		energia = ob.return_energia();
		luz = ob.return_luz();
		mochila = ob.return_mochila();
		recargas = ob.recargas;
		vida_extra=ob.vida_extra;
		dinamite=ob.dinamite;
		Paraquedas=ob.Paraquedas;
		ramdon = ob.ramdon;
	}
	return *this;
}
