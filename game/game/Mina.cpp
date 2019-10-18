#include "Mina.h"
#include "Jogo.h"


Mina::Mina(void): nome("Default"), colunas(0), linhas(0), Nivel(0), mineiro(NULL){
	Bloco ***mapa = NULL;

	mapa = new Bloco **[10];
	for(int i = 0; i < 10 ; i++){
		mapa [i] = new Bloco *[10] ;
	}

	for(int i = 0; i < 10 ; i++){
		for(int j = 0; j < 10 ; j++){
			mapa[i][j] = new Vazio();
		}
	}

}

Mina::Mina(const Mina &ob): nome(ob.nome),colunas(ob.colunas), linhas(ob.linhas), Nivel(ob.Nivel), mineiro(ob.mineiro) {
	this->mapa = new Bloco **[ob.colunas];
	for(int i = 0; i < this->colunas ; i++){
		mapa [i] = new Bloco *[this->linhas] ;
	}
	for(int i = 0; i < this->colunas ; i++){
		for(int j = 0; j < this->linhas ; j++){
			mapa[i][j] = ob.mapa [i][j]->duplica();
		}
	}
}


//operator =
Mina& Mina::operator=( const Mina &ob){
	if(this != &ob){
		colunas = ob.colunas;
		linhas = ob.linhas; 
		Nivel=ob.Nivel;
		mineiro = ob.mineiro;

		if(**mapa != NULL){
			for(int i =0 ; i< this->colunas;i++){
				for(int j = 0  ; j < this->linhas; j++){
					delete mapa[i][j];
				}
			}
		}
		mapa = NULL;
		Bloco ***temp;
		temp = new Bloco **[this->colunas];
		for(int i = 0; i < this->colunas ; i++){
			temp [i] = new Bloco *[this->linhas] ;
		}
		for(int i = 0; i < this->colunas ; i++){
			for(int j = 0; j < this->linhas ; j++){
				temp[i][j] = ob.mapa [i][j]->duplica();
			}
		}
	
		mapa = temp;
	}
	return *this; 
}

Mina::Mina(int col, int lin, int dif){
	this->colunas = col;
	this->linhas = lin;
	this->Nivel = dif;
	mapa = new Bloco **[this->colunas];
	for(int i = 0; i < this->colunas ; i++){
		mapa [i] = new Bloco *[this->linhas] ;
	}

	for(int i = 0; i < this->colunas ; i++){
		for(int j = 0; j < this->linhas ; j++){
			mapa[i][j] = NULL;
		}
	}
}

Mina::~Mina(void){
	if(mapa != NULL){
		for(int i =0 ; i< this->colunas;i++){
			for(int j = 0  ; j < this->linhas; j++){
				delete mapa[i][j];
			}	
		}
	}
	mapa=NULL;
	mineiro = NULL;
	vec.clear();
}

void  Mina::set_dados(int &col, int &lin ,int &dif){
	this->colunas = col;
	this->linhas = lin;
	this->Nivel = dif;
}

//######################## gestao do jogo ##########################################################

void Mina::setmineiro(Mineiro &ob){
	this->mineiro = &ob;
}

//introduzir dados na mina
void Mina::setnome(string &nome){
	this->nome = nome;
}

string Mina::get_nome(void){
	ostringstream str;

	str << this->nome;
	return str.str();
}

//funcao para jogar 
void Mina::jogar(Mineiro mineiro,Consola c,string FILENAME){

}
//funcao para jogar 

//#######################    metodos do jogo     ##################################################

void Mina::createBlocos()	{
	ifstream file(BLOCOS);
	string str;

	this->numero_pedras = 0;


	if(file.is_open() != NULL){
		while(getline(file,str)!= NULL){
			this->vec.push_back(str);
			numero_pedras++;
		}
	file.close();
	}
}

void Mina:: createMina(int col, int lin,int dif){
	this->colunas = col;
	this->linhas = lin;
	this->Nivel = dif;
	mapa = new Bloco **[this->colunas];
	for(int i = 0; i < this->colunas ; i++){//alocar as linhas
		mapa [i] = new Bloco *[this->linhas] ;
	}

	for(int i = 0; i < this->colunas ; i++){
		for(int j = 0; j < this->linhas ; j++){
			mapa[i][j] = NULL;
		}
	}
}

