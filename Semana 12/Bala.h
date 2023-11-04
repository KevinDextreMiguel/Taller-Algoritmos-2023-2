#pragma once
using namespace System::Drawing;

class Bala
{
public:
	Bala(int xHeroe,int yHeroe,char dirHeroe);
	~Bala();
	void dibujar(Graphics^ g);
	void mover();
	bool getvisible();
	Rectangle getRectangulo();
	void setVisble(bool v);
	int getx();
	int gety();
private:
	int x, y;
	int dx, dy;
	int diametro;
	bool visible;
	char direccion;
};

Bala::Bala(int xHeroe, int yHeroe, char dirHeroe)
{
	x = xHeroe;
	y = yHeroe;
	direccion = dirHeroe;
	diametro = 20;
	dx = dy = 15;
	visible = true;
}

Bala::~Bala(){}

void Bala::dibujar(Graphics^ g)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Black);
	g->FillEllipse(b, x, y, diametro, diametro);
}
void Bala::mover()
{
	switch (direccion)
	{
	case 'W':
		y -= dy;break;
	case 'S':
		y += dy;break;
	case 'A':
		x -= dx; break;
	case 'D':
		x += dx; 
	}
}
bool Bala::getvisible() { return visible; }
Rectangle Bala::getRectangulo() { return Rectangle(x, y, diametro, diametro); }
void Bala::setVisble(bool v) { visible = v; }
int Bala::getx() { return x; }
int Bala::gety() { return y; }