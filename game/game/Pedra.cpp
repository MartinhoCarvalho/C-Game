#include "Pedra.h"


Pedra::Pedra(void):Bloco(){
	ostringstream str;

	
	nome = "pedra";
		str << (char) 218  << (char) 196 << (char) 196 << (char) 196 << (char) 191 << '\n' 
			<< (char) 179 << (char) 176 << (char) 176 << (char) 176 << (char) 179 << '\n'
   /*         << (char) 179 << (char) 176 << (char) 176 << (char) 176 << (char) 179 << '\n'*/
			<< (char) 179 << (char) 176 << (char) 176 << (char) 176 << (char) 179 << '\n'
            << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	this->peso = 0;
	this->valor = 0;
	pode_escavar = false;
	permite_mineiro= false;
    cai_no_espaco_vazio = true;
    toques_picareta_ate_partir = 0;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
}


Pedra::Pedra(const Pedra &ob){
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

Pedra::~Pedra(void){
}


/*################  Polimorfismo ################################*/

bool Pedra::get_permite_mineiro(void){
	return this->permite_mineiro;
}


Pedra & Pedra::operator=(const Bloco &b){
	if(this!= &b){// verifico senao estou a copia o mesmo objecto
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Pedra::duplica(){
	return new Pedra (*this);
}

bool Pedra::Puxa(void){
	return false;
}


bool Pedra::escava(void){
	return false;
}

bool Pedra::desaba(void){
	return true;
}


void Pedra::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Pedra::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Pedra::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Pedra::retorna_peso(void){
	return this->peso;
}

int Pedra::retorna_valor(void){
	return this->valor;
}

int Pedra::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Pedra::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Pedra::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}

/*################  Polimorfismo ################################*/
