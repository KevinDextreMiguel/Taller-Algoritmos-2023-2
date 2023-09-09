#pragma once
#include"MisLibrerias.h"
class Fuselaje
{
public:
	Fuselaje(int col);
	~Fuselaje();
	void dibujar(int x, int y);
	void borrar(int x, int y);
private:
	int color;
};

Fuselaje::Fuselaje(int col)
{
	color = col;
}

Fuselaje::~Fuselaje()
{
}
void Fuselaje::dibujar(int x, int y)
{
	Console::ForegroundColor = (ConsoleColor)color;
	Console::SetCursorPosition(x, y); cout << "__|__";
}
void Fuselaje::borrar(int x, int y)
{
	Console::SetCursorPosition(x, y); cout << "     ";
}
