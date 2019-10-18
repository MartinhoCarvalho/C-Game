#include "Jogo.h"


//########################## Construtor  & Destrutor ############################
Jogo::Jogo(void){
	this->tam = n;
	lista = new Mineiro *[this->tam];
	lista2 = new Mina *[this->tam];
	this->condicao_paragem = 0;
	this->paragem = 0;
	this->tempo = 0;
	this->comando = "hfgjhasgfjdgjkfgdks";
	this->BLocos_Partidos = 0;
	int mapa_temp[4][12] = {//nivel 1
			{0, 0, 0, 10, 15, 12, 20, 25,45 , 55,65 , 0},
			{0, 0, 0, 10, 15, 12, 35, 25,45 , 55,65 , 0},
			{5, 0, 0, 10, 15, 12, 35, 25,45 , 55,65 , 0},
			{56, 0, 0, 5, 10, 6, 15, 18,23 , 22,30 , 0},
		};
	int mapa_temp2[4][12] = {//nivel2
			{5, 0, 0, 10, 15, 12, 20, 25,45 , 55,65 , 0},
			{0, 0, 0, 5, 10, 9, 28, 25,35 , 45,55 , 0},
			{0, 0, 0, 5, 10, 9, 28, 25,35 , 45,55 , 0},
			{25, 0, 0, 5, 10, 6, 15, 18,23 , 22,30 , 0},
		};

	this->duplica_array(mapa_temp);
	this->duplica_array2(mapa_temp2);
}

void Jogo::duplica_array(int mapa[][12]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 12 ; j++){
			this->mapa_dif[i][j] = mapa[i][j];
			//this->ecran.setTextColor(this->ecran.BRANCO_CLARO);
			//cout << mapa_dif[i][j] << " ";
		}
	}
}

void Jogo::duplica_array2(int mapa[][12]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 12 ; j++){
			this->mapa_dif2[i][j] = mapa[i][j];
			//this->ecran.setTextColor(this->ecran.BRANCO_CLARO);
			//cout << mapa_dif[i][j] << " ";
		}
	}
}

Jogo::~Jogo(void){
	for(int i = 0; i < this->tam; i++){
		delete lista[i];
		delete lista2[i];
	}
	lista = NULL;
	lista2 = NULL;
	vec.clear();
	vec2.clear();
	tabela_precos.clear();
	lista_comandos.clear();
}

//########################## Construtor  & Destrutor ############################

// ############################### FUNCOES DE JOGO   ################################### 

void debug(char *str) {
	if (DEBUG) {
		cout << str << endl;
	}
}

void Jogo::limpa_minas_mineiros(void){
	for(int i = 0; i < this->tam; i++){
		 *lista[i];
		*lista2[i];
		*time[i];
	}
	lista = NULL;
	lista2=NULL;
	Mina **temp2 = NULL;
	Mineiro **temp;
	this->tam = 0;
	temp = new Mineiro *[0]; 
	temp2 = new Mina *[0];
	lista = temp;
	lista2 = temp2;
	this->BLocos_Partidos = 0;
	this->file =TABELA_PRECOS; 
	tabela_precos.clear();
}

void Jogo::reconhece_comandos(string &comando, Mina &mina,Mineiro &mineiro){
	ecran.clrscr();
	int op  = 0;
	while(op == 0){
		this->ecran.clrscr();
		cout << this->LoadInsertConfiguracoes();
		ecran.putch('>');
		ecran.putch(' ');
		getline(cin,comando);
		this->ValidaComandoStartGame(comando,mina,mineiro);
		if(this->comando == "exit" ){
			op = 1;
		}
	}	
	comando="";
}

void Jogo::ValidaComandoStartGame(string comando,Mina &mina, Mineiro &mineiro){
	stringstream pal(comando);
	vector<string>::iterator i;
	int contador = 0;

	while(getline(pal,(str),' ')){
		vec.push_back(str);
		if(contador == 0){//tipo
			this->comando2  = str;
		}
		else if (contador == 1){//nome
			this->comando3 = str;
		}
		else if (contador == 2){//lin
			this->comando4 = str;
		}
		else if (contador == 3){//col
			this->comando5 = str;
		}
		else if (contador == 4){//dif
			this->comando6 = str;
		}
		contador++;
	}

	if(this->comando2 == "reload"){
		//verifcar se existe ficheiro
		this->valida_nome_ficheiro();
		this->LoadFicheiroUtensilios(this->file);
		mina.load_save_game(this->comando3,this->ecran,this->col,this->lin,this->dif);//faz load 
		for(i = vec.end()-1; i > vec.begin(); i--){
			i=vec.erase(i);
		}
		i=vec.begin();
		i =vec.erase(i);
	}
	else if(this->comando2== "jogo"){
		this->valida_nome_ficheiro();
		this->LoadFicheiroUtensilios(this->file);
		int v1 = 10,v2 = 10,v3 = 10;
		if(contador >= 4){
			this->nome = this->comando3;
			this->lin = atoi(this->comando4.c_str());
			this->col = atoi(this->comando5.c_str());
			this->dif = atoi(this->comando6.c_str());
			str = this->nome;
			v1 = this->col;
			v2 = this->lin;
			v3 = this->dif;
			mina.setnome(str);
			mina.set_dados(v1, v2,v3);
		}
		if(this->dif <= 1){//easy game =)
			mina.criar_mapa_da_mina(this->mapa_dif);
		}
		else {
			mina.criar_mapa_da_mina(this->mapa_dif2);
		}
		mina.criar_buraco();
		mina.criar_twist();
	}
	else if(this->comando2 == "load"){//copiar o nome do file de dados
		this->file = this->comando3;
		this->valida_nome_ficheiro();
		this->LoadFicheiroUtensilios(this->file);
		this->file = TABELA_PRECOS;
	}
	
}

