#pragma once
#include"Figura.h"

class Rombo :public Figura
{
public:
	Rombo();
	~Rombo();
	void dibujar(Graphics^ g);
};

Rombo::Rombo() :Figura(30, 30,"Rombo")
{
	y = 350;
}

Rombo::~Rombo() {}
void Rombo::dibujar(Graphics^ g)
{
	Pen^ p = gcnew Pen(Color::Yellow, 5);
	g->DrawLine(p, x+ancho, y + alto, x, y);
	g->DrawLine(p, x+ancho, y + alto, x, y+(alto*2));
	g->DrawLine(p, x-ancho, y + alto, x, y);
	g->DrawLine(p, x-ancho, y + alto, x, y + (alto*2));
}
