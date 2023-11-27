#pragma once
#include"Base.h"

class Agua:public Base
{
private:
	char direccion;
public:
	Agua(char dir,int _x,int _y):Base(20,20)
	{
		direccion = dir;
		x = _x;
		y = _y;
		dx = dy = 20;

	}
	~Agua(){}

	void dibujar(Graphics ^g)
	{
		g->FillEllipse(Brushes::AliceBlue, GetRectangle());
	}
	void mover(Graphics^ g)
	{
		switch (direccion)
		{
		case 'D':x += dx; break;
		case 'A':x -= dx; break;
		case 'W':y -= dy; break;
		case 'S':y += dy;
		}
	}
};
