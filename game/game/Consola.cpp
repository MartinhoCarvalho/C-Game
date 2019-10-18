/* Funcoes da consola. Dez 2010 */

/* Pequenas correcoes. Nov. 2013 */

#include "Consola.h"                      
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

Consola::Consola() {
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdin = GetStdHandle (STD_INPUT_HANDLE);
	hwnd = GetConsoleWindow(); // NT upwards. Nem queiram saber como seria para 95 e 98
}

//Consola::~Consola(){
//
//}
void Consola::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hconsola,coord);
}

//esconde cursor
void Consola::HideCursor(){
	// get standard console handle
	HANDLE myHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);

	// get current cursor information
	CONSOLE_CURSOR_INFO myCursorInfo;

	::GetConsoleCursorInfo(myHandle, &myCursorInfo);

	// hide cursor
	myCursorInfo.bVisible = false;

	::SetConsoleCursorInfo(myHandle, &myCursorInfo);
}

   
void Consola::clrscr() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD startCoords = {0,0};   
	DWORD dummy;
  
	GetConsoleScreenBufferInfo(hconsola,&csbi);
	FillConsoleOutputCharacter(hconsola,
                               ' ',
                               csbi.dwSize.X * csbi.dwSize.Y,
                               startCoords,
                               &dummy);    
	FillConsoleOutputAttribute(hconsola,
							   csbi.wAttributes,
                               csbi.dwSize.X * csbi.dwSize.Y,
                               startCoords,
							   & dummy);
	gotoxy(0,0);
}


void Consola::deletE(int poscol, int poslin, int largura, int altura) {

	// get standard console handle
	HANDLE myHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);

	// set coordinate to upperleft corner
	COORD myCoord;

	myCoord.X = poscol;
	myCoord.Y = poslin;

	// get console buffer size
	CONSOLE_SCREEN_BUFFER_INFO myInfo;

	GetConsoleScreenBufferInfo(myHandle, &myInfo);

	// write null characters to screen
	DWORD myNumberOfChars;

	for (int j = 0; j < altura; j++) {
		::FillConsoleOutputCharacter(myHandle, 0, largura, myCoord, &myNumberOfChars);
	}

	//// write standard color to screen
	//::FillConsoleOutputAttribute(myHandle, 0x07, mySize, myCoord, &myNumberOfChars);

	//// position cursor at upperleft corner
	//::SetConsoleCursorPosition(myHandle, myCoord);

}


void Consola::setTextColor(WORD color) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hconsola,&csbi);
	WORD cor = csbi.wAttributes;
	cor &= 0xFFF0;
	cor |= color;
	// duvidas acerca destas duas linhas -> TI ou TAC
	SetConsoleTextAttribute(hconsola,cor);
	return;
}

void Consola::setBackgroundColor(WORD color) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hconsola,&csbi);
	WORD cor = csbi.wAttributes;
	cor &= 0xFF0F;
	cor |= (color << 4);
	// duvidas acerca destas duas linhas -> TI ou TAC
	SetConsoleTextAttribute(hconsola,cor);
}

void Consola::setScreenSize(int nLinhas, int nCols) {
	COORD tam;
	SMALL_RECT DisplayArea;

	tam.X = nCols;
	tam.Y = nLinhas;
	SetConsoleScreenBufferSize(hconsola, tam);   // isto muda o tamanho da matriz de caracteres

	DisplayArea.Top = 0;
	DisplayArea.Left = 0;
	DisplayArea.Bottom = nLinhas-1;
	DisplayArea.Right = nCols-1;
    SetConsoleWindowInfo(hconsola, TRUE, &DisplayArea);  // isto muda o tamanho da area da janela em caracteres
}

// usar esta de preferência a não ser que se esteja no XP ou anterior
void Consola::setTextSize(int x, int y) {
	CONSOLE_FONT_INFOEX cfont;

	cfont.cbSize=sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(hconsola, false, & cfont);
	cfont.dwFontSize.X = x;
	cfont.dwFontSize.Y = y;
	SetCurrentConsoleFontEx(hconsola, false, &cfont);
}


char Consola::getch(void) {
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	CHAR cChar;

	while(ReadConsoleInputA(hStdin, &irInputRecord, 1, &dwEventsRead)) /* Read key press */
		if (irInputRecord.EventType == KEY_EVENT
			&& irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_SHIFT
			&& irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_MENU
			&& irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_CONTROL)
		{

		cChar = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
		ReadConsoleInputA (hStdin, &irInputRecord , 1, &dwEventsRead); /* Read key release */

		if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT) return ESQUERDA;
		if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) return DIREITA;
		if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP) return CIMA;
		if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN) return BAIXO;

		return cChar;
    }
  return EOF;
}



void Consola::putch(char c) {//putch programado por mim  e nao pelo prof 
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	CHAR cChar;

	WriteConsole(hconsola, &c, 1, &dwEventsRead, NULL);
}


void Consola::putch(char *c) {
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	CHAR cChar;

	WriteConsole(hconsola, &c, 1, &dwEventsRead, NULL);
}



