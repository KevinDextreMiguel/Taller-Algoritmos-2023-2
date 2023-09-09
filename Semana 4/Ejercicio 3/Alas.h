#pragma once
#include"MisLibrerias.h"
class Alas
{
public:
	Alas(int col);
	~Alas();
	void dibujar(int x,int y);
	void borrar(int x, int y);
private:
	int color;
};

Alas::Alas(int col)
{
	color = col;
}

Alas::~Alas()
{
}
void Alas::dibujar(int x, int y)
{
	Console::ForegroundColor = (ConsoleColor)color;
	Console::SetCursorPosition(x, y); cout << "---oOo---";
}
void Alas::borrar(int x, int y)
{
	Console::SetCursorPosition(x, y); cout << "         ";
}