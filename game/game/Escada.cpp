#include "Escada.h"


Escada::Escada(void):Bloco(){
	ostringstream str;

	nome = "Escada";
	str << (char) 179 << (char) ' ' << (char) ' ' << (char) ' ' << (char) 179 << '\n'
		<< (char) 195 << (char) 196 << (char) 196 << (char) 196 << (char) 180 << '\n'
	    << (char) 195 << (char) 196 << (char) 196 << (char) 196 << (char) 180 << '\n'
    	<< (char) 195 << (char) 196 << (char) 196 << (char) 196 << (char) 180 << '\n'
        << (char) 179 << (char) ' ' << (char) ' ' << (char) ' ' << (char) 179 << '\n';
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

Escada::Escada(const Escada &ob):Bloco(){
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

Escada::~Escada(void){

}

/*################  Polimorfismo ################################*/

bool Escada::get_permite_mineiro(void){
	return this->permite_mineiro;
}


bool Escada::escava(void){
	return false;
}

Escada &Escada::operator=(const Bloco &b){
	if(this!= &b){// verifico senao estou a copia o mesmo objecto
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Escada::duplica(){
	return new Escada(*this);
}

bool Escada::Puxa(void){
	return false;
}

void Escada::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Escada::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Escada::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Escada::retorna_peso(void){
	return this->peso;
}

int Escada::retorna_valor(void){
	return this->valor;
}

int Escada::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Escada::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Escada::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}


/*################  Polimorfismo ################################*/