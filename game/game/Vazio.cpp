#include "Vazio.h"


Vazio::Vazio(void):Bloco(){
	ostringstream str;

	nome = "Vazio";
	str << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << '\n'
		<< (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << (char) ' ' << '\n'
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

Vazio::Vazio(const Vazio &ob){
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


Vazio::~Vazio(void){
}


/*################  Polimorfismo ################################*/

bool Vazio::get_permite_mineiro(void){
	return this->permite_mineiro;
}

Vazio &Vazio ::operator=(Bloco &b){
	if(this != &b){
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Vazio::duplica(){
	return new Vazio(*this);
}

bool Vazio::Puxa(void){
	return true;
}

bool Vazio::escava(void){
	return false;
}

void Vazio::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Vazio::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Vazio::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Vazio::retorna_peso(void){
	return this->peso;
}

int Vazio::retorna_valor(void){
	return this->valor;
}

int Vazio::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Vazio::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Vazio::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}
/*################  Polimorfismo ################################*/