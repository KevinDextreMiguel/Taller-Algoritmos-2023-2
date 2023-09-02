#pragma once
#include"MisLibrerias.h"

class Rectangulo
{
public:
	Rectangulo(int _l1,int _l2, char _caracter);
	~Rectangulo();
	void dibujar();
private:
	int cont;
	int x, y;
	int dx, dy;
	int l1, l2;
	float hipotenusa;
	char caracter;
};

Rectangulo::Rectangulo(int _l1, int _l2,char _caracter)
{
	l1 = _l1;
	l2 = _l2;
	caracter = _caracter;
	cont = 0;
	x = 50;
	y = 15;
	dx = 2; 
	dy = 1;
	hipotenusa = sqrt((l1 * l1) + (l2 * l2));
}

Rectangulo::~Rectangulo(){}

void Rectangulo::dibujar()
{
	while (true)
	{
		Console::SetCursorPosition(x, y);
		cout << caracter;
		if (cont >= hipotenusa + l2 + l1)break;
		else if (cont >= hipotenusa + l2)
		{
			dx = 0;
			dy = -2;
		}
		else if (cont >= hipotenusa)
		{
			dx = -3;
			dy = 0;
		}
		_sleep(100);
		cont++;

		x += dx;
		y += dy;
	}
}
