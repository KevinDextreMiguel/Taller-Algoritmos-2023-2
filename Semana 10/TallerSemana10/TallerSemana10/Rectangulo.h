#pragma once
#include"Figura.h"

class Rectangulo :public Figura
{
public:
	Rectangulo();
	~Rectangulo();
	void dibujar(Graphics^ g);
};

Rectangulo::Rectangulo() :Figura(60, 30, "Rectangulo")
{
	y = 200;
}

Rectangulo::~Rectangulo() {}
void Rectangulo::dibujar(Graphics^ g)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Red);
	g->FillRectangle(b, x, y, ancho, alto);
}
