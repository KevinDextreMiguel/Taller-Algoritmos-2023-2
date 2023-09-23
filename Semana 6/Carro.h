#pragma once
#include"Terrestre.h"
class Carro:public Terrestre
{
public:
	Carro();
	~Carro();
	void dibujar();
};
Carro::Carro():Terrestre(9,3,2){}
Carro::~Carro(){}
void Carro::dibujar()
{
	Console::ForegroundColor = (ConsoleColor)color;
	Console::SetCursorPosition(x, y);
	cout << "___|~\\_";
	Console::SetCursorPosition(x, y + 1);
	cout << "[___|_|-";
	Console::SetCursorPosition(x, y + 2);
	cout << "(_) (_)";
}
