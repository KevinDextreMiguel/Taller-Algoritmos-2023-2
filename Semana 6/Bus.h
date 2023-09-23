#pragma once
#include"Terrestre.h"
class Bus:public Terrestre
{
public:
	Bus();
	~Bus();
	void dibujar();
};
Bus::Bus():Terrestre(22,4,3){}
Bus::~Bus(){}
void Bus::dibujar()
{
	Console::ForegroundColor = (ConsoleColor)color;
	Console::SetCursorPosition(x, y);
	cout << "  ________________";
	Console::SetCursorPosition(x, y + 1);
	cout << "  _/_|[][][][][][][]|";
	Console::SetCursorPosition(x, y + 2);
	cout << "(                   |";
	Console::SetCursorPosition(x, y + 3);
	cout << "= --OO---------OO-=";
}