string Mina::Mapa(int col , int lin){
	ostringstream str;
	str << mapa[col][lin]->outputBloco();
	return str.str();
}

void Mina::criar_mapa_da_mina(int map_dif[][12]) {
	Bloco *bloco = NULL;
	this->mapa = new Bloco **[this->colunas];
	srand (time(NULL));
	//alocar memoria para cada linha
	for(int i = 0; i < this->colunas ; i++){
		mapa [i] = new Bloco *[this->linhas] ;
	}

	int aleatorio;
	int tipo_bloco;
	int nivel_de_profundidade;
	
	nivel_de_profundidade = 0;
	int aux = this->colunas / 4;
	int contador = 0;

	for(int i = 0; i < this->colunas ; i++){
		contador++;//conta o numero de linhas 
		for(int j = 0; j < this->linhas ; j++){
			if(j == 0){
				bloco = new Vazio();
				mapa[i][j] = bloco;
			}
			else{
			aleatorio = rand() % 100-1;
			tipo_bloco = get_tipo_de_bloco(aleatorio, nivel_de_profundidade, map_dif); // este i tem de ser calculado em função do tamanho da mina (varia entre 0 e 3)
			
			if (tipo_bloco == 0) {
				bloco = new Pedra();
			}
			else if (tipo_bloco == 1) {
				bloco = new Viga;
			}
			else if (tipo_bloco == 2) {
				bloco = new Vazio();
			}
			else if (tipo_bloco == 3){
				bloco = new Terreno_Duro();
			}
			else if (tipo_bloco == 4) {
				bloco = new Terra_Ferro();
			}
			else if (tipo_bloco ==5) {
				bloco = new Terreno_mole();
			}
			else if (tipo_bloco == 6) {
				bloco = new Terra_Aluminio();
			}
			else if (tipo_bloco == 7) {
				bloco = new Terra_Carvao();
			}
			else if (tipo_bloco == 8) {
				bloco = new Terra_Ouro();
			}	
			else if (tipo_bloco == 9) {
				bloco = new Terra_Diamante();
			}
			else if (tipo_bloco == 10) {
				bloco = new Terra_frango();
			}
			else if (tipo_bloco == 11) {
				bloco = new Escada();
			}
			mapa[i][j] = bloco;
			}
		}
		if (contador == aux) {//
			contador = 0;
			nivel_de_profundidade++;
		}
	
	}
}


int Mina::get_tipo_de_bloco(int aleatorio,int nivel_profundidade,int map_dif[][12]){
	for (int i = 0; i < 12; i++) {
		if (map_dif[nivel_profundidade][i] >= aleatorio) {
			return i;
		}
	}
	// não deve chegar aqui, mas em caso de matriz mal construída, é uma segurança por defeito
	return 0;
}

void Mina::mostra_mapa_na_consola(int x, int y, int raio,int campo_visao) {
	Consola c;
	int t = 1,l = 1,p = 1,v = 0;
	int aux = t;
	int deslocamento = 5;

	for(int i = x ; i  <  x+7 ; i++){//linhas
		v= 0;
		if(i < this->colunas){
			for(int j =  y ; j < y+7 ; j++){//colunas
				t = v * 5;
				if(j < this->linhas){
					if(campo_visao == 1){
						mapa[i][j]->desenha(deslocamento+t-2,l+1,c,true);
					}
					else{
						mapa[i][j]->desenha(deslocamento+t-2,l+1,c,false);
					}
				}
				v++;
			}
		}
		l+=5;
	}
}

void Mina::coloca_twist(void){
	int x = this->mineiro->return_cordx();
	int y = this->mineiro->return_cordy();
	if(this->mapa[x][y]->coloca_no_Inicio() == true){//coloca mineiro no inicio da mina
		int valor = 0;
		this->mineiro->set_cordx_cordy(valor,valor);
	}
}

void Mina::criar_twist(void){
	int x,y;
	 srand (time(NULL));
	 do{
		x = (rand() %this->colunas-2);
		y =  x = (rand() %this->linhas-2);
	 }while(x == 0 && y == 0);
	this->coloca_bloco_posx_posy(x,y,"TW");
}

