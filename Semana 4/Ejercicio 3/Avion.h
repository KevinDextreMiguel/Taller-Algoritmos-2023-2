#pragma once
#define ANCHO_CONSOLA 120
#define ALTO_CONSOLA 30
#include"Alas.h"
#include"Fuselaje.h"
#include"TrenAterrizaje.h"

class Avion
{
public:
	Avion();
	~Avion();
	void mostrar();
	void borrar();
	void mover();
	//set
	void set_y(int _y);
	//get
	int get_y();
private:
	int x, y;
	int dx, dy;
	int color;

	Alas* objAlas;
	Fuselaje* objFuselaje;
	TrenAterrizaje* objTrenAterrizaje;

	time_t tiempo;
};

Avion::Avion()
{
	color = rand() % 13 + 1;
	dx = dy = 1;
	y = 0;
	x =10+ rand() % (ANCHO_CONSOLA - 30);

	objAlas = new Alas(color);
	objFuselaje = new Fuselaje(color);
	objTrenAterrizaje = new TrenAterrizaje(color);

	tiempo = clock();
}

Avion::~Avion()
{
	delete objAlas;
	delete objFuselaje;
	delete objTrenAterrizaje;
}

void Avion::mostrar()
{
	objTrenAterrizaje->dibujar(x+4, y);
	objFuselaje->dibujar(x+2, y+1);
	objAlas->dibujar(x, y + 2);
}
void Avion::borrar()
{
	objFuselaje->borrar(x + 2, y + 1);
	objAlas->borrar(x, y + 2);
}
void Avion::mover()
{
	if ((clock() - tiempo) / CLOCKS_PER_SEC>=1)
	{
		dx *= -1;
		tiempo = clock();
	}

	y += dy;
	x += dx;
}
//set
void Avion::set_y(int _y) { y = _y; }
//get
int Avion::get_y() { return y; }