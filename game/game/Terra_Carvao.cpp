#include "Terra_Carvao.h"


Terra_Carvao::Terra_Carvao(void):Bloco(){
	ostringstream str;

	nome = "Carvao";
	str << (char) 218  << (char) 196 << (char) 196<< (char) 196 << (char) 191 << '\n' 
		<< (char) 179 << (char) 221 << (char) 221 << (char) 221 << (char) 179 << '\n'
	/*	<< (char) 179 << (char) 221 << (char) 221 << (char) 221 << (char) 179 << '\n'*/
    	<< (char) 179 << (char) 221 << (char) 221 << (char) 221 << (char) 179 << '\n'
        << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = true;
    toques_picareta_ate_partir = 3;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->peso = 2;
	this->valor = 8;
}

Terra_Carvao::Terra_Carvao(const Terra_Carvao &ob):Bloco(){
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

Terra_Carvao::~Terra_Carvao(void){

}


/*################  Polimorfismo ################################*/

bool Terra_Carvao::get_permite_mineiro(void){
	return this->permite_mineiro;
}

bool Terra_Carvao::escava(void){
	return true;
}

Terra_Carvao & Terra_Carvao::operator=(const Bloco &b){
	if(this!= &b){// verifico senao estou a copia o mesmo objecto
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Terra_Carvao::duplica(){
	return new Terra_Carvao(*this);
}

bool Terra_Carvao::Puxa(void){
	return false;
}

void Terra_Carvao::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terra_Carvao::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terra_Carvao::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terra_Carvao::retorna_peso(void){
	return this->peso;
}

int Terra_Carvao::retorna_valor(void){
	return this->valor;
}

int Terra_Carvao::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terra_Carvao::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terra_Carvao::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}




/*################  Polimorfismo ################################*/