void Mina::criar_buraco(void){
	int x,y;
	 srand (time(NULL));
	 cout << (rand() % 100 + 1) << " is the number...";
	 x = (rand() %this->colunas/2);
	 y =  x = (rand() %this->linhas/2);
	this->coloca_bloco_posx_posy(x,y,"VA");
	this->coloca_bloco_posx_posy(x,y+1,"VA");
	this->coloca_bloco_posx_posy(x,y+2,"VA");

}

//#######################    metodos do jogo          ##################################################


//####################### metodos para ler ficheiros ##################################################

void Mina ::load_save_game(string nome_ficheiro, Consola c, int &p, int &q, int &d){
	int col = 0, lin = 0, dif = 0;
	ifstream file(nome_ficheiro);
	string str;
	int contador = 0,i = 4;
	int x_col = 0, y_lin = 0;

	if(file.is_open() != NULL){
		while(getline(file,str) != NULL){
			if(contador == 0){
				col = atoi(str.c_str());
				contador++;
				p = col;
			}
			else if (contador == 1){
				lin = atoi(str.c_str());
				contador++;
				q = lin;
			}
			else if (contador == 2){
				dif = atoi(str.c_str());
				contador++;
				d = dif;
				//alocar memoria para a mina
				this->createMina(col,lin,dif);
			}
			else{// escrever pedras para um ficheiro
				i++;
				this->adiciona_bloco_mais_bloco(y_lin,x_col,str);
				 if(y_lin == 6){
					y_lin = -1;
					x_col++;
				}
				y_lin++;
			}
		}
		cout << "antes duplica" << endl;
		file.close();//fechar ficheiro
	}
	else{//erro ao abrir ficheiro
		cout << "ERRO AO ABRIR FICHEIRO " << nome_ficheiro << endl;
		c.getch();
	}

}

void Mina::adiciona_bloco_mais_bloco(int x_col, int y_lin,string str){

		if("pedra" == str){
			this->mapa[x_col][y_lin] = new Pedra();
		}	
		else if("mole" == str){
			this->mapa[x_col][y_lin]  = new Terreno_mole();
		}
		else if("duro" == str){
			this->mapa[x_col][y_lin]  = new Terreno_Duro();
		}
		else if("carvao" == str){
			this->mapa[x_col][y_lin]  = new Terra_Carvao();
		}
		else if ("aluminio" == str){
			this->mapa[x_col][y_lin]  = new Terra_Aluminio ();
		}
		else if ("ferro" == str){
			this->mapa[x_col][y_lin]  = new  Terra_Ferro ();
		}
		else if ("ouro" == str){
			this->mapa[x_col][y_lin]  = new  Terra_Ouro ();
		}
		else if ("frango" == str){
			this->mapa[x_col][y_lin]  = new  Terra_frango ();
		}
		else if("escada" == str){
			this->mapa[x_col][y_lin]  = new  Escada ();
		}
		else if("viga" == str){
			this->mapa[x_col][y_lin]  = new  Viga ();
		}
		else if("vazio" == str){
			this->mapa[x_col][y_lin]  = new  Vazio ();
		}
		else if("buraco" == str){
			this->mapa[x_col][y_lin]  = new Vazio ();
		}
		else if ("diamante" == str){
			this->mapa[x_col][y_lin] = new Terra_Diamante();
		}
}

//####################### metodos para ler ficheiros ##################################################


//###################### gestao do jogo #############################
void Mina::setContorno(int n){
	this->tam = n;
}

int Mina::getContorno(void){
	return this->tam;
}


/*################## VISAO DO MINEIRO ##############################################################*/

void Mina::desenha_mineiro_mapa(int col_mineiro,int lin_mineiro,int raio, Consola c){
	//desenha mineiro
	int t = 1,l = 1,p = 1,v = 0,flag = 0;
	int aux = t;
	int deslocamento = 5;
}

