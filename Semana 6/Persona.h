#pragma once
#include"MisLibrerias.h"

class Persona
{
public:
	Persona();
	~Persona();
	void borrar();
	void mover();
	void dibujar();
	//set
	void set_dx_dy(int _dx, int _dy);
	void set_terminar(bool v);
	//get
	int get_x();
	int get_y();
	int get_alto();
	int get_ancho();
	bool get_terminar();
private:
	int x, y;
	int dx,dy;
	int ancho, alto;
	int color;
	bool terminar;
};

Persona::Persona()
{
	x = 60;
	y = 28;
	dx = 0; dy = 0;
	alto = ancho = 1;
	color = rand() % 13 + 1;
	terminar = true;
}

Persona::~Persona(){}
void Persona::borrar()
{
	Console::SetCursorPosition(x, y); cout << " ";
}
void Persona::mover()
{
	if (x + dx<0 || x + dx + ancho>ANCHO_CONSOLA)dx=0;
	if (y + dy<0 || y + dy + alto>ALTO_CONSOLA)dy=0;

	x += dx;
	y += dy;
}
void Persona::dibujar()
{
	Console::SetCursorPosition(x, y); cout << char(254);
}
//set
void Persona::set_dx_dy(int _dx, int _dy)
{
	dx = _dx;
	dy = _dy;
}
//get
int Persona::get_x() { return x; }
int Persona::get_y() { return y; }
int Persona::get_alto() { return alto; }
int Persona::get_ancho() { return ancho; }


void Persona::set_terminar(bool v) { terminar = v; }//terminar=false
bool Persona::get_terminar() { return terminar; }

