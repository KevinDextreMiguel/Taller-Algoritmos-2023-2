#pragma once
#include<iostream>

using namespace System::Drawing;

class Circulo
{
public:
	Circulo();
	~Circulo();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);

	void setVisible(bool v);
	bool getVisible();
	Rectangle getRectagle();
private:
	int x, y;
	int radio;
	int dx;
	bool visible;
};

Circulo::Circulo()
{
	x = rand() % 500;
	y = rand() % 300 + 100;
	radio = rand() % 10 + 20;
	dx = rand() % 5 + 10;
	visible = true;
}
Circulo::~Circulo(){}
void Circulo::dibujar(Graphics^ g)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Blue);
	g->FillEllipse(b, x, y, radio * 2, radio * 2);

	//Pen^ p = gcnew Pen(Color::Blue, 5);
	//g->DrawEllipse(p, x, y, radio * 2, radio * 2);
}
void Circulo::mover(Graphics^ g)
{
	if (x + dx<0 || x + dx + radio * 2>g->VisibleClipBounds.Width)dx *= -1;

	x += dx;
}

void Circulo::setVisible(bool v) { visible = v; }
bool Circulo::getVisible() { return visible; }
Rectangle Circulo::getRectagle()
{
	return Rectangle(x, y, radio * 2, radio * 2);
}