#pragma once
#include"Personaje.h"
class Enemigo :public Personaje
{
public:
	Enemigo(int w, int h);
	~Enemigo();
	void dibujar(Graphics^ g, Bitmap^ b);
	void mover(Graphics^ g);
};

Enemigo::Enemigo(int w, int h) :Personaje(w, h)
{
	dx = dy = 2;
	x = rand()%1000;
	y = 0;
}

Enemigo::~Enemigo() {}
void Enemigo::dibujar(Graphics^ g, Bitmap^ b)
{
	Rectangle section = Rectangle(indx * ancho, indy * alto, ancho, alto);
	//Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(b, getRectangulo(), section, GraphicsUnit::Pixel);
}
void Enemigo::mover(Graphics^ g)
{
	y += dy;
	indx++;
	if (indx == 3)indx = 0;
}
