#pragma once
#include"Base.h"

class Animal:public Base
{
public:
	Animal(int _ancho,int _alto, int _anchoF, int _altoF,int _dx,int _dy):
		Base(_ancho, _alto)
	{
		x = rand() % (_anchoF - ancho);
		y = rand() % (_altoF - alto);

		dx = _dx;
		dy = _dy;
	}

	~Animal(){}
	void dibujar(Graphics^ g, Bitmap^ bmp)
	{
		Rectangle porcion(ancho * indx, alto * indy, ancho, alto);
		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
	
	
	}

	void mover(Graphics^ g)
	{
		if (x<0 || x + ancho>g->VisibleClipBounds.Width)dx *= -1;
		if (y<0 || y + alto>g->VisibleClipBounds.Height)dy *= -1;
			
		x += dx;
		y += dy;

		if (dx > 0)indy = 2;
		if (dx < 0)indy = 1;

		if (dy > 0)indy = 0;
		if (dy < 0)indy = 3;

		indx++;
		if (indx == 2)indx = 0;
	}
};