//faz lodo dos logotipos e do start menu e score e etc
void Jogo::game(void){
	vector<string>::iterator i;
	Mina *mina_temp;
	Mineiro *mineiro_temp;
	int v1 = 10;
	this->Loadlogotipo();
 	Sleep(2000);
	ecran.clrscr();
	string op;
	int valor = 0;
	ecran.HideCursor();
	this->inserir_tabela_comandos();
	this->file = " ";
	// ########################  mina de jogo so existe uma ###################################
	// ########################  mina de jogo so existe uma ###################################

	while( valor == 0){
		this->ecran.setTextColor(this->ecran.AZUL_CLARO);
		cout << "##################################################################################";
		this->LoadStartMenu();;
		cout<< "###################################################################################" << endl;
		cout << ">> ";
		this->ecran.setBackgroundColor(this->ecran.PRETO);
		this->ecran.setTextColor(this->ecran.BRANCO);
		getline(cin,op);
		if(op == "1" && this->col > 0 && this->lin > 0 && this->dif > 0){// jogar o jogo;
			this->ecran.setTextColor(this->ecran.AMARELO);
			Mina mina(*mina_temp);
			Mineiro mineiro (*mineiro_temp);
			lista[0] = &mineiro;
			lista2[0] = &mina;
			this->gere_jogo();
			i = vec.begin();
			this->col = 0 ; this->lin = 0; this->dif = 0;
			this->ecran.getch();
			this->limpa_minas_mineiros();
		}
		else if (op == "2"){
			mina_temp = new Mina ();
			mineiro_temp = new Mineiro();
			mina_temp->set_dados(v1,v1,v1);
			mina_temp->criar_mapa_da_mina(this->mapa_dif);
			this->reconhece_comandos(this->comando,*mina_temp,*mineiro_temp);
		}
		else if (op == "3"){//mostra scores dos jogadores
			ecran.clrscr();
		    cout << this->LoadScore() <<endl;
		    ecran.getch();
		}
		else if (op == "4"){//sair do jogo
			valor = 1;
		}
		ecran.clrscr();
	}//fim while
}

void Jogo::gere_jogo(void){
	Mineiro mineiro(*lista[0]);
	Mina mina (*lista2[0]);
	int col = 2, lin = 1;//posicao da mina 
	int poscol = mineiro.return_cordx(),poslin = mineiro.return_cordy();//dados do mineiro 
	int tempo = 0;

	mineiro.set_mina(mina);//mineiro -> &mina
	mina.setmineiro(mineiro);//mina -> &mineiro
	this->ecran.clrscr();
	while(this->condicao_paragem == 0){
		this->superfice_vida(mineiro);
		this->condicao_paragem=mina.gruta();
		poscol = mineiro.return_cordx();
		poslin = mineiro.return_cordy();
		this->desenha_ecran(tempo,mineiro,poscol,poslin);// este metodo deve ser feito pela consola 
    	mina.visao_mineiro(poscol,poslin ,this->ecran,mineiro);
		this->tecla =this->ecran.getch();
		mina.cai_pedra();//para as pedras cairem
		this->teclado_setas(mineiro,mina,poscol,poslin);
		this->comando_tecla_e(mineiro);
		this->comando_tecla_v(mineiro);
		this->comando_tecla_d(mineiro,mina);
		this->comando_tecla_x(mineiro,mina);
		this->comando_tecla_r(mineiro);
		this->converte_valores_em_moedas(mineiro);
		this->comando_tecla_p();
		this->comando_tecla_c(poscol,poslin,mineiro,mina);
		mina.coloca_twist();//meu bloco que eu fiz 
		this->save_blocos_partidos_mineiro(mineiro);
		this->verifica_numero_blocos_escavados(mineiro);
		this->check_life_mineiro(mineiro,mina);
	}
	this->condicao_paragem = 0;
	this->save_Score_player();
}

