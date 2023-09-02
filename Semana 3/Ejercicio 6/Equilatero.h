#pragma once
#include"MisLibrerias.h"

class Equilatero
{
public:
	Equilatero(int _lado,char car);
	~Equilatero();
	void dibujar();
private:
	int x, y;
	int dx, dy;
	int lado;
	int cont;
	char caracter;
};

Equilatero::Equilatero(int _lado, char car)
{
	lado = _lado;
	caracter = car;
	x = 50;
	y = 15;
	dx = 1;
	dy = -1;
	cont = 0;
}

Equilatero::~Equilatero(){}

void Equilatero::dibujar()
{
	while (true)
	{
		Console::SetCursorPosition(x, y);
		cout << caracter;
		if (cont >= lado)
			dy = 1;
		if (cont >= lado * 2)
		{
			dx = -2;
			dy = 0;
		}
		if (cont >= lado * 3)break;

		_sleep(100);
		cont++;

		x += dx;
		y += dy;
	}
}
