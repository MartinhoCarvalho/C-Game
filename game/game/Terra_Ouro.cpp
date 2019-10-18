#include "Terra_Ouro.h"


Terra_Ouro::Terra_Ouro(void):Bloco(){
	ostringstream str;

	nome = "Ouro";
	str << (char) 218 << (char) 196 << (char) 196<< (char) 196 <<  (char) 191 << '\n' 
		<< (char) 179 << (char) 148 << (char) 148 << (char) 148 << (char) 179 << '\n'
		/*<< (char) 179 << (char) 148 << (char) 148 << (char) 148 << (char) 179 << '\n'*/
    	<< (char) 179 << (char) 148 << (char) 148 << (char) 148 << (char) 179 << '\n'
        << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = false;
    toques_picareta_ate_partir = 4;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->valor = 18;
	this->peso = 4;
}

Terra_Ouro::Terra_Ouro(const Terra_Ouro &ob):Bloco(){
	nome = ob.nome;
	aspecto = ob.aspecto;// aqui e uma string e devolve o objecto ja feito
	pode_escavar = ob.pode_escavar;
	permite_mineiro = ob.permite_mineiro;
	cai_no_espaco_vazio = ob.cai_no_espaco_vazio;
	toques_picareta_ate_partir = ob.toques_picareta_ate_partir;
	toques_picareta_recebidos = ob.toques_picareta_recebidos;
	energia_a_dar_ou_retirar = ob.energia_a_dar_ou_retirar;
	//objecto_a_dar = ob.objecto_a_dar->clone();//copio o objecto
	this->valor = ob.valor;
	this->peso = ob.peso;
}

Terra_Ouro::~Terra_Ouro(void){
}

/*################  Polimorfismo ################################*/
bool Terra_Ouro::get_permite_mineiro(void){
	return this->permite_mineiro;
}

Terra_Ouro &Terra_Ouro::operator=(const Bloco &b){
	if(this != &b){
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Terra_Ouro::duplica(){
	return new Terra_Ouro(*this);
}

bool Terra_Ouro::escava(void){
	return true;
}

bool Terra_Ouro::Puxa(void){
	return false;
}

void Terra_Ouro::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terra_Ouro::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terra_Ouro::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terra_Ouro::retorna_peso(void){
	return this->peso;
}

int Terra_Ouro::retorna_valor(void){
	return this->valor;
}

int Terra_Ouro::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terra_Ouro::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terra_Ouro::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}



/*################  Polimorfismo ################################*/