void Jogo::verifica_numero_blocos_escavados(Mineiro &mineiro){
	float p = 0;
	int temp = this->col * this->lin;
	if(this->dif <= 1){
		p= .05;
	}
	else{
		p = 0.10;
	}
	float Percentagem=  ( (this->col * this->lin) * p);
	if(this->BLocos_Partidos > Percentagem){//se ja partiu mais de 60% entao o jogo termina
		this->ecran.clrscr();
		this->ecran.setTextColor(this->ecran.VERMELHO_CLARO);
		cout << "Parabens GANHOU  :) :) :)" << endl;
		this->ecran.getch();
		this->ecran.getch();
		this->condicao_paragem = 1;
	}
}

void Jogo::save_blocos_partidos_mineiro(Mineiro &mineiro){
	this->BLocos_Partidos=mineiro.get_numero_blocos_escavados();
}

void Jogo::faz_concatenar_string_adciona_preco(string comando){
	stringstream pal(comando);
	string str,str2;
	int contador = 0,p;

	while(getline(pal,(str),' ')){
		if(contador == 0){
			str2 = str;
		}
		else if(contador == 2){
			p = atoi(str.c_str());
			tabela_precos.insert(pair<string,int>(str2,p));
		}
		contador++;
	}//apagar objecto dinamico
}

void Jogo::LoadFicheiroUtensilios(string comando){
	stringstream pal();
	string nome,str;
	int contador = 0;
	ifstream File(comando);

	if(File.is_open() != NULL){
		while(getline(File,str) != NULL){
			this->faz_concatenar_string_adciona_preco(str);
		}	
	File.close();
	}
	else{
		cout << "Erro ao ler ficheiro" << endl;
	}
	this->file.clear();
}

void Jogo::loadAtributosJogo(string comando){
	ostringstream str;
	stringstream pal (comando),temp;
	string str2;
	int contador = 0;

	while(getline(pal,(str2),' ')){
		if(contador == 1){
			this->nome = str2;
		}
		else if(contador == 2){
			this->col = atoi(str2.c_str());//numero de colunas
		}
		else if (contador == 3){
			this->lin = atoi(str2.c_str());
		}
		else if (contador == 4){
			this->dif = atoi(str2.c_str());
		}
		contador++;
	}
}

void  Jogo::Loadlogotipo(void){
	ostringstream str;
	string str2;
	ifstream file(LOGOTIPO);

	this->ecran.setTextColor(this->ecran.VERDE_CLARO);
	if(file.is_open() != NULL){
		while(getline(file,str2) != NULL){
			cout << str2 << endl;
		}
		//fechar ficheiro
		file.close();
	}
	else{
		cout << "ERRO AO LER FICHEIRO  " << LOGOTIPO << endl;
 	}
	this->ecran.setBackgroundColor(this->ecran.PRETO);
}

void  Jogo::LoadStartMenu(void){
	string str2;
	ostringstream str;
	ifstream file(STARTMENU);

	if(file.is_open() != NULL){
		while(getline(file,str2) != NULL){
			//str << str2 << endl ;
			cout << "\t\t"<<str2 << endl;
		}
	file.close();//fechar ficheiro
	}
	else{
		cout << "ERRO AO LER FICHEIRO " << STARTMENU << endl;
	}
}

string Jogo::LoadInsertConfiguracoes(void){
	ostringstream str ;

	str << "##############################################################################" << endl;
    str << "\t\t\tload nome-ficheiro" << endl;
	str << "\t\t\tjogo nome lin col dif" << endl;
	str << "\t\t\texit | Back to StarMenu" << endl;
	str << "###############################################################################" << endl;
	return str.str();
}

string Jogo::LoadScore(void){
	ostringstream str;
	string str2;
	ifstream file(SCORE);

	if(file.is_open() != NULL){
		while(getline(file,str2) != NULL){
			str << str2 <<endl;
		}
		file.close();
	}
	else{
		cout << "ERRO AO LER FICHEIRO   " << SCORE <<endl;
	}
	return str.str();
}

void Jogo::save_Score_player(void){
	string line;
	ifstream myfile (SCORE);
	ofstream temp ("example.txt");
	if (myfile.is_open()&&temp.is_open()){//verifco se os dois abriram correctamente 
		while ( getline (myfile,line) ){
				temp<<line<<endl;
		}
		myfile.close();
	}
	this->ecran.clrscr();
	this->ecran.setTextColor(this->ecran.BRANCO);
	cout << "INTRODUZA O SEU NOME "<<endl;
	string nome ="Player";
	getline (cin,nome);
	temp<<nome << "\tPEDRAS PARTIDAS " << this->BLocos_Partidos<< "   DIF\t"<<this->dif;
	temp.close();
	remove(SCORE);
	rename("example.txt",SCORE);
}