void Mina::visao_mineiro(int col_mineiro,int lin_mineiro, Consola c , Mineiro &mineiro){
	int lin = mineiro.return_cordy();
	int raio;


	raio = mineiro.return_raio_visao();
	this->visao_mineiro_raio(col_mineiro,lin_mineiro,raio,c);

		if(this->mapa[col_mineiro][lin_mineiro]->outputBloco()== "Escada"){
			mineiro.desenha(col_mineiro,lin_mineiro,raio,'E',c);
		}
		else if(this->mapa[col_mineiro][lin_mineiro]->outputBloco()== "Viga"){
			mineiro.desenha(col_mineiro,lin_mineiro,raio,'V',c);
		}
		else if(this->mapa[col_mineiro][lin_mineiro]->outputBloco()== "Dinamite"){
			mineiro.desenha(col_mineiro,lin_mineiro,raio,'D',c);
		}
		else{
			mineiro.desenha(col_mineiro,lin_mineiro,raio,' ',c);
		}
}

void Mina:: visao_mineiro_raio(int col_mineiro, int lin_mineiro,int raio,Consola c){
	int t = 1,l = 1,p = 1,v = 0,flag = 0;
	int aux = t;
	int deslocamento = 5,x = 0, y = 0;

	//mapa[1][0]->desenha(0,0,c,true);
	//mapa[1][0]->desenha(1,0,c,true);
	//mapa[1][0]->desenha(1,0,c,true);

	//cout << "Col mineiro: " << col_mineiro << endl;
	//cout << "Lin mineiro: " << lin_mineiro << endl;
	//cout << "x: " << x << endl;
	//cout << "y: " << y << endl;
	int r = 3;
	int i, j;//posicao real da mina 
	i = col_mineiro - raio;//coluna com raio aplicado no tabuleiro
	c.setBackgroundColor(c.CINZENTO);
	for(int x_tabuleiro = r - raio; x_tabuleiro <= r + raio; x_tabuleiro++) {//percorre o tabuleiro com o maximo de 6
		y = 0;
		j = lin_mineiro - raio;//linha com raio aplicado no tabuleiro
		for (int y_tabuleiro = r - raio;  y_tabuleiro <= r + raio; y_tabuleiro++) {//percorre o tabuleiro com o maximo de 6
			if (! (x_tabuleiro == r && y_tabuleiro == r)) {// não desenha na posição do mineiro (posição central)
				if(x_tabuleiro >= 0 || y_tabuleiro>= 0){
					this->mapa[0][0]->desenha(x_tabuleiro, y_tabuleiro, c, false);
				}// limpar a posição corrente
				if(i >= 0 && j >= 0 && i< this->colunas && j < this->linhas){
					//c.setTextColor(c.AMARELO_CLARO);
					//cout << "(" << i << ", " << j << ") - (" << x_tabuleiro << ", " << y_tabuleiro << ")" << endl;
					//Sleep(100);
					this->mapa[i][j]->desenha(x_tabuleiro, y_tabuleiro, c, true);
					//mapa[i][j]->desenha(0,0,c,false);//x_mina y_mina posicao real do tabuleiro
					
					
				}
			}
			//cout << "(" << i << ", " << j << ") - (" << x_tabuleiro << ", " << y_tabuleiro << ")" << endl;
			j++;
		}
		i++;
	}
	c.setBackgroundColor(c.PRETO);
}

void Mina::desenha_fundo_falso_cima(int col_mineiro, int lin_mineiro,int raio,Consola c){
	
	int i, j;//posicao real da mina 
	i = 0;//coluna com raio aplicado no tabuleiro

	int r = 3;
	for(int x_tabuleiro = 0 ; x_tabuleiro <  TAM; x_tabuleiro++) {//percorre o tabuleiro com o maximo de 6
		j = 0;//linha com raio aplicado no tabuleiro
		for (int y_tabuleiro = 0 ;  y_tabuleiro < TAM ; y_tabuleiro++) {//percorre o tabuleiro com o maximo de 6
				if (! (x_tabuleiro == r && y_tabuleiro == r))
					if(j < raio || j > r + raio){
						this->mapa[i][j]->desenha(i, j, c, false);
					}
			j++;
		}
		i++;
	}
}

