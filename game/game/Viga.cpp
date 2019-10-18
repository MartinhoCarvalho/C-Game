#include "Viga.h"


Viga::Viga(void):Bloco(){
	ostringstream str;

	nome = "Viga";
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

Viga::Viga(const Viga &ob): Bloco(){
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

Viga::~Viga(void)
{
}

/*################  Polimorfismo ################################*/
bool Viga::get_permite_mineiro(void){
	return this->permite_mineiro;
}


Viga &Viga::operator=(const Bloco &b){
	if(this!= &b){// verifico senao estou a copia o mesmo objecto
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Viga::duplica(){
	return new Viga(*this);
}

bool Viga::Puxa(void){
	return true;
}

bool Viga::escava(void){
	return false;
}

void Viga::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Viga::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Viga::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Viga::retorna_peso(void){
	return this->peso;
}

int Viga::retorna_valor(void){
	return this->valor;
}

int Viga::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Viga::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Viga::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}

/*################  Polimorfismo ################################*/