string Jogo::procura(string comando){
	ostringstream str;
	stringstream pal(comando);
	int contador = 0;
	string str2;


	while(getline (pal,(str2), ' ')){
		if(contador == 0){
			str << str2;
			contador++;
		}
	}
	return str.str();
}

void Jogo::valida_nome_ficheiro(void){
	ifstream File(this->file);

	if(File.is_open() == NULL){
		this->file = "tabela_precos.txt";
	}

	File.close();
}

// ############################### FUNCOES DE JOGO   ################################### 

/*################## METODOS DOS ATRIBUTOS ###############################*/
void Jogo::setCol(int col){
	this->col = col;
}

void Jogo::setLin(int lin){
	this->lin = lin;
}

void Jogo::setDif(int dif){
	this->dif = dif;
}

void Jogo::setNomeJogador(string nome){
	this->nome = nome;
}

int Jogo::getCol(){
	return this->col;
}

int Jogo::getLin(){
	return this->lin;
}

int Jogo::getDif(){
	return this->dif;
}

string Jogo::getNomeJogador(){
	ostringstream str;

	str << this->nome;
	return str.str();
}

string Jogo::outputDefinicoesJogo(){
	ostringstream str;

	str << " Nome " << this->nome << " Colunas " << this->col << " Linhas " << this->lin << " Dificuldade" << this->dif ;
	return str.str();
}

void Jogo::set_condicao_paragem(int &valor){
	this->condicao_paragem = valor;
}

void Jogo::limpa_vector_comandos(void){
	vector<string>::iterator i;
	i = vec2.begin();

	for(i = vec2.end()-1; i > vec2.begin(); i--){
		i=vec2.erase(i);
	}//apago todos as strings do comando
	i = vec2.begin(); 
	i= vec2.erase(i);
}

/*################## METODOS DOS ATRIBUTOS ###############################*/

//############################## comandos do jogo  #######################################

void Jogo::comando_tecla_r(Mineiro &mineiro){
	if(this->tecla =='r'){
		mineiro.utiliza_ramdon();
	}
}

void Jogo::superfice_vida(Mineiro &mineiro){
	if(mineiro.return_cordy() == 0){
		float valor = mineiro.return_energia_utensilio();
		mineiro.actualiza_vida(valor);
	}
}

void Jogo::teclado_setas(Mineiro &mineiro, Mina &mina,int &poscol, int &poslin){
	if (this->tecla == this->ecran.ESCAPE){//termina o jogo
		this->condicao_paragem = 1;
		}
	else if (this->tecla == this->ecran.CIMA){////andar para a cima
			if(poslin>0){
				mineiro.retira_vida_escada();
				if(mineiro.pede_permisao_mina(poscol,poslin-1)== true){
					poslin--;
					tempo++;
					mineiro.set_cordx_cordy(poscol,poslin);
					Beep(90,100);
				}
				else{
					int posy = poslin-1;
					this->escava_jogo(mineiro,poscol,posy);
				}
			}
		}else if (this->tecla == this->ecran.BAIXO){////andar para a baixo
			if(poslin < this->lin-1){
				if(mineiro.pede_permisao_mina(poscol,poslin+1)== true){
					poslin++;
					tempo++;
					mineiro.set_cordx_cordy(poscol,poslin);
					float vida = -1.0;
					mineiro.retira_vida(vida);
					Beep(100,100);
				}
				else{
					int posy = poslin+1;
					this->escava_jogo(mineiro,poscol,posy);
				}
			}
		}else if(this->tecla == this->ecran.ESQUERDA){////andar para a esquerda
			if(poscol > 0){
				if(mineiro.pede_permisao_mina(poscol-1,poslin)== true){
					poscol--;
					tempo++;
					mineiro.set_cordx_cordy(poscol,poslin);	
					float vida = -1.0;
					mineiro.retira_vida(vida);
					Beep(100,100);
				}
				else{
					int posx = poscol-1;
					this->escava_jogo(mineiro,posx,poslin);
				}
			}
		}else if (this->tecla == this->ecran.DIREITA){//andar para a direita
			if(poscol < this->col-1){
				if(mineiro.pede_permisao_mina(poscol+1,poslin)== true){
					poscol++;
					tempo++;
					mineiro.set_cordx_cordy(poscol,poslin);
					float vida = -1.0;
					mineiro.retira_vida(vida);
					Beep(100,100);
				}
				else{
					int posx = poscol+1;
					this->escava_jogo(mineiro,posx,poslin);
				}
			}
		}	
}

