#pragma once
#include<iostream>
using namespace System::Drawing;

class Triangulo
{
public:
	Triangulo();
	~Triangulo();

	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	//set 
	void setVisible(bool v);
	//get
	bool getVisible();
	Rectangle getRectangle();
private:
	int x, y; 
	int ancho, alto;
	int dy;
	bool visible;
};

Triangulo::Triangulo()
{
	y = 0;
	x = rand() % 500;
	alto = rand() % 30 + 30;
	ancho = rand() % 30 + 30;
	dy = rand() % 5 + 10;
	visible = true;
}
Triangulo::~Triangulo(){}

void Triangulo::dibujar(Graphics^ g)
{
	Pen^ p = gcnew Pen(Color::Red, 5);
	g->DrawLine(p, x, y, x, y + alto);
	g->DrawLine(p, x, y+alto, x+ancho, y + alto);
	g->DrawLine(p, x+ancho, y+alto, x, y);
}
void Triangulo::mover(Graphics^ g)
{
	if (y + dy<0 || y + dy + alto>g->VisibleClipBounds.Height)dy *= -1;

	y += dy;
}
//set 
void Triangulo::setVisible(bool v) { visible = v; }
//get
bool Triangulo::getVisible() { return visible; }
Rectangle Triangulo::getRectangle()
{
	return Rectangle(x, y, ancho, alto);
}