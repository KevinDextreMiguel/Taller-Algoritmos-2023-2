#pragma once
#include"Personaje.h"
class Heroe :public Personaje
{
public:
	Heroe(int w,int h);
	~Heroe();
	void dibujar(Graphics^ g, Bitmap^ b);
	void mover(Graphics^ g, Keys tecla);

	char getDireccion();
private:
	char direccion;
};

Heroe::Heroe(int w, int h):Personaje(w,h)
{
	x = y = 400;
	direccion = 'S';
}

Heroe::~Heroe(){}
void Heroe::dibujar(Graphics^ g, Bitmap^ b)
{
	Rectangle section = Rectangle(indx * ancho, indy * alto, ancho, alto);
	//Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(b,getRectangulo(), section, GraphicsUnit::Pixel);
}
void Heroe::mover(Graphics^ g, Keys tecla)
{
	switch (tecla)
	{
	case Keys::Right:
		indy = 2;
		if (x + ancho < g->VisibleClipBounds.Width)x += dx;
		direccion = 'D';
		break;
	case Keys::Left:
		indy = 1;
		if (0<x)x -= dx;
		direccion = 'A';
		break;
	case Keys::Up:
		indy = 3;
		if (y>0)y -= dy;
		direccion = 'W';
		break;
	case Keys::Down:
		indy = 0;
		if (y + alto < g->VisibleClipBounds.Height)y += dy;
		direccion = 'S';
	}

	indx++;
	if (indx == 3)indx = 0;
}

char Heroe::getDireccion() { return direccion; }