//tecla c
void Jogo::comando_tecla_c(int poscol,int poslin,Mineiro &mineiro,Mina &mina){
	if(this->tecla == 'c'){//modo comando 
		while(this->paragem == 0){//condicao de paragem da consola
				this->desenha_prompt();
				getline(cin,this->comando);
				//condicao_de_paragem para voltar ao jogo			
				if(this->comando.size() > 0 ){
					this->executar_comando (poslin, poscol, mina,mineiro);
					if(this->comando != "x"){
						poscol = mineiro.return_cordx();
						poslin = mineiro.return_cordy();
						mina.redesenha_limites_tabuleiro(poscol,poslin,mineiro.return_raio_visao(),this->ecran);
						this->desenha_ecran(tempo,mineiro,poscol,poslin);
    					mina.visao_mineiro(poscol,poslin ,this->ecran,mineiro);
					}
				}
			}
		}
	this->paragem = 0;//para voltar a entrar no modo comando
}

//trecla e
void Jogo::comando_tecla_e(Mineiro &mineiro){
	if(this->tecla == 'e'){
		int numero = 5;
		mineiro.aplica_escada(numero);
	}
}

void Jogo::comando_tecla_v(Mineiro &mineiro){
	if(this->tecla == 'v'){
		int numero = 5;
		mineiro.aplica_viga(numero);
	}
}

void Jogo::comando_tecla_d(Mineiro &mineiro, Mina &mina){
	if(this->tecla == 'd'&& mineiro.return_DInamite() >= 1){
		mineiro.retira_dinamite();
		mina.coloca_bloco_posx_posy(mineiro.return_cordx(),mineiro.return_cordy(),"VA");
		mina.coloca_bloco_posx_posy(mineiro.return_cordx(),mineiro.return_cordy(),"DI");
	}
}

void Jogo::linha_superior(Mina &mina,int &x,int &y){
	

}

void Jogo::comando_tecla_x(Mineiro &mineiro,Mina &mina){
	if (this->tecla =='x'){//se for tecla x
		Beep(750,30);
		for(int i = 0; i < this->col; i++){//numero de colunas
			for (int j = 0; j < this->lin ; j++){//numero de linhas
				if(mina.percorrer_mapa(i,j) == true){
					this->arrebenta_minas(i,j,mina,mineiro);
				}
			}
		}
	}
}

void Jogo::arrebenta_minas(int x , int y,Mina &mina,Mineiro &mineiro){

		int p1 = 3;
		int p2 = 3;
		int cordx =  mineiro.return_cordx();
		int cordy = mineiro.return_cordy();

		for(int i = -2; i < p1;i++){
			for(int j = -2;j < p2;j++){
				mina.coloca_bloco_posx_posy(x+i,y+j,"VA");
				if(cordx == (x+i) && cordy==(y+j)){
					float valor = 0;
					mineiro.actualiza_vida(valor=0.0);
				}
			}
		}
}

void Jogo::comando_tecla_p(void){
	if(this->tecla=='p'){
			this->condicao_paragem = 1;
	}
}

void Jogo::coloca_colunas(Mineiro &mineiro, Mina &mina){
	
}

void Jogo::inserir_tabela_comandos(void){
	this->lista_comandos.insert (pair<string,int>("u",1));
	this->lista_comandos.insert (pair<string,int>("b",2));
	this->lista_comandos.insert (pair<string,int>("t",3));
	this->lista_comandos.insert (pair<string,int>("g",4));
	this->lista_comandos.insert (pair<string,int>("e",5));
	this->lista_comandos.insert (pair<string,int>("c",6));
	this->lista_comandos.insert (pair<string,int>("f",7));
	this->lista_comandos.insert (pair<string,int>("a",8));
	this->lista_comandos.insert (pair<string,int>("x",9));
	this->lista_comandos.insert (pair<string,int>("j",10));
	this->lista_comandos.insert (pair<string,int>("root",11));
	this->lista_comandos.insert (pair<string,int>("precos",12));
}

int Jogo::reconhece_comandos(void){
	stringstream pal(this->comando);
	string str;
	map<string,int>::iterator i;
	
	try{
		while(getline(pal,(str),' ')){
			vec2.push_back(str);	
		}
		i = lista_comandos.find(vec2[0]);
		if(i == lista_comandos.end()) {
			throw 100;
		}
	}catch(int valor){
		this->ecran.gotoxy(45,35);
		this->ecran.deletE(44,33,30,16);
		this->ecran.setTextColor(this->ecran.AMARELO);
		cout << "comando Invalido " << endl;
	/*	this->ecran.getch();*/
		return valor;
	}
	return i->second;
}

