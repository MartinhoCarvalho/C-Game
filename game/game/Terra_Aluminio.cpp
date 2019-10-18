#include "Terra_Aluminio.h"


Terra_Aluminio::Terra_Aluminio(void){
	ostringstream str;

	nome = "Aluminio";
	str << (char) 218  << (char) 196 << (char) 196 << (char) 196 << (char) 191 << '\n' 
		<< (char) 179 << (char) 233 << (char) 233 << (char) 233 << (char) 179 << '\n'
		/*<< (char) 179 << (char) 233 << (char) 233 << (char) 233 << (char) 179 << '\n'*/
    	<< (char) 179 << (char) 233 << (char) 233 << (char) 233 << (char) 179 << '\n'
        << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = true;
    toques_picareta_ate_partir = 2;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->peso = 1;
	this->valor = 5;


}

Terra_Aluminio::Terra_Aluminio(const Terra_Aluminio &ob){
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

Terra_Aluminio::~Terra_Aluminio(void){

}

/*################  Polimorfismo ################################*/
bool Terra_Aluminio::get_permite_mineiro(void){
	return this->permite_mineiro;
}

bool Terra_Aluminio::escava(void){
	return true;
}

Terra_Aluminio & Terra_Aluminio::operator=(const Bloco &b){
	if(this!= &b){// verifico senao estou a copia o mesmo objecto
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Terra_Aluminio::duplica(){
	return new Terra_Aluminio(*this);
}

bool Terra_Aluminio::Puxa(void){
	return false;
}

void Terra_Aluminio::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terra_Aluminio::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terra_Aluminio::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terra_Aluminio::retorna_peso(void){
	return this->peso;
}

int Terra_Aluminio::retorna_valor(void){
	return this->valor;
}

int Terra_Aluminio::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terra_Aluminio::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terra_Aluminio::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}


/*################  Polimorfismo ################################*/