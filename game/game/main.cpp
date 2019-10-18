# define _CRT_SECURE_NO_WARNINGS 
# define _CRT_SECURE_NO_DEPRECATE 1
# include <iostream>
# include <sstream>
# include <string>
# include "Jogo.h"
using namespace std;

int Jogo::n = 0;

int main (void){
	Jogo jogo;
	Consola c;
	jogo.game();//objecto jogo isto é como fosse um dvd com um jogo la dentro
	cout << "ADEUS | GOODBYE | Press any key to continue "<< endl ;
	c.getch();//simula um system("pause");
	return 0;

}