#include "Terra_frango.h"


Terra_frango::Terra_frango(void):Bloco(){
	ostringstream str;

	nome = "Frango";
	str << (char) 218 << (char) 196 << (char) 196<< (char) 196 <<  (char) 191 << '\n' 
		<< (char) 179 << (char) 177 << (char) 233 << (char) 177 << (char) 179 << '\n'
		/*<< (char) 179 << (char) 177 << (char) 233 << (char) 177 << (char) 179 << '\n'*/
    	<< (char) 179 << (char) 177 << (char) 233 << (char) 177 << (char) 179 << '\n'
        << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = false;
    toques_picareta_ate_partir = 2;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 20;
	this->valor = 0;
	this->peso = 0;
}

Terra_frango::Terra_frango(const Terra_frango &ob):Bloco(){
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

Terra_frango::~Terra_frango(void){
}

/*################  Polimorfismo ################################*/
bool Terra_frango::get_permite_mineiro(void){
	return this->permite_mineiro;
}

bool Terra_frango::escava(void){
	return true;
}

Terra_frango & Terra_frango::operator=(const Bloco &b){
	if(this != &b){
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Terra_frango::duplica(){
	return new Terra_frango(*this);
}

bool Terra_frango::Puxa(void){
	return false;
}

void Terra_frango::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terra_frango::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terra_frango::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terra_frango::retorna_peso(void){
	return this->peso;
}

int Terra_frango::retorna_valor(void){
	return this->valor;
}

int Terra_frango::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terra_frango::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terra_frango::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}



/*################  Polimorfismo ################################*/