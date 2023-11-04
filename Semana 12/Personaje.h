#pragma once
#include<iostream>
#include<vector>
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace std;

class Personaje
{
public:
	Personaje(int w,int h);
	~Personaje();
	int getx();
	int gety();
	int getancho();
	int getalto();
	bool getvisible();
	Rectangle getRectangulo();
	void setVisble(bool v);
protected:
	int x, y;
	int dx, dy;
	int indx, indy;
	int ancho, alto;
	bool visible;
};

Personaje::Personaje(int w, int h)
{
	ancho = w;
	alto = h;
	dx = dy = 10;
	indx = indy = 0;
	visible=true;
}

Personaje::~Personaje(){}
int Personaje::getx() { return x; }
int Personaje::gety() { return y; }
int Personaje::getancho() { return ancho; }
int Personaje::getalto() { return alto; }
bool Personaje::getvisible() { return visible; }
Rectangle Personaje::getRectangulo() { return Rectangle(x,y,ancho,alto); }
void Personaje::setVisble(bool v) { visible = v; }