void Jogo::executar_comando(int &x, int &y, Mina &mina, Mineiro &mineiro){
	if(this->reconhece_comandos() == 1){//comprar novo utensilio
		this->u_novo_utensilio(vec2[1],mineiro,x,mina);
		system("cls");
	}
	else if (this->reconhece_comandos() == 2){//coloca um bloco na posicao x y
		this->coloca_bloco(mina);
	}
	else if(this->reconhece_comandos()==3){//faz teletransporte do mineiro
		this->teletransportmineiro(mineiro);
	}
	else if(this->reconhece_comandos()== 4){//coloca as moedas no valor indicado
		this->comando_g_valor(mineiro);
	}
	else if (this->reconhece_comandos() == 5){//coloca a vida do mineiro no valor indicado
		this->comando_e_valor(mineiro);
	}
	else if(this->reconhece_comandos()==6){//cria uma nova mina
		this->comando_c_nome(mineiro,mina);
	}
	else if(this->reconhece_comandos()==7){//muda o foco da mina
		this->f_nome(mineiro,mina);
	}
	else if (this->reconhece_comandos()==8){//copia a mina atraves do operador=
		this->comando_a_nome_nome_destino(mineiro,mina);
	}
	else if (this->reconhece_comandos()==9){//sair do modo consola do jogo
		this->comando_x();
		system("cls");
	}
	else if (this->reconhece_comandos()==10){//termina o jogo
		this->comando_j(x,y,mineiro,mina);
		system("cls");
	}
	else if(this->reconhece_comandos()==12){//precos dos  utensilios
		this->ecran.clrscr();
		this->listagem_precos();
		this->ecran.getch();
		system("cls");
	}
	else if(this->reconhece_comandos()==100){
		this->ecran.getch();
		system("cls");
	}
	this->limpa_vector_comandos();
}

//comando u 
void  Jogo::u_novo_utensilio(string nome,Mineiro &mineiro, int lin,Mina &mina){
	map<string,int>::iterator i ;
	ERROR_Exception Error;
	if(vec2.size() == 2) { // quando não é passada quantidade, assume quantidade 1 (um)
		vec2.push_back("1");
	}
	int numero = atoi(vec2[2].c_str());
	try{
		i = tabela_precos.find(vec2[1]);
		if(i == tabela_precos.end()){
			throw 100;
		}
		else{
			if(tabela_precos.find(vec2[1])->first == vec2[1]){
				if(mineiro.devolve_numero_moedas() >=(tabela_precos.find(vec2[1])->second * numero)&& mineiro.a_onde_estou(lin) == true ){
					int total = 0;
					total = numero * tabela_precos.find(vec2[1])->second;
					mineiro.retira_moedas(total);//retiro as moedas
					mineiro.compra_utensilios(vec2[1],vec2[2]);
				}
				else{//se nao tiver na superfice  da mina
					if( mineiro.a_onde_estou(lin) == false){
						throw Error;
					}
					if((tabela_precos.find(vec2[1])->second * numero) > mineiro.devolve_numero_moedas()){
						throw 'a';
					}
				}
			}
		}
	}
	catch(ERROR_Exception E){
		this->ecran.setTextColor(this->ecran.VERMELHO_CLARO);
		this->error_msg("Nao esta na superfice");
		this->ecran.setTextColor(this->ecran.PRETO);
	}
	catch(int i){
		this->ecran.setTextColor(this->ecran.AZUL_CLARO);
		this->error_msg("Nao existe esse utensilio");
		this->ecran.setTextColor(this->ecran.PRETO);
	}
	catch(char a){
		this->ecran.setTextColor(this->ecran.VERDE);
		this->error_msg("Nao tens moedas");
		this->ecran.setTextColor(this->ecran.PRETO);
	}
	this->ecran.getch();

}

//comando b
void Jogo::coloca_bloco(Mina &mina){
	int col, lin, preco = 90;
	col = atoi(vec2[3].c_str());
	lin = atoi(vec2[2].c_str());
	mina.coloca_bloco_posx_posy(col,lin,vec2[1]);
}

// comando t
bool Jogo::verifica_limites_mina(void){
	ERROR_Exception error;
	int col, lin;
	col = atoi(vec2[2].c_str());
	lin = atoi(vec2[1].c_str());
	try{
		if(col < 0 || lin < 0){//verifca os limites caso naos ejam validos de atira um valor
			throw error;
		}
		else if (col >= this->col|| lin >= this->lin){
			throw error;
		}
	}
	catch(ERROR_Exception e){
		this->error_msg("Dados Invalidos");
		return false;
	}
	return true;
}

void Jogo::teletransportmineiro( Mineiro &mineiro){
	int col, lin;
	col = atoi(vec2[2].c_str());
	lin = atoi(vec2[1].c_str());
	if(this->verifica_limites_mina() == true){
		mineiro.set_cordx_cordy(col,lin);
		mineiro.teletransporte(col,lin);
	}
}
// comando t
// comando g valor
void Jogo::comando_g_valor(Mineiro &mineiro){
	this->valor = atoi(vec2[1].c_str());
	mineiro.insert_moedas(valor);
}

// comando e valor
void Jogo::comando_e_valor(Mineiro &mineiro){
	this->valor = atoi(vec2[1].c_str());
	mineiro.actualiza_vida(valor);
}


//metodo acrescentado por mim 
int Jogo::pesquisa_nome(string nome){

	for(int i = 0; i < tam ; i++){
		if(lista2[i]->get_nome() == nome){
			return 1;
		}
	
	}
	return 0;
}