void Mina::desenha_fundo_falso_lateral(int col_mineiro, int lin_mineiro,int raio,Consola c){

	int i, j;//posicao real da mina 
	i = 0;//coluna com raio aplicado no tabuleiro

	int r = 3;
	c.setTextColor(c.CINZENTO);
	for(int x_tabuleiro = 0 ; x_tabuleiro <  TAM; x_tabuleiro++) {//percorre o tabuleiro com o maximo de 6
		j = 0;//linha com raio aplicado no tabuleiro
		for (int y_tabuleiro = 0 ;  y_tabuleiro < TAM ; y_tabuleiro++) {//percorre o tabuleiro com o maximo de 6
				if (! (x_tabuleiro == r && y_tabuleiro == r))
					if(i < raio || i > raio){
						this->mapa[i][j]->desenha(i, j, c, false);
					}
			j++;
		}
		i++;
	}
	c.setTextColor(c.PRETO);
}

void Mina::redesenha_limites_tabuleiro(int col_mineiro, int lin_mineiro,int raio,Consola c){
	int t = 1,l = 1,p = 1,v = 0,flag = 0;
	int aux = t;
	int deslocamento = 5,x = 0, y = 0;
	int r = 3;
	// desenha limites superiores e inferiores para além do raio (invisível)
	for(int x_tabuleiro = r - raio;  x_tabuleiro <= r + raio; x_tabuleiro++ ){
		for (int y_tabuleiro = r - raio;  y_tabuleiro <= r + raio; y_tabuleiro++) {
			c.setTextColor(c.PRETO);
			this->mapa[0][0]->desenha(x_tabuleiro, y_tabuleiro, c, false); // desenha limite superior
			this->mapa[0][0]->desenha(x_tabuleiro, this->linhas - y_tabuleiro - 1, c, false); // desenha limite inferior
		}
	}
	// desenha limites laterais para além do raio (invisível)
	for(int y_tabuleiro = (this->linhas / 2 - raio); y_tabuleiro <  (this->linhas - (this->linhas / 2 - raio)); y_tabuleiro++) {
		for (int x_tabuleiro = 0;  x_tabuleiro < (this->colunas / 2 - raio); x_tabuleiro++) {
			this->mapa[0][0]->desenha(x_tabuleiro, y_tabuleiro, c, false); // desenha limite lateral esquerdo
			this->mapa[0][0]->desenha(this->colunas - x_tabuleiro - 1, y_tabuleiro, c, false); // desenha limite lateral direito
		}
	}
	c.setTextColor(c.PRETO);
}

/* ################## VISAO DO MINEIRO ##############################################################*/



//##################  Metodos Para os comandos ####################################

//comando b tipo col lin
int Mina::reconhece_terreno(string tipo){
	/*
	P  = pedra
	TM = terra_mole
	TD = terra dura
	A = terra_aluminio
	C = terra_carvao
	F = terra_ferro
	O = terra_ouro
	D = terra_diamante
	FF = terra_frango
	E = Escada
	V =  viga
	*/
	if(tipo == "P"){
		return 1;
	}
	else if(tipo == "TM"){
		return 2;
	}
	else if(tipo == "TD"){
		return 3;
	}
	else if(tipo == "A"){
		return 4;
	}
	else if(tipo == "C"){
		return 5;
	}
	else if(tipo == "F"){
		return 6;
	}
	else if(tipo == "O"){
		return 7;
	}
	else if(tipo == "D"){
		return 8;
	}
	else if(tipo == "FF"){
		return 9;
	}
	else if(tipo == "E"){
		return 10;
	}
	else if(tipo == "V"){
		return 11;
	}

	return 100;
}

