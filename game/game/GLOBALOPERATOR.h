# include "Jogo.h"
# include <iostream>
# include <sstream>
# include <string>
# include "Consola.h"
# include <fstream>
# include <dos.h>
# include <vector>
# include "Bloco.h"
# include "Mineiro.h"
using namespace std;


//operadores GLobais  Objecto Jogo
//ostream &operator<<(ostream &str,Jogo &b);

//operadores GLobais Objecto Jogo



//Operadores GLobais Objecto Mina
ostream &operator<<(ostream &str,Mina &b);
//Operadores GLobais Objecto Mina


Mineiro &operator-=(Mineiro &b,float  &valor);