//void  Consola::WriteText( string text, unsigned short x, unsigned short y,unsigned short foreColor, unsigned short backColor){
//	// get standard console handle
//	HANDLE myHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// set coordinate to start writing
//	COORD myCoord;
//
//	myCoord.X = x;
//	myCoord.Y = y;
//
//	// create color buffer
//	LPWORD myColorBuffer;
//	myColorBuffer = new WORD[text.length()];
//
//	memset(myColorBuffer, (backColor << 4) + foreColor,
//		sizeof(WORD) * text.length());
//
//	// write text to screen
//	DWORD myNumberOfCharsWritten;
//
//	/*::WriteConsoleOutputCharacter(myHandle, text.c_str (), text.length(),
//		myCoord, &myNumberOfCharsWritten);*/
//
//	// set color
//	::WriteConsoleOutputAttribute(myHandle, myColorBuffer, text.length(),
//		myCoord, &myNumberOfCharsWritten);
//}


// setTextSize - Usar isto apenas se a outra não funcionar (XP ou menos)
// O método de funcionamento é bastante força-bruta
//   Procura uma fonte que cumpra os requisitos do novo tamanho
//   e muda para essa fonte (ou seja, muda tambéma fonte)
// Funções que a MS nem se deu ao trabalho de documentar
// Help: http://blogs.microsoft.co.il/blogs/pavely/archive/2009/07/23/changing-console-fonts.aspx
typedef BOOL (WINAPI * SetConsoleFont_)(HANDLE ConsoleOutput, DWORD FontIndex); // kernel32!SetConsoleFont
typedef BOOL (WINAPI * GetConsoleFontInfo_)(HANDLE ConsoleOutput, BOOL Unknown1, DWORD Unknown2, PCONSOLE_FONT_INFO ConsoleFontInfo); // kernel32!GetConsoleFontInfo
typedef DWORD (WINAPI * GetNumberOfConsoleFonts_)(); // kernel32!GetNumberOfConsoleFonts


void Consola::setTextSizeXP(int x, int y){
	// Configura acesso às funções "secretas" do Windows
    SetConsoleFont_ SetConsoleFont = reinterpret_cast<SetConsoleFont_>(GetProcAddress(GetModuleHandle(L"kernel32.dll"), "SetConsoleFont"));
    GetConsoleFontInfo_ GetConsoleFontInfo = reinterpret_cast<GetConsoleFontInfo_>(GetProcAddress(GetModuleHandle(L"kernel32.dll"), "GetConsoleFontInfo"));
    GetNumberOfConsoleFonts_ GetNumberOfConsoleFonts = reinterpret_cast<GetNumberOfConsoleFonts_>(GetProcAddress(GetModuleHandle(L"kernel32.dll"), "GetNumberOfConsoleFonts"));
      
    // Num de fontes
	DWORD NumFonts = GetNumberOfConsoleFonts();

    // alloca matriz de cont infos
	CONSOLE_FONT_INFO* ConsoleInfo = new CONSOLE_FONT_INFO[sizeof(CONSOLE_FONT_INFO) * NumFonts];

    // obtem info das fontes todas
	GetConsoleFontInfo(hconsola, FALSE, NumFonts, ConsoleInfo);

    // percorre-as todas. O melhor é não chamar isto muitas vezes
    for (size_t i = 0; i < NumFonts; ++i) {
		// Indaga o tamanho (suportado) da fonte. Pode não haver nenhuma para esse tamanho
		ConsoleInfo[i].dwFontSize = GetConsoleFontSize(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleInfo[i].nFont);

		// Encontrou uma. muda para essa e já está (mesmo que haja outras)
		if (ConsoleInfo[i].dwFontSize.X == x && ConsoleInfo[i].dwFontSize.Y == y) {
			// x,y = tamanho desejado (se houver)
			// muda para essa fonte e sai
			SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleInfo[i].nFont);
			break;
		}
	}

	// devolve a matriz de INFO
	delete [] ConsoleInfo;
}


// estas funcoes servem para pouco a nao ser que nao se tape/destape a janela
// o refresh da janela da consola não reactualiza isto
// por esse motivo nao achei que valesse apena optimizar certos aspectos delas
void Consola::drawLine(int x1,int y1,int x2,int y2,int cor){
	HDC DrawHDC;
	HPEN hOPen;  // penstyle, width, color
	HPEN hNPen = CreatePen(PS_SOLID, 2, cor);
	DrawHDC = GetDC(hwnd);
	hOPen = (HPEN)SelectObject(DrawHDC, hNPen);  // inicio da linha
	MoveToEx(DrawHDC, x1, y1, NULL);  // fim da linha
	LineTo(DrawHDC, x2, y2);
	DeleteObject(SelectObject(DrawHDC, hOPen));
	ReleaseDC(hwnd, DrawHDC);
}

