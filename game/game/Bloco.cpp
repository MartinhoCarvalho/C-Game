#include "Bloco.h"


string Bloco::outputBloco(){
	ostringstream str;

	str << this->nome;
	//str << this->aspecto  << this->nome << " " << this->tipo_minerio << " " << this->toquesMax ;
	return str.str();
}

string Bloco::getAspecto(int x){
	ostringstream str;

	str << this->aspecto[x];
	return str.str();
}

char Bloco::getCaracter(void){
	return this->aspecto[8];
}

void Bloco::incrementa_toque_picareta(void){
	this->toques_picareta_recebidos += 1;
}

int Bloco::get_toques_de_picareta_recebidos(void){
	return this->toques_picareta_recebidos;
}

void Bloco::desenha(int x, int y, Consola c, bool visivel){
	int x_consola, y_consola;
	int t, l;

	int deslocamento = 5;

	t = x * 5;
	l = y * 5;
	x_consola = deslocamento + t-2;
	y_consola = l +2;
	desenha_coord_consola(x_consola,y_consola, c,visivel);
}

void Bloco::desenha_coord_consola(int x_consola,int y_consola, Consola c, bool visivel){
	// desenha contorno do bloco
	if (visivel == true) {
		if(this->outputBloco() != "Vazio" && this->outputBloco() != "Escada" && this->outputBloco() != "Viga" && this->outputBloco() != "Dinamite"){//se for bloco vazio nao desenha contorno
			this->cor();
			c.desenha_rectangulo_bloco(x_consola, y_consola, 5, 5);//do as codernadas e ele imprime
			c.setTextColor(c.PRETO);
		}
		else{// #############################
		int x = 0, y = 0;
		if(this->outputBloco() == "Escada"){// se for escada desenha escada
				for (int t = y_consola; t < y_consola+5; t++) {//linhas
					c.setTextColor(c.AMARELO);
					y = 0;
					for(int i = x_consola; i < x_consola+5; i++){//colunas
						if(y == 0 || y == 4){
							c.gotoxy(i, t);//posicionar o caracter no ecran
							cout << (char)'|';
						}
						else{
							c.gotoxy(i, t);//posicionar o caracter no ecran
							//c.setTextColor(c.AMARELO);
							cout << (char)'-';
						}
						y++;
					}
					x++;
				}
				c.setTextColor(c.PRETO);
			}
			else if(this->outputBloco() =="Viga"){
				c.setTextColor(c.AMARELO);
				for (int t = y_consola; t < y_consola+5; t++) {//linhas
					y = 0;
					for(int i = x_consola; i < x_consola+5; i++){//colunas
						if((x ==0 && y == 0) || (x == 0 &&y == 4)){
							c.gotoxy(i, t);//posicionar o caracter no ecran
							cout << (char) 203;
						}
						else{
							c.gotoxy(i, t);//posicionar o caracter no ecran
							cout << (char)' ';
						}
						y++;
					}
					x++;
				}
			c.setTextColor(c.PRETO);
			}
			else if (this->outputBloco() == "Vazio"){//se for bloco vazio entra aqui
				for (int t = y_consola; t < y_consola+5; t++) {//linhas
					for(int i = x_consola; i < x_consola+5; i++){//colunas
						c.gotoxy(i, t);//posicionar o caracter no ecran
						cout << (char)' ';
					}
				}
			}
			else if (this->outputBloco() == "Dinamite"){//se for bloco vazio entra aqui
				c.setTextColor(c.AZUL_CLARO);
				for (int t = y_consola; t < y_consola+5; t++) {//linhas
					y = 0;
					for(int i = x_consola; i < x_consola+5; i++){//colunas
						if((x ==0 && y == 0 ) || (x == 0 &&y == 4)|| (x == 4 &&y == 0)|| (x == 4 &&y == 4)){
							c.gotoxy(i, t);//posicionar o caracter no ecran
							cout << "*";
						}
						else{
							c.gotoxy(i, t);//posicionar o caracter no ecran
							cout << (char)' ';
						}
						y++;
					}
					x++;
				}
				c.setTextColor(c.PRETO);
			}
		}
	}
	else {
		for (int t = y_consola; t < y_consola+5; t++) {//linhas
			for(int i = x_consola; i < x_consola+5; i++){//colunas
				c.gotoxy(i, t);//posicionar o caracter no ecran
				//c.setTextColor(c.CINZENTO);
				cout << (char)219;
			}
			//c.setTextColor(c.PRETO);
		}
	}
	//se for diferente de vazio escada e viga desenha contorno
	if(this->outputBloco() != "Escada" && this->outputBloco() != "Viga"&& this->outputBloco() != "Vazio" && visivel && this->outputBloco() != "Dinamite"){
		for(int i = x_consola + 1; i < x_consola+4 ; i++){//linhas
			for(int j = y_consola + 1; j < y_consola+4 ; j++){// colunas
				c.gotoxy(i,j);
				this->cor();
				cout << this->getAspecto(7);
		     }
		}
		c.setTextColor(c.PRETO);
	}
}
	
void Bloco::recebe_toque(int &valor){
	this->toques_picareta_recebidos += valor;
}

int Bloco::retorna_numero_toques_recebidos(void){
	return this->toques_picareta_recebidos;
}

int Bloco::retorna_numero_toques_ate_partir(void){
	return this->toques_picareta_ate_partir;
}



//####################### polimorfismo #############################################

bool Bloco::desaba(void){
	return false;
}


//operator = com polimorfismo
Bloco &Bloco::operator=(const Bloco &b){
	return *this;
}


Bloco ::~Bloco(void){
	
}

//####################### polimorfismo #############################################