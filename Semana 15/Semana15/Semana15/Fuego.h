#pragma once
#include"Base.h"

class Fuego :public Base
{
public:
	Fuego() :Base(40, 40)
	{
		x = rand()%400+400;
		y = rand() % 200 + 200;
		dx = dy = 5;
	}
	~Fuego() {}

	void dibujar(Graphics^ g)
	{
		g->FillEllipse(Brushes::OrangeRed, GetRectangle());
	}
	void mover(Graphics^ g)
	{
		if (x<0 || x + ancho>g->VisibleClipBounds.Width)
			dx *= -1;
		x += dx;
	}
};
