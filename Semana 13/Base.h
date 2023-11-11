#pragma once
#include<iostream>
#include<vector>
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace std;

class Base
{
public:
	Base(int w,int h);
	~Base();
	void mover(Graphics^ g);
	Rectangle getRectangle();
	int getX();
	int getY();
	void posicision_Inicial();
protected:
	int x, y;
	int dx, dy;
	int velocidad;
	int indx,indy;
	int ancho,alto;
	int posInicialX, posInicialY;
};

Base::Base(int w, int h)
{
	ancho = w;
	alto = h;
	indx = indy = 0;
	dx = dy = 0;
	
	velocidad = 5;
}

Base::~Base(){}

void Base::mover(Graphics^ g)
{
	if (x + dx<0 || x + dx + ancho>g->VisibleClipBounds.Width)dx *= -1;
	if (y + dy<0 || y + dy + alto>g->VisibleClipBounds.Height)dy *= -1;
	
	x += dx * velocidad;
	y += dy * velocidad;
}
Rectangle Base::getRectangle() { return Rectangle(x, y, ancho, alto); }
int Base::getX() { return x; }
int Base::getY() { return y; }
void Base::posicision_Inicial()
{
	x=posInicialX ;
	y=posInicialY ;
}