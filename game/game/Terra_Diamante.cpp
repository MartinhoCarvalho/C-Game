#include "Terra_Diamante.h"


Terra_Diamante::Terra_Diamante(void):Bloco(){
	ostringstream str;

	nome = "Diamante";
	str << (char) 218 << (char) 196 << (char) 196<< (char) 196 <<  (char) 191 << '\n' 
		<< (char) 179 << (char) 177 << (char) 224 << (char) 177 << (char) 179 << '\n'
		/*<< (char) 179 << (char) 177 << (char) 233 << (char) 177 << (char) 179 << '\n'*/
    	<< (char) 179 << (char) 177 << (char) 244 << (char) 177 << (char) 179 << '\n'
        << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = false;
    toques_picareta_ate_partir = 5;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->peso = 4;
	this->valor = 25;
}

Terra_Diamante::Terra_Diamante(const Terra_Diamante &ob):Bloco(){
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

Terra_Diamante::~Terra_Diamante(void){
}

/*################  Polimorfismo ################################*/
bool Terra_Diamante::get_permite_mineiro(void){
	return this->permite_mineiro;
}

Terra_Diamante & Terra_Diamante::operator=(const Bloco &b){
	if(this!= &b){// verifico senao estou a copia o mesmo objecto
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Terra_Diamante::duplica(){
	return new Terra_Diamante(*this);
}

bool Terra_Diamante::Puxa(void){
	return false;
}

bool Terra_Diamante::escava(void){
	return true;
}


void Terra_Diamante::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terra_Diamante::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terra_Diamante::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terra_Diamante::retorna_peso(void){
	return this->peso;
}

int Terra_Diamante::retorna_valor(void){
	return this->valor;
}

int Terra_Diamante::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terra_Diamante::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terra_Diamante::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}

/*################  Polimorfismo ################################*/