void Mina::coloca_bloco_posx_posy(int x , int y, string tipo){

	/*
	P  = pedra
	TM = terra_mole
	TD = terra dura
	A = terra_aluminio
	C = terra_carvao
	F = terra_ferro
	O = terra_ouro
	D = terra_diamante
	FF = terra_frango
	E = Escada
	V =  viga
	*/
	if(x >= 0 && y >= 0 && x < this->colunas && y < this->linhas){
			if(tipo == "P"){//pedra
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
				delete this->mapa[x][y];
				this->mapa[x][y] = new Pedra();
				}
			}
			else if(tipo =="TM"){//terreno mole
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
				delete this->mapa[x][y];
				this->mapa[x][y] = new Terreno_mole();
				}
			}
			else if(tipo =="TD"){//terreno duro
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
					delete this->mapa[x][y];
					this->mapa[x][y] = new Terreno_Duro();			
				}
			}
			else if(tipo =="A"){//terra aluminio
			if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
				delete this->mapa[x][y];
				this->mapa[x][y] =new Terra_Aluminio();
				}
			}
			else if(tipo =="C"){//terra (carvao)
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
					delete this->mapa[x][y];
					this->mapa[x][y] = new Terra_Carvao();
				}
			}
			else if(tipo =="F"){//terra (Ferro)
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
					delete this->mapa[x][y];
					this->mapa[x][y] = new Terra_Ferro();
				}
			}
			else if(tipo =="O"){//terra (Ouro)
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
					delete this->mapa[x][y];
					this->mapa[x][y] = new Terra_Ouro();
				}
			}
			else if(tipo =="D"){//terreno (Diamante)
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
					delete this->mapa[x][y];
					this->mapa[x][y] = new Terra_Diamante();
				}
			}
			else if(tipo =="FF"){//terreno (Frango)
				if(this->mineiro->return_cordx() != x || this->mineiro->return_cordy() != y){//para nao colocar uma pedra em cima do mineiro
					delete this->mapa[x][y];
					this->mapa[x][y] = new Terra_frango();
				}
			}
			else if(tipo =="E"){//(Escada)
				delete this->mapa[x][y];
				this->mapa[x][y] = new Escada();
				
			}
			else if(tipo =="V"){//(Viga)
				delete this->mapa[x][y];		
				this->mapa[x][y] =new Viga();		
			}
			else if (tipo =="VA"){
				delete this->mapa[x][y];		
				this->mapa[x][y] =new Vazio();
			}
			else if (tipo =="DI"){//dinamite
				delete this->mapa[x][y];
				this->mapa[x][y] = new Dinamite_bloco();
			}
			else if (tipo == "TW"){
					delete this->mapa[x][y];		
					this->mapa[x][y] =new Twist();
			}
		}
}

// comando c lin col
void Mina::coloca_mineiro_na_posicao(int x, int y){
	if(this->mapa[x][y]->outputBloco() != "Escada" || this->mapa[x][y]->outputBloco() != "Viga"){
		delete this->mapa[x][y];
		this->mapa[x][y]=new Vazio();
	}
}

//##################  Metodos Para os comandos ####################################


//########################## funcoes da mina ############################

bool Mina::restricao(void){
	int x = this->mineiro->return_cordx();
	int y = this->mineiro->return_cordy();

	if(this->mapa[x][y+1]->outputBloco() == "Vazio" || this->mapa[x][y+1]->outputBloco() == "Viga"){//viga puxa
		return true;
	}
	return false;//senao para
}

void Mina::gruta_retira_vida(int  &numero_blocos){
	if(numero_blocos == 1){
		float valor = 0.0;
		this->mineiro->retira_vida(valor);
	}
	else if (numero_blocos >= 2){//se numero de espaco for superior a 2
		float total = 10 *(numero_blocos-1);
		float t1 = 1.0;
		float t2 =t1/total;
		t2 = t2*(-1.0) ;
		if(this->mineiro->return_paraquedes() >= 1){//se tiver algum paraquedas nao perde vida :D
			this->mineiro->paraquedas_decrementa();
		}
		else{//senao olha la perde vida
			this->mineiro->retira_vida(t2);
		}
	}
}

void Mina::mata_mineiro(void){
	float valor = 0.0;
	this->mineiro->actualiza_vida(valor);
}

int Mina::gruta(void){
	int x = this->mineiro->return_cordx();
	int y = this->mineiro->return_cordy();
	int i = this->mineiro->return_cordx();
	int j = this->mineiro->return_cordy();
	int n = 0;
	int cond = this->mineiro->return_cordy();

	
	if((this->linhas- cond) == 2 && this->mapa[x][y+1]->outputBloco() != "Vazio"){
		return 0;
	}
	if((this->linhas- cond) == 2 && this->mapa[x][y+1]->Puxa() == true && this->restricao() == true){
		return 1;
	}
	else if ((this->linhas- cond) == 1 && this->mapa[x][y]->Puxa() == true){
		return 1;
	}
	else{ 
		if((this->linhas - cond)== 1){//ultima linha
			return 1;
		}

		if(this->mapa[x][y]->Puxa() == true ){//se bloco puxar entao executa a accao
			while (this->mapa[x][y+1]->get_permite_mineiro() == true && this->restricao() == true && this->mapa[x][y+1]->outputBloco() != "Escada"){
					cond = y;
					if((this->linhas-cond)<=2){//verificar se tiver1
						return 1;
					}
					else{
						y++;n++;
					}
			}
			this->mineiro->set_cordx_cordy(x,y);
			this->gruta_retira_vida(n);
		}
		return 0;
	}
}

