#include "Terreno_Duro.h"


Terreno_Duro::Terreno_Duro(void):Bloco(){
	ostringstream str;

	nome = "Terreno_Duro";
	str << (char) 218  << (char) 196 << (char) 196 << (char) 196 << (char) 191 << '\n' 
		<< (char) 179 << (char) 178 << (char) 178 << (char) 178 << (char) 179 << '\n'
		/*<< (char) 179 << (char) 178 << (char) 178 << (char) 178 << (char) 179 << '\n'*/
    	<< (char) 179 << (char) 178 << (char) 178 << (char) 178 << (char) 179 << '\n'
        << (char) 192 << (char) 196 << (char) 196 << (char) 196 << (char) 217 << '\n';
	this->aspecto = str.str();
	pode_escavar = true;
	permite_mineiro = false;
    cai_no_espaco_vazio = true;
    toques_picareta_ate_partir = 2;
    toques_picareta_recebidos = 0;
    energia_a_dar_ou_retirar = 0;
	this->peso = 0;
	this->valor = 0;
}


Terreno_Duro::Terreno_Duro(const Terreno_Duro &ob){
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

Terreno_Duro::~Terreno_Duro(void){
}



/*################  Polimorfismo ################################*/

bool Terreno_Duro::get_permite_mineiro(void){
	return this->permite_mineiro;
}

Terreno_Duro &Terreno_Duro::operator=(const Bloco &b){
	if(this != &b){
		Bloco::operator=(b);
	}
	return *this;
}

Bloco *Terreno_Duro::duplica(){
	return new Terreno_Duro(*this);
}

bool Terreno_Duro::Puxa(void){
	return false;
}

bool Terreno_Duro::escava (void){
	return true;
}

void Terreno_Duro ::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Terreno_Duro::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Terreno_Duro::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Terreno_Duro::retorna_peso(void){
	return this->peso;
}

int Terreno_Duro::retorna_valor(void){
	return this->valor;
}

int Terreno_Duro::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Terreno_Duro::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}
int Terreno_Duro::da_energia(void){
	return this->energia_a_dar_ou_retirar;
}

/*################  Polimorfismo ################################*/