// converte circle(centerX,centerY,radius,pen) para a WinApi
void Consola::drawCircle(int X,int Y,int R,int Pen,int Fill){
	HDC DrawHDC;
	DrawHDC = GetDC(hwnd);  // penstyle, width, color
	HPEN   hNPen = CreatePen(PS_SOLID, 2, Pen);
	HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
	HBRUSH hOldBrush;
	HBRUSH hNewBrush;  // true  preenche o circulo com a cor
	if (Fill) {
		hNewBrush = CreateSolidBrush(Pen);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
	} else {
		hNewBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
	}
	Ellipse(DrawHDC, X-R, Y+R, X+R, Y-R);
	DeleteObject(SelectObject(DrawHDC, hOPen));
	DeleteObject(SelectObject(DrawHDC, hOldBrush));
	ReleaseDC(hwnd, DrawHDC);  // torna-se lento
}


void Consola::linha_horizontal_cima(int x, int y , int tamanho){
	gotoxy(x,y);
	//putch( 201);
	cout << (char) 201;
	for(int i = 0;i < tamanho -2; i++){
		cout << (char) 205;		
	}
	cout << (char) 187;
}

void Consola::linha_horizontal_meio(int x, int y , int tamanho){
	gotoxy(x,y);
	cout <<  (char) 186;
	x +=tamanho - 1;
	gotoxy(x,y);
	cout << (char) 186;
}

void Consola::linha_horizontal_baixo(int x, int y , int tamanho){
	gotoxy(x,y);
	cout << (char) 200;
	for(int i = 0;i < tamanho -2; i++){
		cout << (char) 205;		
	}
	cout << (char) 188;
}

void Consola::linha_horizontal_bloco_cima(int x, int y , int tamanho){
	gotoxy(x,y);
	 cout << (char) 218;
	for(int i = 0;i < tamanho -2; i++){
		cout <<  (char) 196;		
	}
	cout << (char) 191;
}

void Consola:: Linha_interior_bloco(int x , int y , int tamanho, char c){
	int p  = x , v = y;
	for(int i= 1; i < tamanho -2; i++){
		for(int j = 1;  j < tamanho - 2; j++){
			gotoxy(p,v);
			cout << c;
			p++;
		}
		v++;
	}

}

void Consola::linha_horizontal_bloco_meio(int x, int y , int tamanho){
	gotoxy(x,y);
	cout << (char) 179;
	x +=tamanho - 1;//andar colunas

	
	gotoxy(x,y);
	cout << (char) 179;
}

void Consola::linha_horizontal_bloco_baixo(int x, int y , int tamanho){
	gotoxy(x,y);
	cout <<  (char) 192 ;
	for(int i = 0;i < tamanho -2; i++){
		cout << (char) 196;		
	}
	cout << (char) 217;
}

void Consola::desenha_rectangulo(int x,int y,int largura, int altura){
	
	linha_horizontal_cima(x,y,largura);
	for(int i = 1 ; i < altura - 1; i++){
		linha_horizontal_meio(x,y+i,largura);
	}

	linha_horizontal_baixo(x,y+altura-1,largura);
}

void Consola::desenha_rectangulo_bloco(int x,int y,int largura, int altura){
	
	linha_horizontal_bloco_cima(x,y,largura);
	for(int i = 1 ; i < altura - 1; i++){
		linha_horizontal_bloco_meio(x,y+i,largura);
	}
	linha_horizontal_bloco_baixo(x,y+altura-1,largura);
}








//##################### teste ###########################################################

void Consola::WriteText(char text, unsigned short foreColor, unsigned short backColor){



// HANDLE hOutput; 
//    LPTSTR lpszString = text ; 
//    DWORD cWritten; 
//    BOOL fSuccess; 
//    COORD coord; 
//    WORD wColors[3], wColor; 
//    CHAR chFillChar; 
// 
//// Write a string of characters to a screen buffer. 
// 
//    coord.X = 0;            // start at first cell 
//    coord.Y = 0;            //   of first row      
//    fSuccess = WriteConsoleOutputCharacter( 
//        hOutput,              // screen buffer handle 
//        "",           // pointer to source string 
//        lstrlen(lpszString),  // length of string 
//        coord,                // first cell to write to 
//        &cWritten);           // actual number written 
 

	//// get standard console handle
	//HANDLE myHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);

	//// set coordinate to start writing
	//COORD myCoord;

	//myCoord.X = 0;
	//myCoord.Y = 0;

	//// create color buffer
	//LPWORD myColorBuffer;
	//myColorBuffer = new WORD[text.length()];

	//memset(myColorBuffer, (backColor << 4) + foreColor,
	//	sizeof(WORD) * text.length());

	//// write text to screen
	//DWORD myNumberOfCharsWritten;

	//::WriteConsoleOutputCharacter(myHandle, text.c_str(), myCoord,text.length(),
	//	myCoord, &myNumberOfCharsWritten);

	//// set color
	//::WriteConsoleOutputAttribute(myHandle, myColorBuffer, text.length(),
	//	myCoord, &myNumberOfCharsWritten);
}



//##################### teste ###########################################################