bool Mina::percorrer_mapa(int x ,int y){
	if(this->mapa[x][y]->outputBloco() == "Dinamite"){
		return true;
	}
	return false;
}

void Mina::puxa_pedra(int &x,int &y){
	int lin = 0;
	int j = y;
	Consola c;
	string msg;
	lin = this->linhas;
	if((lin - y) > 2 ){
		this->coloca_bloco_posx_posy(x,y,"VA");
		while(this->mapa[x][j+1]->outputBloco()=="Vazio"){
			lin = this->linhas -j;
			if(lin > 2){
				float valor =  0.0;
				if(x == this->mineiro->return_cordx() && (j+1) == this->mineiro->return_cordy() ) {//
					c.setTextColor(c.VERMELHO_CLARO);
					c.gotoxy(45,34);
					c.deletE(44,33,30,16);
					cout << " WARNING " << endl;
					c.gotoxy(45,34);
					cout << "Deseja aplicar uma viga porque tem ";
					c.gotoxy(45,35);
					cout <<" uma pedra por cima  "<< endl;
					c.gotoxy(45,36);
					cout << "SIM --s || NAO--n"<< endl;
					c.gotoxy(45,37);
					getline(cin,msg);
					if(msg=="s" && this->mineiro->return_numero_recargas() >= 5){
						int valor = 5;
						this->mineiro->aplica_viga(valor);
						this->coloca_bloco_posx_posy(this->mineiro->return_cordx(),this->mineiro->return_cordy(),"V");
						c.clrscr();
						break;
					}else{
						this->mineiro->actualiza_vida(valor);
					}
					msg =" ";
					c.clrscr();
					c.setTextColor(c.PRETO);
				}
				j++;
			}
			else{
				break;
			}
		}
		this->coloca_bloco_posx_posy(x,j,"P");
	}
}

void Mina::cai_pedra(void){
	int linha = this->mineiro->return_cordy();
	for(int i = 0; i < this->colunas; i++){
		for(int j = 0; j < this->linhas; j++){
			if(this->mapa[i][j]->outputBloco() =="pedra"){
				this->puxa_pedra(i,j);//este metodo vai puxar as pedra todas para baixo
			} 
		}
	}
}

void Mina::mineiro_da_martelada(int &x, int &y){
	if(this->mapa[x][y]->escava()== true){//vefirica se pode ser escavado
		int numero_toques = mineiro->numero_marteladas();
		this->mapa[x][y]->recebe_toque(numero_toques);
		float v = -1.0;
		this->mineiro->retira_vida(v);
		if(this->mapa[x][y]->retorna_numero_toques_recebidos() >= this->mapa[x][y]->retorna_numero_toques_ate_partir()){
			this->mineiro->set_n_pedras_escavadas();
			int peso = mapa[x][y]->retorna_peso();
			int valor= mapa[x][y]->retorna_valor();
			int vida = this->mapa[x][y]->da_energia();
			this->mineiro->recarrega_vida(vida);
			delete this->mapa[x][y];
			this->mapa[x][y] = new Vazio;
			this->mineiro->carrega_mochila(peso,valor);
		}
	}
}

//###################### polimorfismo ################################################################
bool Mina::verifica(int x, int y){
	return this->mapa[x][y]->get_permite_mineiro();
}


//metodos de perguntas do mineiro
bool Mina::resposta_posicao(int lin){
	if(lin == 0)
		return true;
	else
		return false;
}

//metodos de perguntas do mineiro

//###################### polimorfismo ################################################################

//###################### gestao do jogo #############################