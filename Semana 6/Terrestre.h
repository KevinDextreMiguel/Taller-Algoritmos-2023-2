#pragma once
#include"MisLibrerias.h"

class Terrestre
{
public:
	Terrestre(int _ancho, int _alto, int _dx);
	~Terrestre();

	void borrar();
	void mover();
	virtual void dibujar() {}
	bool colision(int _x, int _y, int _ancho, int _alto);
	//get
	int get_x();
	int get_y();
	int get_alto();
	int get_ancho();

protected:
	int x, y;
	int dx;
	int ancho, alto;
	int color;
};

Terrestre::Terrestre(int _ancho, int _alto, int _dx)
{
	ancho = _ancho;
	alto = _alto;
	dx = _dx;
	x = rand() % (ANCHO_CONSOLA - ancho);
	y = rand() % (ALTO_CONSOLA - alto);
	color = rand() % 13 + 1;
}
Terrestre::~Terrestre() {}

void Terrestre::borrar()
{
	for (int i = 0; i < ancho; i++)
		for (int j = 0; j < alto; j++) 
		{
			Console::SetCursorPosition(x+i, y+j);
			cout << " ";
		}
}
void Terrestre::mover()
{
	if (x + dx<0 || x + dx + ancho>ANCHO_CONSOLA)dx *= -1;

	x += dx;
}
bool Terrestre::colision(int _x, int _y, int _ancho, int _alto)
{
	return x + ancho > _x && x < _x + _ancho && y<_y + _alto && y + alto>_y;
}

//get
int Terrestre::get_x() { return x; }
int Terrestre::get_y() { return y; }
int Terrestre::get_alto() { return alto; }
int Terrestre::get_ancho() { return ancho; }



