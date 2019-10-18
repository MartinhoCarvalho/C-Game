#include "Terra_Ferro.h"


Terra_Ferro::Terra_Ferro(void){
	ostringstream str;

	nome = "Ferro";
	str << (char) 218  << (char) 196 << (char) 196<< (char) 196 << (char) 191 << '\n' 
		<< (char) 179 << (char) 197 << (char) 197 << (char) 197 << (char) 179 << '\n'
	/*	<< (char) 179 << (char) 197 << (char) 197 << (char) 197 << (char) 179 << '\n'*/
    	<< (char) 179 << (char) 197 << (char) 197 << (char) 197 << (char) 179 << '\n'
        << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = false;
    toques_picareta_ate_partir = 4;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->peso = 3;
	this->valor = 12;
}

Terra_Ferro::Terra_Ferro(const Terra_Ferro &ob){
	nome = ob.nome;
	aspecto = ob.aspecto;// aqui e uma string e devolve o objecto ja feito
	pode_escavar = ob.pode_escavar;
	permite_mineiro = ob.permite_mineiro;
	cai_no_espaco_vazio = ob.cai_no_espaco_vazio;
	toques_picareta_ate_partir = ob.toques_picareta_ate_partir;
	toques_picareta_recebidos = ob.toques_picareta_recebidos;
	energia_a_dar_ou_retirar = ob.energia_a_dar_ou_retirar;
	//objecto_a_dar = ob.objecto_a_dar->clone();//copio o objecto
	this->peso = ob.peso;
	this->valor = ob.valor;
}

Terra_Ferro::~Terra_Ferro(void){

}

/*################  Polimorfismo ################################*/

bool Terra_Ferro::get_permite_mineiro(void){
	return this->permite_mineiro;
}

Terra_Ferro & Terra_Ferro::operator=(const Bloco &b){
	if(this!= &b){// verifico senao estou a copia o mesmo objecto
		Bloco::operator=(b);
	}
	return *this;
}

bool Terra_Ferro::escava(void){
	return true;
}

Bloco *Terra_Ferro::duplica(){
	return new Terra_Ferro(*this);
}

bool Terra_Ferro::Puxa(void){
	return false;
}


void Terra_Ferro::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terra_Ferro::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terra_Ferro::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terra_Ferro::retorna_peso(void){
	return this->peso;
}

int Terra_Ferro::retorna_valor(void){
	return this->valor;
}

int Terra_Ferro::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terra_Ferro::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terra_Ferro::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}


/*################  Polimorfismo ################################*/