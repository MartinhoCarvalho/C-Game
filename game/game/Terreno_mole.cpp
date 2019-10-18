#include "Terreno_mole.h"


Terreno_mole::Terreno_mole(void):Bloco(){
	ostringstream str;

	nome = "Terreno_mole";
	str << (char) 218  << (char) 196 << (char) 196 << (char) 196 << (char) 191 << '\n' 
		<< (char) 179 << (char) 177 << (char) 177 << (char) 177 << (char) 179 << '\n'
       /* << (char) 179 << (char) 177 << (char) 177 << (char) 177 << (char) 179 << '\n'*/
		<< (char) 179 << (char) 177 << (char) 177 << (char) 177 << (char) 179 << '\n'
		<< (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = true;
    toques_picareta_ate_partir = 1;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->peso = 0;
	this->valor = 0;
}


Terreno_mole::Terreno_mole(const Terreno_mole &ob):Bloco(){
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


Terreno_mole::~Terreno_mole(void){
}

/*################  Polimorfismo ################################*/
bool Terreno_mole::get_permite_mineiro(void){
	return this->permite_mineiro;
}


Terreno_mole & Terreno_mole::operator=(const Bloco &b){
	if(this != &b){
		Bloco::operator=(b);
	}
	return *this;
}


Bloco *Terreno_mole::duplica(){
	return new Terreno_mole(*this);
}

bool Terreno_mole::Puxa(void){
	return false;
}

bool Terreno_mole::escava(void){
	return true;
}


void Terreno_mole::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terreno_mole::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terreno_mole::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terreno_mole::retorna_peso(void){
	return this->peso;
}

int Terreno_mole::retorna_valor(void){
	return this->valor;
}

int Terreno_mole::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terreno_mole::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terreno_mole::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}





/*################  Polimorfismo ################################*/