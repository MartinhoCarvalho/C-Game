#include "Dinamite_bloco.h"


Dinamite_bloco::Dinamite_bloco(void){
ostringstream str;

	nome = "Dinamite";
	str << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << '\n'
		<< (char) ' ' << (char) 203 << (char) ' ' << (char) 203 << (char) ' ' << '\n'
	    << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << '\n'
    	<< (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << '\n'
        << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << '\n';
	this->aspecto = str.str();
	pode_escavar = false;
	permite_mineiro = true;
    cai_no_espaco_vazio = false;
    toques_picareta_ate_partir = 0;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->peso = 0;
	this->valor = 0;
}


Dinamite_bloco::~Dinamite_bloco(void){
}


Dinamite_bloco::Dinamite_bloco(const Dinamite_bloco &ob){
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





/*################  Polimorfismo ################################*/

bool Dinamite_bloco::get_permite_mineiro(void){
	return this->permite_mineiro;
}

Dinamite_bloco&Dinamite_bloco::operator=(Bloco &b){
	if(this != &b){
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Dinamite_bloco::duplica(){
	return new Dinamite_bloco(*this);
}

bool Dinamite_bloco::Puxa(void){
	return true;
}

bool Dinamite_bloco::escava(void){
	return true;
}

void Dinamite_bloco::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Dinamite_bloco::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Dinamite_bloco::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Dinamite_bloco::retorna_peso(void){
	return this->peso;
}

int Dinamite_bloco::retorna_valor(void){
	return this->valor;
}

int Dinamite_bloco::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Dinamite_bloco::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Dinamite_bloco::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}

/*################  Polimorfismo ################################*/