void Jogo::comando_save_dados(Mineiro &ob_mineiro,  Mina &ob_mina){
	Mineiro **temp;
	Mina **temp2;
	//alocar memoria para um vector temporario de minas e mineiros
	temp = new Mineiro *[this->tam+1];
	temp2 = new Mina *[this->tam+1];
	for(int i = 0; i < tam ; i++){
		//cout << lista2[i]->get_nome() << endl;
		temp2[i] = lista2[i];
		temp[i] = lista [i]; 
	}
	temp[tam] = &ob_mineiro;
	temp2[tam] = &ob_mina;
	n++;
	tam =n;
	lista = temp;
	lista2 = temp2;
}

//comando c novo-nome
void Jogo::comando_c_nome(Mineiro &ob_mineiro,  Mina &ob_mina){
	try{
		if(this->pesquisa_nome(vec2[1]) == 1){
			throw 1;
		}
		else{
			throw 0;
		}
	}
	catch(int valor){
		if(valor == 0){
			Mina *mina;
			mina = new Mina (ob_mina);
			str = vec2[1];
			mina->setnome(vec2[1]);
			Mineiro *mineiro;
			mineiro = new Mineiro (ob_mineiro);
			this->ecran.getch();
			this->comando_save_dados(*mineiro,*mina);
		}
		else{
			this->ecran.gotoxy(45,35);
			this->ecran.deletE(44,33,30,16);
			this->ecran.setTextColor(this->ecran.AMARELO);
			cout << "Ja existe esse nome " << endl;
			this->ecran.getch();
		}
	}
}

//comando f muda foca_mina
void Jogo::f_nome(Mineiro &ob_mineiro,  Mina &ob_mina){
	int pos = -1;
	for(int i = 0; i < tam; i++){
		if(lista2[i]->get_nome() == vec2[1]){
			pos = i;
		}
	}
	vec2[1].erase();
	if(pos >= 0){//procurar a mina em questao
		ob_mineiro = *lista[pos];
		ob_mina = *lista2[pos];
		ob_mineiro.set_mina(ob_mina);//mineiro -> &mina
		ob_mina.setmineiro(ob_mineiro);//mina -> &mineiro
	}
	this->ecran.clrscr();
}

//comando a nome-origem nome-dest
void Jogo::comando_a_nome_nome_destino(Mineiro &ob_mineiro,  Mina &ob_mina){
	Mina *mina;
	Mineiro *mineiro;
	mina =new Mina();
	mineiro = new Mineiro();
	if(vec2[1].size() > 0  && vec2[2].size() > 0){
		for(int i = 0; i < tam ; i++){
			if(lista2[i]->get_nome() == vec2[1]){
				if(lista2[i]->get_nome() != vec2[2]){
					mina = lista2[i];
					mineiro = lista[i];
					mina->setnome(vec2[2]);
					this->ecran.gotoxy(43,16);
					this->comando_save_dados(*mineiro,*mina);
					break;
				}
			}
		}
	}
}

//comando j
void Jogo::comando_j(int poscol,int poslin,Mineiro &mineiro,Mina &mina){
	this->paragem = 1;
}

//comando x
void Jogo::comando_x(void){
	this->paragem = 1;
	this->condicao_paragem = 1;
}

// mostra tabela de precos 
void Jogo::listagem_precos(void){
	map<string,int>::iterator i ;

	for(i = tabela_precos.begin(); i != tabela_precos.end();i++){
		cout << i->first << " " << i->second << endl;
	}
}

//desabamento
void Jogo::desabamento(Mineiro &mineiro, Mina &mina){
	


}

//vida extra
int Jogo::vida_extra(Mineiro &mineiro,Mina &mina){
	this->ecran.setTextColor(this->ecran.AMARELO);
		if(mineiro.return_vida_Extra() >= 1){
			mineiro.utliza_vida_extra();
			return 1;//usou uma vida extra
		}
	return 0;//nao tem vida extra
}

void Jogo::escava_jogo(Mineiro &mineiro,int &x, int &y){
	mineiro. mineiro_da_uma_martelada_no_bloco(x,y);
}

void Jogo::converte_valores_em_moedas(Mineiro &mineiro){
	if(mineiro.return_cordy() == 0){
		mineiro.soma_moedas();
	}
}

void Jogo::check_life_mineiro(Mineiro &mineiro, Mina &mina){
	if(mineiro.devolve_energia_mineiro() <= 0.0){//
		this->ecran.clrscr();
		if(this->vida_extra(mineiro,mina) == 0){//se nao tiver vida extra termina o jogo
			this->condicao_paragem = 1;
			cout << "FIM DO JOGO MINEIRO MORREU  LIFE " << mineiro.devolve_energia_mineiro() <<  endl;
			this->ecran.getch();
		}
		else{
			int x = 0; int y = 0;
			mineiro.set_cordx_cordy(x,y);
		}
	}
}

