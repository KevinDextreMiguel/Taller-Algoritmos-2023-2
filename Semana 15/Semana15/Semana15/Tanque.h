#pragma once
#include"Base.h"

class Tanque:public Base
{
private:
	char direccion;
	int puntos;
	int vida;
public:
	Tanque(int _ancho, int _alto):Base(_ancho,_alto)
	{
		direccion = ' ';
		x = y = 0;
		dx = dy = 5;
		vida = 2;
		puntos = 0;
	}

	~Tanque()
	{
	}
	
	void dibujar(Graphics^ g, Bitmap^ bmp)
	{
		Rectangle porcion(ancho * indx, alto * indy, ancho, alto);
		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g, Keys tecla)
	{
			switch (tecla)
			{
			case Keys::Right: case Keys::D:
				if (x + ancho < g->VisibleClipBounds.Width)
					x += dx;
				indy = 2;
				direccion = 'D';
				break;
			case Keys::Left: case Keys::A:
				if (x > 0)
					x -= dx;
				indy = 1;
				direccion = 'A';
				break;
			case Keys::Down: case Keys::S:
				if (y + alto < g->VisibleClipBounds.Height)
					y += dy;
				indy = 0;
				direccion = 'S';
				break;
			case Keys::Up: case Keys::W:
				if (y > 0)
					y -= dy;
				indy = 3;
				direccion = 'W';
			}
	}

	char Getdireccion() { return direccion; }
	int Getpuntos() { return puntos; }
	int Getvida() { return vida; }
	//set
	void Setpuntos(int val) { puntos+=val; }
	void Setvida(int val) {  vida+=val; }
};
