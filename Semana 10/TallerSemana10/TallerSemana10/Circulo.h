#pragma once
#include"Figura.h"

class Circulo:public Figura
{
public:
	Circulo();
	~Circulo();
	void dibujar(Graphics^ g);
};

Circulo::Circulo():Figura(60,60,"Circulo")
{
	y = 10;
}

Circulo::~Circulo(){}
void Circulo::dibujar(Graphics^ g)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Blue);
	g->FillEllipse(b, x, y, ancho, alto);
}