/*################## FUNCOES DO JOGO ###############################*/

// ############################### desenha output ecran ###################################
void Jogo::desenha_ecran(int &time , Mineiro &b, int poscol, int poslin){
		//Medidas fixas nao mexer
		//c.setTextColor(c.BRANCO);
		this->ecran.setTextColor(this->ecran.CINZENTO);
		this->ecran.desenha_rectangulo(2,1,37,37);//Medidas fixas nao mexer
		this->ecran.desenha_rectangulo(42,1,36,5);//Medidas fixas nao mexer
		//c.setBackgroundColor(c.AZUL_CLARO);
		this->ecran.desenha_rectangulo(42,9,36,24);//Medidas fixas nao mexer
		this->ecran.gotoxy(45,2);//Medidas fixas nao mexer
		this->ecran.setTextColor(this->ecran.AZUL_CLARO);
		cout << "TIME "<< this->tempo;
		this->ecran.gotoxy(54,2);//Medidas fixas nao mexer
		this->ecran.setTextColor(this->ecran.VERMELHO_CLARO);
		printf("LIFE %.2f ",b.devolve_energia_mineiro());
		//cout << "LIFE " << b.devolve_energia_mineiro();
		this->ecran.gotoxy(65,2);//Medidas fixas nao mexer
		this->ecran.setTextColor(this->ecran.VERDE_CLARO);
		cout << " COINS " << b.devolve_numero_moedas();
		this->desenha_informacao_relativa( poscol,poslin, b);
		this->ecran.setTextColor(this->ecran.PRETO);
}

void Jogo::desenha_prompt(void){
		int posx = 43 ;
		int posy = 31;
		this->ecran.setTextColor(this->ecran.BRANCO);
		this->ecran.desenha_rectangulo(42,34,36,4);
		this->ecran.gotoxy(45,35);
		this->ecran.deletE(44,35,30,16);
		this->ecran.putch('>');
		this->ecran.putch(' ');
	    this->ecran.getch();
}

void Jogo::error_msg(string msg){
	this->ecran.gotoxy(45,35);
	cout << msg;
	this->ecran.getch();
}

void Jogo::desenha_informacao_relativa(int poscol, int poslin, Mineiro &b){
	this->ecran.setTextColor(this->ecran.CINZENTO);
	this->ecran.deletE(44,8,30,16);
	this->ecran.gotoxy(44,7);
	cout << "Cordenadas(linha,Coluna) " << poslin << ' ' << poscol;
	this->ecran.gotoxy(45,11);
	this->ecran.deletE(44,13,30,16);
	cout << b.tipo_picareta();
	this->ecran.gotoxy(45,13);
	this->ecran.deletE(44,13,30,16);
	this->ecran.setTextColor(this->ecran.AMARELO_CLARO);
	cout << b.tipo_luz();
	this->ecran.gotoxy(45,15);
	this->ecran.deletE(44,15,30,16);
	this->ecran.setTextColor(this->ecran.VERMELHO);
	cout << b.tipo_energia();
	this->ecran.gotoxy(45,17);
	this->ecran.deletE(44,19,32,16);
	this->ecran.setTextColor(this->ecran.AZUL_CLARO);
	cout << b.tipo_mochila(); 
	this->ecran.gotoxy(45,19);
	this->ecran.deletE(44,19,32,16);
	this->ecran.setTextColor(this->ecran.CYAN_CLARO);
	cout << "Peso "<<b.retorna_peso() << "  Capacidade "<<b.retorna_capacidade()<<" Valor "<<b.return_valor();
	this->ecran.gotoxy(45,21);
	this->ecran.deletE(44,21,30,16);
	this->ecran.setTextColor(this->ecran.AMARELO_CLARO);
	cout << b.recargas();
	this->ecran.gotoxy(45,23);
	this->ecran.deletE(44,23,30,16);
	this->ecran.setTextColor(this->ecran.COR_DE_ROSA);
	cout << b.Vida_extra();
	this->ecran.gotoxy(45,25);
	this->ecran.deletE(44,25,30,16);
	cout << b.Dinamite();
	this->ecran.gotoxy(45,27);
	this->ecran.deletE(44,27,30,16);
	cout << b.Paraquedas();
	this->ecran.gotoxy(45,29);
	this->ecran.deletE(44,28,30,16);
	cout <<"Random "<< b.get_ramdon();
	this->ecran.gotoxy(45,31);
	this->ecran.deletE(44,31,30,16);
	this->ecran.setTextColor(this->ecran.CYAN);
	cout << "BLocos Partidos " <<this->BLocos_Partidos; 
}

// ############################### desenha output ecran ###################################

// ###############################		Operator		###################################
Jogo &Jogo::operator++(int n){
	this->condicao_paragem++;
	return *this;
}
// ###############################		Operator		###################################